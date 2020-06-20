// BusRoute.h
#ifndef BUSROUTE_H
#define BUSROUTE_H

#include <stdio.h>
#include "Point2D.h"
#include "PointList.h"

typedef struct busroute 
{
	char* routeName;
	PointList pList;
	int numStops;
} BusRoute;

/**
  Allocates a bus route based on the numeber of stops passed in
  returns a pointer to the bus route
*/
BusRoute* mallocBusRoute(int numStops);

/**
  Changes a point at postion n in the PointList of route
*/
void editPoint(BusRoute* route, Point2D point, int n);

/**
  Adds a point at the end of the provided bus route
*/
void addPoint(BusRoute* route, Point2D point);

/**
  Removes the point at position index of the bus route
*/
void removePoint(BusRoute* route, int index);

/**
  Returns the point at postion n of the provided bus route
*/
Point2D* getPoint(BusRoute* route, int n);

/**
  Prints the provided bus route to the terminal
*/
void printBusRoute(BusRoute* route);

/**
  Saves the current bus route to the provided file
*/
void fprintBusRoute(BusRoute* route, FILE* fp);

void freeBusRoute(BusRoute* route);

#endif
