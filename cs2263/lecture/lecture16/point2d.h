#ifndef POINT_2D_H
#define POINT_2D_H
typedef struct Point2D {
	double x;
	double y;
} Point2D;


void setPoint(Point2D* point, const double x, const double y);
void print(const Point2D* point);
double distance(const Point2D* point1, const Point2D* point2);

#endif
