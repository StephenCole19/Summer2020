#include "Point2D.h"
#include "BusRoute.h"

#include <stdio.h>
#include <stdlib.h>

BusRoute* mallocBusRoute(int numStops)
{
	BusRoute* route = (BusRoute*)malloc(sizeof(BusRoute));
	route->pList = *mallocPointList(numStops);
	route->numStops = numStops;
	return route;
}

void addPoint(BusRoute* route, Point2D point, int n)
{
	setElementPointList(&route->pList, point, n);
}


Point2D* getPoint(BusRoute* route, int n)
{
	Point2D* p = getElementPointList(&route->pList, n);
	return p;
}
