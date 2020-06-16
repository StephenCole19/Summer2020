#include <stdio.h>
#include <stdlib.h>
#include "Point2D.h"
#include "Queue.h"

PtQ* mallocPtQ()
{
	PtQ* queue = (PtQ*)malloc(sizeof(PtQ));
	if(queue == (pPtQ)NULL )
		return queue;

	queue->head = (pPtLink)NULL;
	queue->tail = (pPtLink)NULL;
	queue->length = 0;
	return queue;
}

void enqueue(PtQ* queue, Point2D* pt)
{
	pPtLink newLink = createPointLink(pt);
	
	//Empty
	if(queue->head == (pPtLink)NULL)
	{	
		queue->head = newLink;
		queue->tail = newLink;
	}
	else if(queue->head == queue->tail)
	{
		queue->tail = newLink;
		queue->head->next = newLink;
	}
	else
	{
		queue->tail->next = newLink;
		queue->tail = newLink;
	}
	
	queue->length = queue->length + 1;
}

void dequeue(PtQ* queue)
{
	if(queue->length == 0)
		return;
	else if(queue->head->next == (pPtLink)NULL)
	{
		queue->head = (pPtLink)NULL;
		queue->length = queue->length-1;
	}
	else
	{
		queue->head = queue->head->next;
		queue->length = queue->length-1;
	}
}

void listQueue(PtQ* queue)
{
	pPtLink link = (pPtLink)malloc(sizeof(PtLink));
	link = queue->head;

	for(int i=0; i<queue->length; i++)
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
