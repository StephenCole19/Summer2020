#ifndef POINT_2D_H
#define POINT_2D_H
typedef struct Point2D {
	double x;
	double y;
} Point2D;

Point2D* mallocPoint2D();
void freePoint2D(Point2D* pThis);
Point2D* createPoint2D(double x, double y);
void setPoint2D(Point2D* pPt, double x, double y);
Point2D* copyPoint2D(Point2D* pThis);
double getXPoint2D(Point2D* pThis);
double getYPoint2D(Point2D* pThis);
void setPoint(Point2D* point, const double x, const double y);
void print(const Point2D* point);
double getDistancePoint2D(const Point2D* point1, const Point2D* point2);


#endif
