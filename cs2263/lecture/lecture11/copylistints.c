#include"Integer.h"
#include<stdio.h>
#include<stdlib.h>

#define MAX_1D 3
#define MAX_2D 4

int main(void)
{
	int i;
	int *storage = (int*)malloc(MAX_1D*MAX_2D*sizeof(int));
	int **iArrs = (int**)malloc(MAX_1D*sizeof(int*));
	
	for(i=0; i<MAX_1D; i++)
		iArrs[i] = storage + 4*i;

	int j;
	for(i=0; i<MAX_1D; i++)
	{
		for(j=0; j<MAX_2D; j++)
			iArrs[i][j] = i+j;
	}
	
	int** dup = duplicateIntArrays(iArrs, MAX_1D, MAX_2D);
	free(iArrs);
	free(storage);	

	for(i=0; i<MAX_1D; i++)
	{
		for(j=0; j<MAX_2D; j++)
			printf("dup[%d][%d] = %d\n", i, j, dup[i][j]);
	}	
	
	free(dup);
	return EXIT_SUCCESS;
}
