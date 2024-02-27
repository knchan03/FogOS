#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int 
main(void)
{
  char digit = '4';

  char lower = 's';

  char upper = 'Z';

  char punct = '\'';

  char space = ' ';

  char* string = "Hello, my name is Kevin and I am a student";

  char* substring = "stu";

  char target = 'l';

  int count;

  int indexes[strlen(string)];

  findindexes(string, target, indexes, &count);

  int countchar = charcount(string, target);

  char* finder = strpbrk(string, substring);
  
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
  
  printf("\nDONE\n");
  return 0;
}
