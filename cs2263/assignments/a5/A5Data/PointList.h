#include "Point2D.h"
#include <stdlib.h>

#ifndef POINTLIST_H
#define POINTLIST_H

typedef struct pointlist{
	int length;
	Point2D* pointList;
} PointList;

PointList* mallocPointList(int iNElements);

void freePointList(PointList* pList);

int setElementPointList(PointList* pList, Point2D point, int index);

Point2D* getElementPointList(PointList* pList, int index);

#endif
