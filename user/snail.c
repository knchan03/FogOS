#include "kernel/types.h"
#include "user/user.h"
#include "kernel/fcntl.h"

#define MAX_HISTORY 100

struct history {
  int benchmark;
  char* cmd;
  int cmd_num;
};

struct history history_arr[MAX_HISTORY];
int history_count = 0;

uint
strspn(const char *str, const char *chars)
{
  uint i, j;
  for (i = 0; str[i] != '\0'; i++) {
    for (j = 0; chars[j] != str[i]; j++) {
      if (chars[j] == '\0')
        return i;
    }
  }
  return i;
}

uint
strcspn(const char *str, const char *chars)
{
  const char *p, *sp;
  char c, sc;
  for (p = str;;) {
    c = *p++;
    sp = chars;
    do {
      if ((sc = *sp++) == c) {
        return (p - 1 - str);
      }
    } while (sc != 0);
  }
}

char
*next_token(char **str_ptr, const char *delim)
{
  if (*str_ptr == NULL) {
    return NULL;
  }

  uint tok_start = strspn(*str_ptr, delim);
  uint tok_end = strcspn(*str_ptr + tok_start, delim);

  /* Zero length token. We must be finished. */
  if (tok_end  == 0) {
    *str_ptr = NULL;
    return NULL;
  }

  /* Take note of the start of the current token. We'll return it later. */
  char *current_ptr = *str_ptr + tok_start;

  /* Shift pointer forward (to the end of the current token) */
  *str_ptr += tok_start + tok_end;

  if (**str_ptr == '\0') {
    /* If the end of the current token is also the end of the string, we
         * must be at the last token. */
    *str_ptr = NULL;
  } else {
    /* Replace the matching delimiter with a NUL character to terminate the
         * token string. */
    **str_ptr = '\0';

    /* Shift forward one character over the newly-placed NUL so that
         * next_pointer now points at the first character of the next token. */
    (*str_ptr)++;
  }

  return current_ptr;
}

//initializes history array
void init_history() {
  for (int i = 0; i < MAX_HISTORY; i++) {
  	history_arr[i].cmd = NULL;
  	history_arr[i].benchmark = 0;
  }
}

//adds history entry to array
void add_history(char* cmd, int benchmark, int cmd_num) {
  char* cmd_copy = malloc(strlen(cmd) + 1);
  strcpy(cmd_copy, cmd);
  if (history_count < MAX_HISTORY) {
  	history_arr[history_count]. cmd = cmd_copy;
  	history_arr[history_count].benchmark = benchmark;
  	history_arr[history_count].cmd_num = cmd_num;
  	history_count++;
  }
  else {
    //frees oldest history entry and moves all other entries up
  	free(history_arr[0].cmd);
  	for (int i = 1; i < MAX_HISTORY; i++) {
  	  history_arr[i - 1] = history_arr[i];
  	}
  	//add history at end
  	history_arr[99]. cmd = cmd_copy;
  	history_arr[99].benchmark = benchmark;
  	history_arr[99].cmd_num = cmd_num;
  }
}

//prints history entries without benchmark
void print_history() {
  for (int i = 0; i < MAX_HISTORY; i++) {
    if (history_arr[i].cmd != NULL){
      printf("%d %s\n", history_arr[i].cmd_num, history_arr[i].cmd);
    }
  }
}

void print_history_benchmark() {
  for (int i = 0; i < MAX_HISTORY; i++) {
    if (history_arr[i].cmd != NULL){
      printf("[%d|%dms] %s\n", history_arr[i].cmd_num, history_arr[i].benchmark / 1000000, history_arr[i].cmd);
    }
  }
}


int 
main(int argc, char* argv[])
{
  int status = 0;
  char *line = 0;
  char* line_cpy = 0;
  uint sz = 0;
  int cmd_count = 0;
  init_history();
  int scripting = 0;
  int fd = 0;
  if (argc > 1 && argv[1] != NULL) {
    fd = open(argv[1], O_RDONLY);
    scripting = 1;
  }

  while (true) {
    char buf[128];
    getcwd(buf, 128);
    buf[strlen(buf) - 1] = '\0';
    int built_in = 0;
    
    if (scripting == 0) {
      printf("[%d] - [%d]--[%s] -@D ", status, cmd_count, buf);
    }
    
	if (getline(&line, &sz, fd) <= 0) {
      close(fd);
	  break;
    }
	char *args[128] = { 0 };
	int tokens = 0;
	char *next_tok = line;
	line_cpy = malloc(strlen(line));
	strcpy(line_cpy, line);
	char *curr_tok;
	while ((curr_tok = next_token(&next_tok, " \t\n\r")) != NULL) {
	  if (curr_tok[0] == '#') {
	    break;
	  }
	  args[tokens++] = curr_tok;
	}
	args[tokens] = NULL;

    if (args[0] != NULL) {
      cmd_count++;
    }
	//exit shell
	if (strcmp(args[0], "exit") == 0){
	  shutdown();
	}
	else if (strcmp(args[0], "history") == 0) {
	  built_in = 1;
	  if (strcmp(args[1], "-t") == 0) {
	    //print with benchmark
	    print_history_benchmark();
	  }
	  else {
	    //print without benchmark
	    print_history();
	  }
	}
	//cd
	else if (strcmp(args[0], "cd") == 0) {
	  built_in = 1;
	  if (args[1] == NULL || chdir(args[1]) != 0) {
	    fprintf(1, "Error: cd failed to change directory.\n");
	    status = 1;
	  }
	  else {
	    status = 0;
	  }
	}
    
    int start = clock();
    int pid = fork();
    if (pid == -1) {
      fprintf(2, "Error!\n");
      continue;
    }
    //child
    else if (pid == 0 && built_in == 0) { 
      //exec cmd
      if (args[0] != NULL) {
	    if (exec(args[0], args) == -1) {
		  fprintf(1, "Error: Exec Failed: %s\n", args[0]);
		  cmd_count--;
		  status = 1;
        }
      }
    }
    //parent
    else {
      wait(&status);
      int end = clock();
      int benchmark = end - start;
      line_cpy[strlen(line_cpy) - 1] = '\0';
      add_history(line_cpy, benchmark, cmd_count);
      free(line_cpy);
    }
  }
  free(line);
  return 0;
}
