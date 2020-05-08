#include"isfib.c"
#include<stdlib.h>
#include<stdio.h>

int main(void)
{
	int iVal;
	int fibRes=0;
	printf("Enter an integer >= 0: ");
	scanf("%d", &iVal);

	fibRes = isFib(iVal);
	
	if(fibRes == 1)
		printf("Result: Fibonacci Number\n");
	else
		printf("Result: Not a Fibonacci Number\n");


	return EXIT_SUCCESS;
}
