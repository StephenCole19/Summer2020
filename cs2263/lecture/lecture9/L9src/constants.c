// first.c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * * argv)
{
  // the address varaibles (pointers) are declared on the stack
  // but the contants/literals exist in the instructions/executable
  // region in the process. Check out how small the address values are.
  char *name = "Eric";
  char *p;
  p = "abc";

  printf("variable: name; value: %s, address: %p\n", name, name);
  printf("variable: p; value: %s, address: %p\n", p, p);

  // generates a runtime error. Why?
  name[4]='!';
  printf("variable: name; value: %s, address: %p\n", name, name);

  return EXIT_SUCCESS;
}
