#include"isfib.c"
#include"isprime.c"
#include<stdio.h>

void findPrimeFibs(int min, int max)
{
	int count = min;
	while(count <= max)
	{
		if(isFib(count) == 1 && isPrime(count) == 1)
			printf("%d\n", count);
		count++;
	}
}

int main(void)
{
	int val1;
	int val2;

	printf("Enter the smallest number of your range: ");
	scanf("%d", &val1);
	
	printf("Enter the largest number of your range: ");
	scanf("%d", &val2);

	findPrimeFibs(val1,val2);

	return EXIT_SUCCESS;
}
