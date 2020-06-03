#include<math.h>
#include<stdio.h>

#include"point2d.h"

void setPoint(Point2D* point, const double x, const double y) 
{
	point->x = x;
	point->y = y;
}

Point2D* mallocPoint2D()
{
	return (Point2D)malloc(sizeof(Point2D));
}

void freePoint2D(Point2D* pThis)
{
	free(pThis->x);
	free(pThis->y);
	free(pThis);
}

Point2D* copyPoint2D(Point2D* pThis)
{
	Point2D copy = mallocPoint2D();
	copy.x = pThis->x;
	copy.y = pThis->y;

	return &copy;
}

double getXPoint2D(Point2D* pThis)
{
	return pThis->x;
}

double getYPoint2D(Point2D* pThis)
{
	return pThis->y;
}

void print(const Point2D* point) 
{
	printf("(%f,%f)\n", point->x, point->y);
}
 
double getDistancePoint2D(const Point2D* point1, const Point2D* point2) 
{
 const double x2 = pow(point2->x - point1->x, 2);
 const double y2 = pow(point2->y - point1->y, 2);
 return sqrt(x2 + y2);
}

int main(void)
{
	Point2D point;
	setPoint(&point, 1.0, 1.0);
	print(&point);
	Point2D point2;
 	setPoint(&point2, 2.0, 2.0);
 	print(&point2);
 	printf("distance %f\n", distance(&point, &point2));
	return 0;
}
