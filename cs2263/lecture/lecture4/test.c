#include<stdio.h>
#include<stdlib.h>

int main(void)
{
int i=0;
int n = 4;
int sum;

for(i=0;i<n;i++){
				sum = sum+i;
}

printf("%d \n", &sum);

return EXIT_SUCCESS;
}
