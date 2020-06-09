// C program to generate random numbers and write them to binary as ablob
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
    printf("%s: %s\n", argv[0], "<number of labels>");
    return EXIT_FAILURE;
  }
  int max = atoi(argv[1]);
	// Use current time as seed for random generator
	srand(time(0));

  struct timeval startTime;
  struct timeval endTime;
  float elapsedTime;
  gettimeofday(&startTime, NULL);

  Point* pPts = (Point*)malloc(sizeof(Point)*max) ;
  for(int i = 0; i<max; i++){
    pPts[i].id = i;
    pPts[i].x = rand()/(float)10000;
    pPts[i].y = rand()/(float)10000;
  }
  int nwritten = fwrite(pPts, sizeof(Point), max, stdout);
  free(pPts);

  gettimeofday(&endTime, NULL);
  elapsedTime = (endTime.tv_sec - startTime.tv_sec) + 1e-6 * (endTime.tv_usec - startTime.tv_usec);
  fprintf(stderr, "time for processing %d records= %f\n", max, elapsedTime);

	return 0;
}
