#include<stdio.h>
#include<stdlib.h>

/* the value a the address in pi is
* set to zero.
*/
void zero(int* pi){
*pi = 0;
printf("%p: %i\n", pi, *pi);
}

int main(void){
int* pointer;
*pointer = 1;
zero(pointer);
printf("%p: %i\n", pointer, *pointer);
return EXIT_SUCCESS;
}
