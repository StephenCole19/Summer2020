#include "Point2D.h"
#include "BusRoute.h"

#include <stdio.h>
#include <stdlib.h>

/**
  Allocates a bus route based on the numeber of stops passed in
  returns a pointer to the bus route
*/
BusRoute* mallocBusRoute(int numStops)
{
	BusRoute* route = (BusRoute*)malloc(sizeof(BusRoute));
	route->pList = *mallocPointList(numStops);
	route->numStops = numStops;
	return route;
}

/**
  Changes a point at postion n in the PointList of route
*/
void editPoint(BusRoute* route, Point2D point, int n)
{
	setElementPointList(&route->pList, point, n);
}

/**
  Adds a point at the end of the provided bus route
*/
void addPoint(BusRoute* route, Point2D point)
{	
	addElementPointList(&route->pList, point);	
}

/**
  Removes the point at position index of the bus route
*/
void removePoint(BusRoute* route, int index)
{
	removeElementPointList(&route->pList, index);
}

/**
  Returns the point at postion n of the provided bus route
*/
Point2D* getPoint(BusRoute* route, int n)
{
	Point2D* p = getElementPointList(&route->pList, n);
	return p;
}

/**
  Prints the provided bus route to the terminal
*/
void printBusRoute(BusRoute* route)
{
	printf("Route Name: %s", route->routeName);
	printPointList(&route->pList);
}

/**
  Saves the current bus route to the provided file
*/
void fprintBusRoute(BusRoute* route, FILE* fp)
{
	fprintPointList(&route->pList, fp);
	fprintf(fp, "%s", route->routeName);
}

void freeBusRoute(BusRoute* route)
{
  freePointList(&route->pList);
  free(route);
}