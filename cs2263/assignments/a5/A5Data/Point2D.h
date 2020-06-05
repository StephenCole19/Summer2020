/*
 *	Point2D.h file -- header file for two dimensional point data
 *
 * Original: Rick Wightman, June, 2020
 */


#ifndef POINT2D_H
#define POINT2D_H
#include <stdio.h>

typedef struct point2d
{
	double x;
	double y;

} Point2D;

/*
 * mallocPoint2D: allocates memory for a Point2D
 * 
 * returns: pointer to allocated memory; NULL on fail
 */
Point2D* mallocPoint2D();

/*
 * freePoint2D: deallocates memory for a Point2D
 * 
 * Parameters: Point2D* pPtThis - pointer to free
 * 
 * returns: nothing
 */
void freePoint2D(Point2D* pPtThis);

Point2D* createPoint2D(double x, double y);

void setPoint2D(Point2D* pPtThis, double x, double y);

void setXPoint2D(Point2D* pPtThis, double x);

double getYPoint2D(Point2D* pPtThis);

Point2D* fscanfPoint2D(FILE* pFin);

double getDistancePoint2D( Point2D* ptThis, Point2D* pPtThat);

#endif
