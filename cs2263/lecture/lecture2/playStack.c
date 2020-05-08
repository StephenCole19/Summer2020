// first.c
#include <stdio.h>
#include <stdlib.h>
#define MAX 256
#define PUSH 1
#define POP 0
#define LIST 2
int main(int argc, char* argv[])
{
  int stack[MAX];
  int size = 0;
  int val;
  int iChoice;
  int iNRead;

  /* Processing loop */
  printf("Choice (1=add, 0=remove, 2=list): ");
  iNRead = scanf("%d", &iChoice);
  while(iNRead == 1)
  {
    switch(iChoice)
    {
      case PUSH:
        printf("Value to add: ");
				scanf("%d", &val);
				if(size < MAX) {
					stack[size] = val;
					size++;
				}
        // Read the element, add it to the stack
      break;
      case POP:
				if(size > 0){
					size--;
					val = stack[size];
					printf("Value popped: %d \n", val);
				}
      // Print out the last element and remove it.
      break;
      case LIST:
				for(int i=0; i<size; i++)
				{
					printf("Value at %d = %d \n", i, stack[i]);
				}
        // Print out the stack elements
      break;
    }
    printf("Choice (1=add, 0=remove, 2=list): ");
    iNRead = scanf("%d", &iChoice);
  }
  return EXIT_SUCCESS;
}
