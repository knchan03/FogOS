#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void
tokenizer(void)
{
  char *str = "Hope was a letter I never could send";
  char *line = malloc(strlen(str));
  char *cpy = line;
  char *c = line;
  
  strcpy(line, str);
  //memory leak and corruption/invalid free, writing past endpoint in memory
  while (*c != '\0') {

    for ( ; *c != ' ' && *c != '\0'; c++) {
      // find the next space (or end of string)
    }

    *c = '\0';
    printf("%s\n", line);

    line = c + 1;
    c = line;
  }

  free(cpy);
}

int main(void)
{
	tokenizer();
}
