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
  	printf("Type the function name and the following arguments.\n\n\n");

  	
  	printf("isdigit: ");
  	printf("\"testchar isdigit (char)\"\n\n");

  	printf("isalpha: ");
  	printf("\"testchar isalpha (char)\"\n\n");

    printf("isupper: ");
    printf("\"testchar isupper (char)\"\n\n");

    printf("islower: ");
    printf("\"testchar islower (char)\"\n\n");

    printf("toupper: ");
    printf("\"testchar toupper (char)\"\n\n");

    printf("tolower: ");
    printf("\"testchar tolower (char)\"\n\n");

    printf("ispunct: ");
    printf("\"testchar ispunct (char)\"\n\n");

    printf("isspace: ");
    printf("\"testchar isspace (char)\"\n\n");

    printf("findindexes: ");
    printf("\"testchar findindexes (string) (char)\"\n\n");

    printf("charcount: ");
    printf("\"testchar charcount (string) (char)\"\n\n");  

    printf("strcount: ");
    printf("\"testchar strcount (string) (substring)\"\n\n");  
    
    printf("strpbrk: ");
    printf("\"testchar strpbrk (string) (substring)\"\n\n"); 
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
  else if (!strcmp(argv[1], "ispunct")) {
    c = argv[2][0];
  	printf("func : ispunct / char : %c : %d\n", c, ispunct(c));
  }
  else if (!strcmp(argv[1], "isspace")) {
    c = argv[2][0];
  	printf("func : isspace / char : %c : %d\n", c, isspace(c));
  }
  else if (!strcmp(argv[1], "findindexes")) {
    char* str = argv[2];
    char c = argv[3][0];
    int count;
    int indexes[strlen(str)];
    findindexes(str, c, indexes, &count);
  	printf("func: findindexes / string : \"%s\" / char '%c' / indexes : ", str, c);
    for (int i = 0; i < count; i++) {
  	  printf("%d ", indexes[i]);
    }
  }
  else if (!strcmp(argv[1], "charcount")) {
    char* str = argv[2];
    char c = argv[3][0];
  	printf("func: charcount / string : \"%s\" / char '%c' / count : %d", str, c, charcount(str, c));
  }
  else if (!strcmp(argv[1], "strpbrk")) {
    char* str = argv[2];
    char* substr = argv[3];
    //char* ret = strpbrk(str, substr));
    if (!strcmp(*strpbrk(str, substr)), "\0")) {
      printf("func: strpbrk / string : \"%s\" / substring %s' / first matching char : %s", str, substr, "NOT FOUND");
    }
    else {
  	  printf("func: strpbrk / string : \"%s\" / substring %s' / first matching char : %c", str, substr, *strpbrk(str, substr));
    }
  }
  else if (!strcmp(argv[1], "strcount")) {
    char* str = argv[2];
    char* substr = argv[3];
  	printf("func: strcount / string : \"%s\" / substring %s' / count : %d", str, substr, strcount(str, substr));
  }
  else{
    printf("A valid function was not chosen.\nPlease use \"testchar usage\" for how to use.\n");
  	return 0;
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
