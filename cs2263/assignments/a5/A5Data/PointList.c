#include "Point2D.h"
#include "PointList.h"
#include <stdlib.h>
#include <stdio.h>

PointList* mallocPointList(int iNElements)
{
	PointList* pList = (PointList*)malloc(sizeof(PointList));
	pList->pointList = (Point2D*)malloc(iNElements * sizeof(Point2D));
	pList->length = iNElements;

	for (int i=0; i < pList->length; i++) {
		pList->pointList[i] = *mallocPoint2D();
	}

	return pList;
}

void freePointList(PointList* pList)
{	
	for (int i=0; i < pList->length; i++) {
     free(&(pList->pointList[i]));
	}

	free(pList);
}

int setElementPointList(PointList* pList, Point2D point, int index)
{
	// How do we tell if the element previously held a String?
  //if (pList->pointList[index] != (Point2D)NULL) {
  //  free(pList->pointList[index]);
 // }
  Point2D* p = createPoint2D(point.x, point.y);
  pList->pointList[index] = *p;
  return index;
}

Point2D* getElementPointList(PointList* pList, int index)
{
	return &pList->pointList[index];
}
