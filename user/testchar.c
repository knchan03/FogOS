#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int 
main(int argc, char* argv[])
{
  char c = ' ';
/*
  char* string = "Hello, my name is Kevin and I am a student yes yesyes yes";

  char* substring = "yes";

  char target = 'l';

  int count;

  int indexes[strlen(string)];
  findindexes(string, target, indexes, &count);


  int countchar = charcount(string, target);

  char* finder = strpbrk(string, substring);

  int substrcount = strcount(string, substring);
  */
  
  if (!strcmp(argv[1], "usage")) {
  	printf("How to Use Test Program: \n");
  	printf("Type the function name and the following arguments\n");
  	
  	printf("isdigit\n");
  	printf("testchar (char)\n");

  	printf("isalpha\n");
  	printf("isalpha (char)\n");

    printf("isupper\n");
    printf("isupper (char)\n");

    printf("islower\n");
    printf("islower (char)\n");

    printf("toupper\n");
    printf("toupper (char)\n");

    printf("tolower\n");
    printf("tolower (char)\n");

    printf("ispunct\n");
    printf("ispunct (char)\n");

    printf("isspace\n");
    printf("isspace (char)\n");

    printf("findindexes\n");
    printf("findindexes (char)\n");

    printf("charcount\n");
    printf("charcount (string) (char)\n");  

    printf("strcount\n");
    printf("strcount (string) (substring)\n");  
    
    printf("strpbrk\n");
    printf("strpbrk (string) (substring)\n"); 
  }

  if (!strcmp(argv[1], "isdigit")) {
    c = argv[2][0];
  	printf("func : isdigit / char : %c : %d\n", c, isdigit(c));
  }
  else if (!strcmp(argv[1], "isalpha")) {
    c = argv[2][0];
  	printf("func : isalpha / char : %c : %d\n", c, isalpha(c));
  }
  else if (!strcmp(argv[1], "isupper")) {
    c = argv[2][0];
  	printf("func : isupper / char : %c : %d\n", c, isupper(c));
  }
  else if (!strcmp(argv[1], "islower")) {
    c = argv[2][0];
  	printf("func : islower / char : %c : %d\n", c, islower(c));
  }
  else if (!strcmp(argv[1], "toupper")) {
    c = argv[2][0];
  	printf("func : toupper / char : %c : %d\n", c, toupper(c));
  }
  else if (!strcmp(argv[1], "tolower")) {
    c = argv[2][0];
  	printf("func : tolower / char : %c : %d\n", c, tolower(c));
  }




  
 
  /*
  printf("func : isdigit / char : %c : %d\n", digit, isdigit(digit));

  printf("func : isdigit / char : %c : %d\n", lower, isdigit(lower));
 
  printf("func : isalpha / char : %c : %d\n", digit, isalpha(digit));
  
  printf("func : isalpha / char : %c : %d\n", lower, isalpha(lower));
 
  printf("func : isupper / char : %c : %d\n", lower, isupper(lower));
  
  printf("func : isupper / char : %c : %d\n", upper, isupper(upper));
  
  printf("func : islower / char : %c : %d\n", lower, islower(lower)); 
  
  printf("func : islower / char : %c : %d\n", upper, islower(upper));

  printf("func : toupper / char : %c : %c\n", lower, toupper(lower));

  printf("func : toupper / char : %c : %c\n", digit, toupper(digit));

  printf("func : tolower / char : %c : %c\n", upper, tolower(upper));

  printf("func : tolower / char : %c : %c\n", digit, tolower(digit));

  printf("func : ispunct / char : %c : %d\n", punct, ispunct(punct));

  printf("func : ispunct / char : %c : %d\n", space, ispunct(space));

  printf("func : isspace / char : %c : %d\n", space, isspace(space));

  printf("func : isspace / char : %c : %d\n", punct, isspace(punct));

  printf("func: findindexes / string : \"%s\" / char '%c' / indexes : ", string, target);
  for (int i = 0; i < count; i++) {
  	printf("%d ", indexes[i]);
  }

  printf("\nfunc : charcount / char : '%c' / str : %s / count : %d\n", target, string, countchar);

  printf("\nfunc : strpbrk / str : '%s' / substr : %s / count : %c\n", string, substring, *finder);

  printf("\nfunc : strcount / str : '%s' / substr : %s / count : %d\n", string, substring, substrcount);
  */
  printf("\nDONE\n");
  return 0;
}
