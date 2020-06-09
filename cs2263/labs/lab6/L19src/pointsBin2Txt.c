// C program to read binary values and write them as text
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
	// This program will read binary froma file and write text
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

  struct timeval startTime;
  struct timeval endTime;
  float elapsedTime;
  gettimeofday(&startTime, NULL);
  int nRead = 0;
  Point* pPt = mallocPoint();
	nRead = freadPoint(pFIn, pPt);
  while(nRead == 1){
		fprintfPoint(stdout, pPt);
    nRead = freadPoint(pFIn, pPt);
  }
  freePoint(pPt);
  gettimeofday(&endTime, NULL);
  elapsedTime = (endTime.tv_sec - startTime.tv_sec) + 1e-6 * (endTime.tv_usec - startTime.tv_usec);
  fprintf(stderr, "time for processing %d records= %f\n", nRead, elapsedTime);

	return 0;
}
