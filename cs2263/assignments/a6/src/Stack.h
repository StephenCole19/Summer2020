
#ifndef STACK_H
#define STACK_H
#include <stdlib.h>
#include "Point2D.h"

typedef struct pt2link {
 Point2D* payload;
 struct pt2link* next;
}PtLink, *pPtLink;


typedef struct pointstack {
	pPtLink head;
	int length;
}PtStack, *pPtStack;

PtStack* mallocPtStack();

void push(PtStack* stack, Point2D* pt);

void pop(PtStack* stack);

void list(PtStack* stack);

pPtLink createPointLink(Point2D* pt);

#endif
