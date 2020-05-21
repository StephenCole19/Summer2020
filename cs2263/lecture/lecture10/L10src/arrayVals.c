#include <stdio.h>
#include <stdlib.h>

#define MAXVALS 4
void arrayVals(int iN, int* arr, int val);

int main(void){

	int iErr;
	int iVal;
	int a[MAXVALS];
	char* prompt = "value: ";
	
	printf("%s",prompt);
	iErr = scanf("%d", &iVal);
	if(iErr != 1){
		fprintf(stderr, "Unable to read value\n");
		return EXIT_FAILURE;
	}

	arrayVals(MAXVALS, a, iVal);
	printf("-------------------------------------------\n");
	printf("main prompt (char*):\t%p\n", &prompt);
	printf("main a (int[MAXVALS]):\t%p\n", a);
	printf("main iVal (int):\t%p\n", &iVal);
	printf("main iErr (int):\t%p\n", &iErr);

	for(int i=0; i<MAXVALS; i++)
		printf("\t%d", a[i]);
	printf("\n");

	return EXIT_SUCCESS;
}

void arrayVals(int iN, int* arr, int val)
{
	printf("arrayVals arr (int*):\t%p\n",&arr);
	printf("arrayVals val (int):\t%p\n",&val);
	printf("arrayVals iN (int):\t%p\n",&iN);
	for(int i=0; i<iN; i++)
		arr[i]= val;
}

/*
value: 3
arrayVals arr (int*):	0x7ffc99b277d0
arrayVals val (int):	0x7ffc99b277d8
arrayVals iN (int):		0x7ffc99b277dc
-------------------------------------------
main prompt (char*):	0x7ffc99b27808
main a (int[MAXVALS]):	0x7ffc99b27810
main iVal (int):		0x7ffc99b27824
main iErr (int):		0x7ffc99b27828
	3	3	3	3
*/

