// ifscope.c
/*
 * Should this compile? Why/why not?
 * What will the output be if:
 *    (i) i=1, j=2
 *    (i) i=2, j=1
 */
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char** argv)
{
  int iErr;
  int i;
  int j;

  printf("Enter two integers: ");
  iErr = scanf("%d %d", &i, &j);
  if(iErr != 2)
  {
    fprintf(stderr,"Egads - something went wrong!\n");
    return EXIT_FAILURE;
  }
  if(i>j){
    int i = 0;
    printf("%d\n",i);
  }
  return EXIT_SUCCESS;
}
