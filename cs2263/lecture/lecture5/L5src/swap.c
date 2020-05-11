#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[]) 
{
int i = 10;
int j = 99;
printf("i = %d; j = %d\n", i, j);
swap(i,j);
printf("i = %d; j = %d\n", i, j);
return EXIT_SUCCESS;
}

void swap(int i, int j) 
{
int iSwap;
iSwap = i;
i = j;
j = iSwap;
}
