// playStack.c
#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
#define PUSH 1
#define POP 0
#define LIST 2
#define PEEK 3
int main(int argc, char* argv[])
{
  int iChoice;
  int iNRead;
	pPtStack stack =  mallocPtStack();

  /* Processing loop */
  printf("Choice (1=add, 0=remove, 2=list, 3=peek): ");
  iNRead = scanf("%d", &iChoice);
  while(iNRead == 1)
  {
    switch(iChoice)
    {
      case PUSH:
        printf("Point value to add:"); // Obviously you need to read the x and y values
        // Read the element, add it to the stack
				double x;
				double y;
				scanf("%lf %lf", &x, &y);
				Point2D* pt = createPoint2D(x,y);
				push(stack, pt);
      break;
      case POP:
      // Pop the Point2D and print it out.
				if(stack->head != NULL)
				{
					printf("Point x=%lf, y=%lf\n", stack->head->payload->x, stack->head->payload->y);
					pop(stack);
				}
				else
					printf("Stack is empty!\n");
      break;
      case LIST:
        // Print out the stack elements
     		list(stack);
		 	break;
      case PEEK:
        // Print out the next value to be popped.
      	printf("Point x=%lf, y=%lf\n", stack->head->payload->x, stack->head->payload->y);
			break;
      default: 
        return 0;
    }
    printf("Choice (1=add, 0=remove, 2=list, 3=peek): ");
    iNRead = scanf("%d", &iChoice);
  }
  return EXIT_SUCCESS;
}
