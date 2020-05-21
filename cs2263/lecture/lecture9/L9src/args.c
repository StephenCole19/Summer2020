#include <stdio.h>
#include <stdlib.h>
int main(int argc, char* argv[])
{
  int i;
  printf("argc: %p\n", &argc);
  printf("argv: %p\n", argv);
  printf("i: %p\n", &i);
  for(i=0; i<argc; i++)
  {
    printf("argv: %p;\t%s\n", argv[i], argv[i]);
  }
  return EXIT_SUCCESS;
}
