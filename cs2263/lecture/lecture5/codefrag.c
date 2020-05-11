#include<stdio.h>
#include<stdlib.h>

int main(void)
{
int i = 2;
int* pi;
pi = &i;
printf("%p: %i\n", &i, i);
printf("%p: %i\n", pi, *pi);

*pi = 4;
printf("%p: %i\n", &i, i);
printf("%p: %i\n", pi, *pi);

return EXIT_SUCCESS;
}
