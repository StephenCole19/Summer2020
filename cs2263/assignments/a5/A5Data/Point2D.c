/*
 *	Point2D.c file -- source file for two dimensional point data
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Point2D.h"

/*
 * mallocPoint2D: allocates memory for a Point2D
 * 
 * returns: pointer to allocated memory; NULL on fail
 */
Point2D* mallocPoint2D(){
	Point2D* pPtThis = (Point2D*) malloc(sizeof(Point2D) );
	return pPtThis;
}

/*
 * freePoint2D: deallocates memory for a Point2D
 * 
 * Parameters: Point2D* pPtThis - pointer to free
 * 
 * returns: nothing
 */
void freePoint2D(Point2D* pPtThis){
	free(pPtThis);
}

Point2D* createPoint2D(double x, double y){
	Point2D* pPtThis = mallocPoint2D();
	if(pPtThis != (Point2D*)NULL ){
		setPoint2D(pPtThis,x,y);
	}
	return pPtThis;
}

void setPoint2D(Point2D* pPtThis, double x, double y){
	pPtThis->x = x;
	pPtThis->y = y;
}

void setXPoint2D(Point2D* pPtThis, double x){
	pPtThis->x = x;
}

double getYPoint2D(Point2D* pPtThis){
	return pPtThis->y;
}

Point2D* fscanfPoint2D(FILE* pFIn){
	Point2D* pPtThis;
	double x;
	double y;
	int iNRead;
	iNRead = fscanf(pFIn, "%lf %lf", &x, &y);
	if(iNRead !=2 ) return (Point2D*)NULL;
	pPtThis = createPoint2D(x, y);
	return pPtThis;
}

double getDistancePoint2D( Point2D* pPtThis, Point2D* pPtThat){
	double dX;
	double dY;
	double distance;
	dX = pPtThis->x - pPtThat->x;
	dY = pPtThis->y - pPtThat->y;
	distance = sqrt(dX*dX + dY*dY);
	return distance;
}
