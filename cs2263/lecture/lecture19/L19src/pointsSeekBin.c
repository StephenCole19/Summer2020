// C program demonstrating random access on a binary file
// Based on https://www.geeksforgeeks.org/rand-and-srand-in-ccpp/
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
  if(argc != 2)
  {
    printf("%s: %s\n", argv[0], "<binary file>");
    return EXIT_FAILURE;
  }
  FILE* pFIn = fopen(argv[1], "rb");
  if(pFIn == (FILE*) NULL){
    fprintf(stderr, "File open failed.\n");
    return EXIT_FAILURE;
  }
	// Use current time as seed for random generator
	srand(time(0));

  struct timeval startTime;
  struct timeval endTime;
  float elapsedTime;
  gettimeofday(&startTime, NULL);
  int nRead = 0;
  Point* pPt = mallocPoint();
  int i;
  printf("Point number to report (-ve to quit):");
  scanf("%d", &i);
  while(i >= 0){
    fseek(pFIn, (long)i*sizeof(Point), SEEK_SET);
    nRead = freadPoint(pFIn, pPt);
    if(nRead == 0)
      return EXIT_FAILURE;
    fprintfPoint(stdout, pPt);
    printf("Point number to report (-ve to quit):");
    scanf("%d", &i);
  }
  freePoint(pPt);
  gettimeofday(&endTime, NULL);
  elapsedTime = (endTime.tv_sec - startTime.tv_sec) + 1e-6 * (endTime.tv_usec - startTime.tv_usec);
  fprintf(stderr, "time for processing %d records= %f\n", nRead, elapsedTime);

	return 0;
}
