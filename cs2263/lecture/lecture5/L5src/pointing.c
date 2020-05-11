// pointing.c
/*
 * Never dereference an unitialized pointer!
 *
 * Assigning a value to an unitialized pointer much worse!
 */
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char * * argv)
{
  int a = 5;
  int b = 17;
  int* pa;
  int* pb;
  // what happens if you leave these two statements out? Why?
  pa = &a;
  pb = &b;
  printf("main: a = %d, b = %d, argc = %d\n", *pa, *pb, argc);
  return EXIT_SUCCESS;
}
