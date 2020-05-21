#include"Integer.h"
#include<stdlib.h>
#include<stdio.h>

int* mallocIntArray(int intsize)
{
	return (int*) malloc(sizeof(int)*intsize);
}

int* duplicateInt(int* iArr)
{
	int* duplicate = mallocIntArray(sizeof(iArr));
	int iArrSize = sizeof(iArr)/2;
	int i;

	for(i=0; i<iArrSize; i++)
		duplicate[i] = iArr[i];

	return duplicate;
}

int** duplicateIntArrays(int** iArrs, int size1d, int size2d)
{
	int i;
	int *storage = (int*)malloc(size1d*size2d*sizeof(int));
	int **dup = (int**)malloc(size1d*sizeof(int*));
	
	for(i=0; i<size1d; i++)
		dup[i] = storage + 4*i;

	int j;
	for(i=0; i<size1d; i++)
	{
		for(j=0; j<size2d; j++)
			dup[i][j] = iArrs[i][j];
	}

	return dup;
}
