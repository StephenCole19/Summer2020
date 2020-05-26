#include<stdio.h>
#include<stdlib.h>

int main(void)
{	
	int a = 1;
	int* res = f1(a);
	return EXIT_SUCCESS;
}


int* f1(int a)
{
	int wow;
	wow = a;
	return &wow;
}


