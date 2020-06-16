#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <math.h>

#define MAX_INTS 100000000

// Driver program
int main(int argc, char* argv[])
{
  if(argc != 3)
  {
    printf("%s %s %s\n", "Usage:", argv[0], "<input file> <output file>");
    return EXIT_FAILURE;
  }

	FILE* input = fopen(argv[1], "r");
	FILE* output = fopen(argv[2], "w");

	if(input == NULL || output == NULL)
	{
    fprintf(stderr, "File open failed.\n");
    return EXIT_FAILURE;
	}

  struct timeval startTime;
  struct timeval endTime;
  float elapsedTime;
  gettimeofday(&startTime, NULL);
	int* fileVals = (int*)malloc(sizeof(int) * MAX_INTS);

	int read = 0;
	int count = 0;
	
	do
	{
    read = fread(&fileVals[count++], sizeof(int), 1, input);
  }
	while(read == 1);

	fileVals[--count] = 0;

	sortInts(fileVals, count);
	
	for(int i=0; i<count; ++i)
	{
		fwrite(&fileVals[i], sizeof(int), 1, output);
	}
	fclose(input);
	fclose(output);
	free(fileVals);

  gettimeofday(&endTime, NULL);
  elapsedTime = (endTime.tv_sec - startTime.tv_sec) + 1e-6 * (endTime.tv_usec - startTime.tv_usec);
  fprintf(stderr, "time for processing %d records= %f\n", count, elapsedTime);
}

void sortInts(int bin[], int n)
{
	for(int i = 0; i < n-1; ++i)
	{
		for(int j = i+1; j < n; ++j)
		{
			if(bin[j] < bin[i])
				sortHelper(&bin[i], &bin[j]);
		}
	}
}

void sortHelper(int* i1, int* i2)
{
	int temp = *i1;
	*i1 = *i2;
	*i2 = temp;
}
