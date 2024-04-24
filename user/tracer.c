#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main (int argc, char* argv[]) 
{
  int child = fork();
  if (child == -1) {
    printf("fork failed!\n");
  } 
  else if (child == 0) {
    strace();
    exec(argv[1], &argv[1]);
  } 
  else {
    int status;
    wait(&status);
  }

  return 0;
}
