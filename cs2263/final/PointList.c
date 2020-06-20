#include "Point2D.h"
#include "PointList.h"
#include <stdlib.h>
#include <stdio.h>

#define MAX_STOPS 50

/**
  Allocates a Point list of size iNElements
  return a pointer to the list
*/
PointList* mallocPointList(int iNElements)
{
	PointList* pList = (PointList*)malloc(sizeof(PointList));
	pList->pointList = (Point2D*)malloc(iNElements * sizeof(Point2D));
	pList->length = 0;

	for (int i=0; i < pList->length; i++) {
		pList->pointList[i] = *mallocPoint2D();
	}

	return pList;
}

/**
  Frees the point list
*/
void freePointList(PointList* pList)
{	
	for (int i=0; i < pList->length; i++) {
    free(&(pList->pointList[i]));
	}

	free(pList);
}

/**
  Changes an element in the list at the specified index
*/
int setElementPointList(PointList* pList, Point2D point, int index)
{
  Point2D* p = createPoint2D(point.x, point.y);
  pList->pointList[index] = *p;
  return index;
}

/**
  Adds a new element to the end of the list
*/
void addElementPointList(PointList* pList, Point2D point)
{
	Point2D* p = createPoint2D(point.x, point.y);
	pList->pointList[pList->length] = *p;
	pList->length++;
}

/**
  Removes the element at the specified index and shifts the rest of the list up
*/
void removeElementPointList(PointList* pList, int index)
{
	for(int i=index; i<pList->length-1; i++)
		pList->pointList[i] = pList->pointList[i+1];

	pList->length--;
}

/**
  Retreives the element in the list at the specified index
*/
Point2D* getElementPointList(PointList* pList, int index)
{
	return &pList->pointList[index];
}

/**
  Prints the given list to the terminal
*/
void printPointList(PointList* pList)
{
	printf("Stops (x,y):\n");
	for(int i=0; i<pList->length; i++)
		printf("%d (%lf,%lf)\n", i, pList->pointList[i].x, pList->pointList[i].y);	
	
	printf("\n");
}

/**
  Saves the current list to the specified file
*/
void fprintPointList(PointList* pList, FILE* fp)
{
	fprintf(fp, "%d ", pList->length);

	for(int i=0; i<pList->length; i++)
		fprintf(fp, "%lf %lf ", pList->pointList[i].x, pList->pointList[i].y);
}
