#include <stdlib.h>
#include <stdio.h>

int compareInt(const void * arg1, const void * arg2);

// Note - this program *should* do error checking!!
int main(void){
    int a;
    int b;
    int* pa = &a;
    int* pb = &b;

    printf("Two integers please: ");
    scanf(" %d %d", pa, pb); 

    if(compareInt(pa, pb)) printf("Integers are in ascending order\n");
    else printf("Integers are equal or in descending order\n");

    return EXIT_SUCCESS;
}

int compareInt(const void * arg1, const void * arg2){
  // convert void * to an int *
  const int * ptr1 = (const int *) arg1; 
  const int * ptr2 = (const int *) arg2;  
  // get the value from the address
  const int val1 = * ptr1; 
  const int val2 = * ptr2;
  // compare the value
  if (val1 < val2) return -1; 
  if (val1 == val2) return 0; 
  return 1;
}
/*
 * [FCSSSDs-iMac-3:Lectures/L15 - Code Along/L15src] wightman% ./sortInts
 * 10 integers please: 5 34 -1 0 444 34 -34 5 34 -66
 * Sorted values: -66 -34 -1 0 5 5 34 34 34 444
 */
