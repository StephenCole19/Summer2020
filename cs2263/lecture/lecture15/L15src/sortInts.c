#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 10
int compareInt(const void * arg1, const void * arg2);

// Note - this program *should* do error checking!!
int main(void){
    int a[MAX_SIZE];

    printf("%d integers please: ", MAX_SIZE);
    for(int i=0; i< MAX_SIZE; i++){
      scanf("%d", &a[i]); 
    }

    qsort(a, MAX_SIZE, sizeof(int), compareInt);
    printf("Sorted values: ");
    for(int i=0; i< MAX_SIZE; i++){
      printf("%d ", a[i]); 
    }    
    printf("\n"); 

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
