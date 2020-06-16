// playQueue.c
#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
#define ENQUEUE 1
#define DEQUEUE 0
#define LIST 2
#define PEEK 3
int main(int argc, char * * argv)
{
  int iChoice;
  int iNRead;
	pPtQ queue = 	mallocPtQ();

  /* Processing loop */
  printf("Choice (1=enqueue, 0=dequeue, 2=list, 3=peek): ");
  iNRead = scanf("%d", &iChoice);
  while(iNRead == 1)
  {
    switch(iChoice)
    {
      case ENQUEUE:
        printf("Point value to add:"); // Obviously you need to read the x and y values
        // Read the element, add it to the queue
				double x;
				double y;
				scanf("%lf %lf", &x, &y);
				Point2D* pt = createPoint2D(x,y); 
				enqueue(queue, pt);
      break;
      case DEQUEUE:
      // dequeue the Point2D and print it out.
				if(queue->head != NULL)
				{
					printf("Point x=%lf, y=%lf\n", queue->head->payload->x, queue->head->payload->y);
					dequeue(queue);		
				}
				else
					printf("Queue is empty!\n");

      break;
      case LIST:
        // Print out the stack elements, 
				listQueue(queue);
      break;
      case PEEK:
        // Print out the next value to be dequeue.
				 printf("Point x=%lf, y=%lf\n", queue->head->payload->x, queue->head->payload->y);
      break;
      default: 
        return 0;
    }
    printf("Choice (1=enqueue, 0=dequeue, 2=list, 3=peek): ");
    iNRead = scanf("%d", &iChoice);
  }
  return EXIT_SUCCESS;
}
