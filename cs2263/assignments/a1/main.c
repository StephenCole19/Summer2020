#include<stdlib.h>
#include<stdio.h>
#include "isprime.c"

int main(void)
{
	int iVal=0;
	int result=0;
	printf("Enter a positive integer: ");
	scanf("%d", &iVal);
	if(iVal < 1){
		printf("Invalid Input!\n");
		return 0;
	}

	result = isPrime(iVal);
	
	if(result == 1)
		printf("Result: Prime\n");
	else
		printf("Result: Non-prime\n"); 
	
	return EXIT_SUCCESS;
}
