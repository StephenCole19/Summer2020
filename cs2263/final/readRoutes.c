#include "PointList.h"
#include "Point2D.h"
#include "BusRoute.h"
#include "LinkedList.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_STRING_LENGTH 255
#define MAX_STOPS 50

#define ADDROUTE 1
#define REMOVEROUTE 0
#define ADDSTOP 2
#define REMOVESTOP 3
#define SAVE 4
#define LIST 5


int main(int argc, char** argv)
{
	if(argc != 2)
	{
		printf("Usage: %s <busroutes>\n", argv[0]);
		return 0;
	}

	FILE* fp;
	int numRoutes = 0;

	fp = fopen(argv[1], "r");
	fscanf(fp, "%d", &numRoutes);
	
	//Read in from file and fill up linked list
	Node* head = mallocHead();
	for(int i=0; i<numRoutes; i++)
	{		
		int numStops = 0;
		fscanf(fp,"%d", &numStops);
		BusRoute* route = mallocBusRoute(MAX_STOPS);
		
		for(int j=0; j<numStops; j++)
		{
			double x;
			double y;
			fscanf(fp,"%lf %lf", &x, &y);
			Point2D* point = createPoint2D(x,y);
			addPoint(route, *point);
		}
		
		char* line = (char*)malloc(MAX_STRING_LENGTH);
		fgets(line, MAX_STRING_LENGTH, fp);
		line++;
		route->routeName = line;
		
		if(head->route == NULL)
			head->route = route;
		else
			push(head, route);
	}

	fclose(fp);
	
	printf("All bus routes and stops will be refered to by the index printed to their left\n");
	
	int iChoice;
	int iNRead;

	/* Processing loop */
	printf("Choice (1=Add Route, 0=Remove Route, 2=Add Stop, 3=Remove Stop, 4=Save, 5=List): ");
	iNRead = scanf("%d", &iChoice);
	while(iNRead == 1)
	{
		switch(iChoice)
		{
			case ADDROUTE:
			{
				// There are a million different ways to read in a line but it just wouldn't work soooooo 
				char* name1 = (char*)malloc(sizeof(char)*MAX_STRING_LENGTH);
				char* name2 = (char*)malloc(sizeof(char)*MAX_STRING_LENGTH);
				printf("What is name of the route? (Two words): ");

				scanf("%s %s", name1, name2);
				strcat(name1, " ");
				strcat(name1, name2);
				strcat(name1, "\n");

				BusRoute* route = mallocBusRoute(MAX_STOPS);
				
				int iChoice2;
				int iNRead2;
				printf("Choice (1=Add Point, 0=End loop): ");
				iNRead2 = scanf("%d", &iChoice2);
				while(iChoice2 == 1)
				{
					double x;
					double y;
					printf("Enter a bus stop in the format x y: ");
					scanf("%lf %lf", &x, &y);

					Point2D* point = createPoint2D(x,y);
					addPoint(route, *point);
					printf("Choice (1=Add Point, 0=End loop): ");
					iNRead2 = scanf("%d", &iChoice2);
				}
				route->routeName = name1;
				push(head, route);
				break;
			}
			case REMOVEROUTE:
			{
				printLinkedList(head);
				int nodeNum;
				printf("What is the id of the bus route would you like to remove?: ");
				scanf("%d", &nodeNum);
				removeNode(head, nodeNum);
				break;
			}
			case ADDSTOP:
			{
				printLinkedList(head);
				printf("What is the id of the bus route would you like to add a stop to?: ");
				int picked;
				scanf("%d", &picked);
				Node* pickedNode = head;
				for(int i=0; i<picked; i++)
					pickedNode = pickedNode->next;
				
				double x;
				double y;
				printf("Enter a bus stop in the format x y: ");
				scanf("%lf %lf", &x, &y);

				Point2D* point = createPoint2D(x,y);
				addPoint(pickedNode->route, *point);
				break;
			}
			case REMOVESTOP:
			{
				printLinkedList(head);
				printf("What is the id of the bus route would you like to remove a stop from?: ");
				int pickedRoute;
				scanf("%d", &pickedRoute);
				
				printf("What is the id of the stop would you like to remove?: ");
				int pickedStop;
				scanf("%d", &pickedStop);

				Node* pickedNode = head;
				for(int i=0; i<pickedRoute; i++)
					pickedNode = pickedNode->next;

				removePoint(pickedNode->route, pickedStop);	
				break;
			}
			case SAVE:
			{
				char* output = "routes1.txt";
				FILE* outFile;
				outFile = fopen(output, "w+");
				fprintLinkedList(head, outFile);
				fclose(outFile);
				break;
			}
			case LIST:
			{
				printLinkedList(head);
				break;
			}
			default:
				return 0;
		}
		printf("Choice (1=Add Route, 0=Remove Route, 2=Add Stop, 3=Remove Stop, 4=Save, 5=List): ");
		iNRead = scanf("%d", &iChoice);
	}

	freeLinkedList(head);	
	return 0;
}

