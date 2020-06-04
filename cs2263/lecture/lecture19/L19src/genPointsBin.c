// C program to generate random numbers and write them to binary
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
    printf("%s: %s\n", argv[0], "<number of points>");
    return EXIT_FAILURE;
  }
  //no error checking
  int max = atoi(argv[1]);
	// Use current time as seed for random generator
	srand(time(0));

  struct timeval startTime;
  struct timeval endTime;
  float elapsedTime;
  gettimeofday(&startTime, NULL);

  Point* pPt = mallocPoint();
  for(int i = 0; i<max; i++){
    pPt->id = i;
    pPt->x = rand()/(float)10000;
    pPt->y = rand()/(float)10000;
    fwritePoint(stdout, pPt);
  }
  freePoint(pPt);

  gettimeofday(&endTime, NULL);
  elapsedTime = (endTime.tv_sec - startTime.tv_sec) + 1e-6 * (endTime.tv_usec - startTime.tv_usec);
  fprintf(stderr, "time for processing %d records= %f\n", max, elapsedTime);

	return 0;
}
