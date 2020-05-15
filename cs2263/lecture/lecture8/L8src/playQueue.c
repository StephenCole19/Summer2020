// first.c
#include <stdio.h>
#include <stdlib.h>
#define MAX 256
#define ADD 1
#define REMOVE 0
#define LIST 2
int main(int argc, char * * argv)
{
  int queue[MAX];
  int size = 0;
  int front = 0;
  int pos = 0;
  int val;
	int i;
  int iChoice;
  int iNRead;

  /* Processing loop */
  printf("Choice (1=add, 0=remove, 2=list): ");
  iNRead = scanf("%d", &iChoice);
  while(iNRead == 1)
  {
    switch(iChoice)
    {
      case ADD:
      if(size < MAX)
      {
        printf("Value to add: ");
        scanf("%d", &val);

        pos = (front+size)%MAX;
        queue[pos] = val;
        size++;
      }
        // Read the element, add it to the queue
      break;
      case REMOVE:
        if(size > 0)
        {
          printf("Value removed: %d\n", queue[front]); 
          val = queue[front];
          front = (front+1)%MAX;
          size--;
        }
      // Print out the last element and remove it.
      break;
      case LIST:
        for(i=0;i<size;i++)
        {
          printf("Queue position[%d]: %d\n", i, queue[i]);
        }
      // Print out the queue elements
      break;
    }
    printf("Choice (1=add, 0=remove, 2=list): ");
    iNRead = scanf("%d", &iChoice);
  }
  return EXIT_SUCCESS;
}
