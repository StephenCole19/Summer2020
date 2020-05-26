#include<stdio.h>

int main(void)
{
	int a[5] = {1,2,3,4,5};
	int n = 5;
	int max = 0;
	int min = 10;

	max_min(a, n, &max, &min);
	
	printf("Max value: %d, Min value: %d\n", max, min);
	return 0; 
}

void max_min(int a[], int n, int *max, int *min)
{	
	int i;
	for(i=0; i<n; i++)
	{
		printf("cur: %d, max: %d, min: %d\n", a[i], *max, *min);
		if(a[i] > *max){
			*max = a[i];
		}
		if(a[i] < *min){
			*min = a[i];
		}	
	}

}
