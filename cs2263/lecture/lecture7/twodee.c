#include<stdio.h>
#define LENGTH 5
#define WIDTH 3

int main(void)
{
	int iArr[LENGTH][WIDTH];
	int i;
	int j;
	for(i=0;i<LENGTH;i++){
		for(j=0;j<WIDTH;j++){
			iArr[i][j] = 0;
		}	
	}
	
	printf("iArr[4][2] = %d %lu\n", iArr[4][2], sizeof(iArr));

	return 0;
}
