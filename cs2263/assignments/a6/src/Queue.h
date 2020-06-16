
#ifndef QUEUE_H
#define QUEUE_H
#include <stdlib.h>
#include "Point2D.h"

typedef struct pt2link {
 Point2D* payload;
 struct pt2link* next;
}PtLink, *pPtLink;


typedef struct pointqueue {
	pPtLink head;
	pPtLink tail;
	int length;
}PtQ, *pPtQ;

PtQ* mallocPtQ();

void enqueue(PtQ* queue, Point2D* pt);

void dequeue(PtQ* queue);

void listQueue(PtQ* queue);

pPtLink createPointLink(Point2D* pt);

#endif
