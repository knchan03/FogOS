/**
 * @file broken.c
 * @author mmalensek
 *
 * This program contains a series of buggy, broken, or strange C functions for
 * you to ponder. Your job is to analyze each function, fix whatever bugs the
 * functions might have, and then explain what went wrong. Sometimes the
 * compiler will give you a hint.
 *
 *  ____________
 * < Good luck! >
 *  ------------
 *      \   ^__^
 *       \  (oo)\_______
 *          (__)\       )\/\
 *              ||----w |
 *              ||     ||
 */

#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

static int func_counter = 1;
#define FUNC_START() printf("\n\n%d.) %s\n", func_counter++, __func__);


/**
 * This awesome code example was taken from the book 'Mastering C Pointers,'
 * one of the famously bad resources on learning C. It was trying to demonstrate
 * how to print 'BNGULAR'... with pointers...? Maybe?
 *
 * (1) Fix the problem.
 * (2) Explain what's wrong with this code:
 *      Hint: where are string literals stored in memory?
 *      Hint: what is '66' in this example? Can we do better?
 *      
 *     '66' is the capital character 'B', so we can just put 'B' instead of the ASCII.
 */
void
angular(void)
{
  FUNC_START();

  char a[] = { "ANGULAR" };
  a[0] = 'B';
  printf("%s\n", a);
}

/**
 * This function is the next step after 'Hello world' -- it takes user input and
 * prints it back out! (Wow).
 *
 * But, unfortunately, it doesn't work.
 *
 * (1) Fix the problem.
 * (2) Explain what's wrong with this code:
 *
 *     Memory is not allocated, because it sets a pointer for name, so when gets tries to write to address 0
       it segfaults
 */
void
greeter(void)
{
  FUNC_START();
  char name[128];

  printf("Please enter your name: ");
  gets(name, 128); //gets will try to write to address 0 and segfault / usertrap

  // Remove newline character
  char *p = name;
  for ( ; *p != '\n' && *p != 0; p++) { }
  *p = '\0';

  printf("Hello, %s!\n", name);
}

/**
 * This 'useful' function prints out an array of integers with their indexes, or
 * at least tries to. It even has a special feature where it adds '12' to the
 * array.
 *
 * (1) Fix the problem.
 * (2) Explain what's wrong with this code:
 *
 *     The displayer is going beyong the length of the stuff array, which is 100 not 1000.
 */
void
displayer(void)
{
  FUNC_START();
  //comment out pragma
  //#pragma GCC diagnostic push
  //#pragma GCC diagnostic ignored "-Waggressive-loop-optimizations"

  int stuff[100] = { 0 };

  /* Can you guess what the following does without running the program? */
  /* Rewrite it so it's easier to read. */
  stuff[15] = 12;

  for (int i = 0; i < 100; ++i) {
    printf("%d: %d\n", i, stuff[i]);
  }

  //#pragma GCC diagnostic pop
}

/**
 * Adds up the contents of an array and prints the total. Unfortunately the
 * total is wrong! See main() for the arguments that were passed in.
 *
 * (1) Fix the problem.
 * (2) Explain what's wrong with this code:
 *
 *     There is no size of the array, so we should calculate the size and pass it into the adder
       instead of just having a pointer to its first element.
 */
void
adder(int *arr, int size)
//array decay
{
  FUNC_START();

  int total = 0;

  for (int i = 0; i < size; ++i) {
    total += arr[i];
  }

  printf("Total is: %d\n", total);
}

/**
 * This function is supposed to be somewhat like strcat, but it doesn't work.
 *
 * (1) Fix the problem.
 * (2) Explain what's wrong with this code:
 *
 *     There is no memory allocation because there is a dangling pointer, and buf is a set size of 128,
 *     which is bad because if a strlen of both strings combined is more than 128 characters, then it work.
 */
char *
suffixer(char *a, char *b)
{
  FUNC_START();
  //#pragma GCC diagnostic push
  //#pragma GCC diagnostic ignored "-Wdangling-pointer"
  char *buf = malloc(strlen(a) + strlen(b) + 1);
  char *buf_start = buf;
  strcpy(buf, a);
  strcpy(buf + strlen(a), b);
  return buf_start;

  //#pragma GCC diagnostic pop
}

/**
 * This is an excerpt of Elon Musk's Full Self Driving code. Unfortunately, it
 * keeps telling people to take the wrong turn. Figure out how to fix it, and
 * explain what's going on so Elon can get back to work on leaving Earth for
 * good.
 *
 * (1) Fix the problem.
 * (2) Explain what's wrong with this code:
 *
 *     The character buffer for street 4 isn't long enough to copy the new name, so it needs to get bigger.
 *     Memcpy also doesn't include a '\0' character, so strcpy makes more sense.
 */
void
driver(void)
{
  FUNC_START();
  //memory corruption
  char street1[8] = { "fulton" };
  char street2[8] = { "gomery" };
  char street3[9] = { "piedmont" };
  char street4[12] = { "baker" };
  char street5[8] = { "haight" };

  if (strcmp(street1, street2)) {
    char *new_name = "saint agnew ";
    strcpy(street4, new_name);
    //use str cpy as memcpy doesnt recognize a '\0'
  }

  printf("Welcome to TeslaOS 0.1!\n");
  printf("Calculating route...\n");
  printf("Turn left at the intersection of %s and %s.\n", street5, street3);
}

/**
 * This function tokenizes a string by space, sort of like a basic strtok or
 * strsep. It has two subtle memory bugs for you to find.
 *
 * (1) Fix the problem.
 * (2) Explain what's wrong with this code:
 *
 *     The malloced line doesn't include the '\0' character in strings, so we need 1 more byte
 *     The free is also invalid because the pointer to line is not the original pointer because it keeps updating,
 *     so we have to increment the pointer without changing the original line pointer.
 */
void
tokenizer(void)
{
  FUNC_START();
  char *str = "Hope was a letter I never could send";
  char *line = malloc(strlen(str) + 1);
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

/**
* This function should print one thing you like about C, and one thing you
* dislike about it. Assuming you don't mess up, there will be no bugs to find
* here!
*/
void
finisher(void)
{
  FUNC_START();

  printf("One thing that I like about c is it has simple function implementation, so\n parameters and how they are passed are similar to other languages\n");
  printf("One thing that I dislike about c is pointers because keeping track of \nreferencing and derefrencing can be annoying, especially because there is technically no string type\n");
}

int
main(void)
{
  printf("Starting up!");

  angular();

  greeter();

  displayer();

  int nums[] = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512 };
  adder(nums, sizeof(nums) / sizeof(nums[0]));

  char *result = suffixer("kayak", "ing");
  printf("Suffixed: %s\n", result);

  driver();

  tokenizer();

  finisher();

  return 0;
}
