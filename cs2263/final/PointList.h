#include "Point2D.h"
#include <stdlib.h>

#ifndef POINTLIST_H
#define POINTLIST_H

typedef struct pointlist{
	int length;
	Point2D* pointList;
} PointList;

/**
  Allocates a Point list of size iNElements
  return a pointer to the list
*/
PointList* mallocPointList(int iNElements);

/**
  Frees the point list
*/
void freePointList(PointList* pList);

/**
  Changes an element in the list at the specified index
*/
int setElementPointList(PointList* pList, Point2D point, int index);

/**
  Adds a new element to the end of the list
*/
void addElementPointList(PointList* pList, Point2D point);

/**
  Removes the element at the specified index and shifts the rest of the list up
*/
void removeElementPointList(PointList* pList, int index);

/**
  Retreives the element in the list at the specified index
*/
Point2D* getElementPointList(PointList* pList, int index);

/**
  Prints the given list to the terminal
*/
void printPointList(PointList* pList);

/**
  Saves the current list to the specified file
*/
void fprintPointList(PointList* pList, FILE* fp);

#endif
