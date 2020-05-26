#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int numVals;
	int n;
	printf("Enter the number of values in your array: ");
        scanf("%d", &n);
	int a[n];

	numVals = scanfIntArray(a, n);
	
	printf("Number of values in array: %d\n", numVals);
	return 0;
}

int scanfIntArray(int a[], int n){
        int i;
        for(i=0;i<n;i++){
                int in;
                printf("Enter an integer: ");
                scanf("%d", &in);
                a[i] = in;
        }

	return n;
}
