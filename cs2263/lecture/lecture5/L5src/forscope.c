// forscope.c
/*
 * - Should this compile? Why/why not?
 * - What will the output be?
 * - Explain the output.
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
  int i = 0;
  for(int i=0;i<5;i++){
    printf("%d\n",i);
  }
  printf("%d\n",i);
  return EXIT_SUCCESS;
}
