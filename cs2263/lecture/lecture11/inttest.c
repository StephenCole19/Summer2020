#include <stdio.h>
#include <stdlib.h>
#include "Integer.h"
#define MAX_SIZE 4

int main(void){

	int* iArr = mallocIntArray(MAX_SIZE);
	int i;

	for(i=0;i<MAX_SIZE;i++)
	{
		iArr[i]=i;
		printf("iArr[%d] = %d\n", i, iArr[i]);
	}

	int* dupArr = duplicateInt(iArr);
	free(iArr);

	for(i=0;i<MAX_SIZE;i++)
	{
		printf("dupArr[%d] = %d\n", i, dupArr[i]);
	}

	free(dupArr);

	return EXIT_SUCCESS;
}
