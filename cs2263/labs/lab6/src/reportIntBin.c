#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <math.h>

//Driver
int main(int argc, char* argv[])
{

  if(argc != 2)
  {
    printf("%s %s %s\n", "Usage:", argv[0], "<input file>");
    return EXIT_FAILURE;
  }
  FILE* fp = fopen(argv[1], "r");
  if(fp == (FILE*) NULL){
    fprintf(stderr, "File open failed.\n");
    return EXIT_FAILURE;
  }

  int read = 0;
  int val = 0;
  read = fread(&val, sizeof(int), 1, fp);
  while(read == 1)
  {
    printf("%d ", val);
    read = fread(&val, sizeof(int), 1, fp);
  }
  printf("\n");
  fclose(fp);

  return 0;
}
