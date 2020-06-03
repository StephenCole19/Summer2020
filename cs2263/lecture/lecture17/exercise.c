#include<stdio.h>
#include<stdlib.h>

struct Point2D 
{
	double x;
	double y;
};

void print(const struct Point2D* point)
{
	printf("%f,%f)\n", point->x, point->y);
}

int main(void)
{
	struct Point2D point = {.x = 1.1, .y = 2.2};
	print(&point);
	return 0;
}
