#include <stdio.h>
#include <stdlib.h>

#define LENGTH 5

void sortArray(int* arr, int (*comp)(int, int));
int comp(int a, int b);

int main(void)
{
	int arr[] = {3,4,5,1,2};
	
	printf("Array pre-sort: %d, %d, %d, %d, %d\n", arr[0], arr[1], arr[2], arr[3], arr[4]);
	sortArray(arr, comp);
	printf("Array post-sort: %d, %d, %d, %d, %d\n", arr[0], arr[1], arr[2], arr[3], arr[4]);

	return 1;
}

int comp(int a, int b)
{
	if(a > b)
		return 1;
	
	return 0;
}

void sortArray(int* arr, int (*comp)(int, int))
{
	int i,j,a;
	int n = LENGTH;
	for (i = 0; i < n; ++i) 
  {
    for (j = i + 1; j < n; ++j)
    {
			if (comp(arr[i], arr[j])) 
      {
        a =  arr[i];
        arr[i] = arr[j];
      	arr[j] = a;
      }
  	}
	}

}
