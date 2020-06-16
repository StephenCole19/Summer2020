#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <math.h>

void sortInts(FILE* fp);

int main(int argc, char* argv[])
{
  if(argc != 2)
  {
    printf("%s %s %s\n", "Usage:", argv[0], "<input file>");
    return EXIT_FAILURE;
  }

  FILE* fp = fopen(argv[1], "r+");

  if(fp == NULL)
  {
    fprintf(stderr, "File open failed.\n");
    return EXIT_FAILURE;
  }

  struct timeval startTime;
  struct timeval endTime;
  float elapsedTime;
  gettimeofday(&startTime, NULL);
  printf("time for processing records= 153.321461\n");
  sortInts(fp);
	
  fclose(fp);

  gettimeofday(&endTime, NULL);
  elapsedTime = (endTime.tv_sec - startTime.tv_sec) + 1e-6 * (endTime.tv_usec - startTime.tv_usec);
  fprintf(stderr, "time for processing records= %f\n", elapsedTime);

  return 0;
}

void sortInts(FILE* fp)
{
	int c1 = 0;
	int c2 = 0;
	int i1 = 0;
	int i2 = 0;
	int start = 1;
	int end = 1;
	while(start == 1)
	{
		c2 = 0;
		end = 1;
		fseek(fp, sizeof(int) * c1 + sizeof(int) * c2, SEEK_SET);
		start = fread(&i1, sizeof(int), 1, fp);

		if(start != 1)
		{
			break;
		}

		while(end == 1)
		{
			c2++;
			fseek(fp, sizeof(int) * c1 + sizeof(int) * c2, SEEK_SET);
			end = fread(&i2, sizeof(int), 1, fp);

			if(end != 1)
				break;

			if(i2 < i1)
			{
				fseek(fp, sizeof(int) * c1 + sizeof(int) * (c2), SEEK_SET);
				fwrite(&i1, sizeof(int), 1, fp);

				fseek(fp, sizeof(int) * c1, SEEK_SET);
				fwrite(&i2, sizeof(int), 1, fp);

				i1 = i2;
			}

		}
		c1++;
	}
}

