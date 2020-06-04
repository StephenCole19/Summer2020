// C program to read text values and write them to binary
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <math.h>
#include "Point.h"

// Driver program
int main(int argc, char* argv[])
{
	// This program will create different sequence of
	// random numbers on every program run
  FILE* pFIn = stdin;
  FILE* pFOut;

  if(argc < 2)
  {
    printf("%s: %s\n", argv[0], "{<inputfile>} <outputfile>");
    return EXIT_FAILURE;
  }
  if(argc == 3)
  {
    pFIn = fopen(argv[1], "r");
    pFOut = fopen(argv[2], "wb");
    if(pFIn == (FILE*)NULL || pFOut == (FILE*)NULL){
      fprintf(stderr,"Failed to open files.\n");
      return EXIT_FAILURE;
    }
  }
  else if(argc == 2)
  {
    pFOut = fopen(argv[2], "wb");
    if(pFOut == (FILE*)NULL){
      fprintf(stderr,"Failed to open file.\n");
      return EXIT_FAILURE;
    }
  }
  struct timeval startTime;
  struct timeval endTime;
  float elapsedTime;

  int i = 0;
  int nWritten;
  Point* pPt = mallocPoint();
  int nRead = fscanfPoint(pFIn, pPt);
  while(nRead == 1){
    nWritten = fwritePoint(pFOut, pPt);
    if(nWritten == 0){
        fprintf(stderr,"%s\n","Failed to write to output file.\n");
        fclose(pFOut);
        if(argc==3) fclose(pFIn);
        return EXIT_FAILURE;
    }
    i++;
    freePoint(pPt);
    nRead = fscanfPoint(pFIn, pPt);
  }
  gettimeofday(&endTime, NULL);
  elapsedTime = (endTime.tv_sec - startTime.tv_sec) + 1e-6 * (endTime.tv_usec - startTime.tv_usec);
  fprintf(stderr, "time for processing %d records= %f\n", i, elapsedTime);

  fclose(pFOut);
  if(argc==3) fclose(pFIn);

	return 0;
}
