#include<stdio.h>
#include<stdlib.h>

//return 1 if prime, else 0
int isPrime(int val)
{
	int ret=1;
	int i;

	for(i=2; i<=val/2; ++i)
	{
		if(val % i == 0){
			ret=0;
			break;
		}
	}

	if(ret == 0 || val == 1)
		return 0;
	else
		return 1;
}
