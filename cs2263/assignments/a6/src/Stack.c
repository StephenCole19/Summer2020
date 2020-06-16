#include <stdio.h>
#include <stdlib.h>
#include "Point2D.h"
#include "Stack.h"

PtStack* mallocPtStack()
{
	PtStack* stack = (PtStack*)malloc(sizeof(PtStack));
	if(stack == (pPtStack)NULL )
		return stack;

	stack->head = (pPtLink)NULL;
	stack->length = 0;
	return stack;
}

void push(PtStack* stack, Point2D* pt)
{
	pPtLink newLink = createPointLink(pt);
	newLink->next = stack->head;
  stack->head = newLink;	
	stack->length = stack->length + 1;
}

void pop(PtStack* stack)
{
	pPtLink temp;
	if(stack->length == 0)
		return;

	temp = stack->head->next;
	freePoint2D(stack->head->payload);
  free(stack->head);
  stack->head = temp;
  stack->length--;
}

void list(PtStack* stack)
{
	pPtLink link = (PtLink*)malloc(sizeof(PtLink));
	link = stack->head;

	for(int i=0; i<stack->length; i++)
	{
		printf("%lf %lf\n", link->payload->x, link->payload->y);
		link = link->next;
	}
}

pPtLink createPointLink(Point2D* pt){
	pPtLink ptLink = (pPtLink)malloc(sizeof(PtLink));
	ptLink->payload = pt;
	ptLink->next = (pPtLink)NULL;
	
	return ptLink;
}

