#include "PointList.h"
#include "Point2D.h"
#include "BusRoute.h"
#include "Student.h"

#include <stdlib.h>
#include <stdio.h>

#define MAX_STRING_LENGTH 255

/**
 * You know what imo this code doesn't look as bad as normal
 * @StephenCole19
 */
int main(int argc, char** argv)
{
	FILE* fp;
	int numRoutes = 0;

	fp = fopen(argv[1], "r");
	fscanf(fp, "%d", &numRoutes);

	BusRoute** routes =  (BusRoute**)malloc(numRoutes * sizeof(BusRoute*));
	
	for(int i=0; i<numRoutes; i++)
	{		
		int numStops = 0;
		fscanf(fp,"%d", &numStops);
		BusRoute* route = mallocBusRoute(numStops);
		
		for(int j=0; j<numStops; j++)
		{
			double x;
			double y;
			fscanf(fp,"%lf %lf", &x, &y);
			Point2D* point = createPoint2D(x,y);
			addPoint(route, *point, j);
		}
		
		char *line = (char*)malloc(MAX_STRING_LENGTH);
		fgets(line, MAX_STRING_LENGTH, fp);
		line++;
		route->routeName = line;

		routes[i] = route;
	}
		
	double x = 0;
	double y = 0;
	

	while(fscanf(stdin, "%lf %lf", &x, &y) != 0)
	{
		char *name = (char*)malloc(MAX_STRING_LENGTH);
  	if(fgets(name, MAX_STRING_LENGTH, stdin) == NULL)
			break;
		name++;
		
		Point2D* p = createPoint2D(x,y);
		Student* stud = createStudent(name, *p);
		int routeIndex = 0;
		double shortestDistance = 1000000000000; // If it's longer than that he can fly to school;
		for(int i=0; i<numRoutes; i++)
		{
			int numStops = routes[i]->numStops;
			for(int j=0; j<numStops; j++)
			{
				Point2D* currentStop = getPoint(routes[i],j);
				double currentDistance = getDistancePoint2D(currentStop, &stud->location);

				if(currentDistance < shortestDistance)
				{
					routeIndex = i;
					shortestDistance = currentDistance;
				}
			}

		}

		printf("%s\tShould be assigned to %s", stud->name, routes[routeIndex]->routeName);
	}

	return 0;
}

