#include "LinkedList.h"
#include "BusRoute.h"

#include <stdio.h>
#include <stdlib.h>

/**
  creates the head node
  return a pointer to that node
*/
Node* mallocHead()
{
	Node* head = NULL;
	head = (Node*)malloc(sizeof(Node));
	if(head == NULL) 
		return (Node*)NULL;

	head->route = NULL;
	head->next = NULL;

	return head;
}

/**
  Adds a bus route to the end of the list
*/
void push(Node* head, BusRoute* route)
{
		Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    /* now we can add a new variable */
    current->next = (Node*)malloc(sizeof(Node));
    current->next->route = route;
    current->next->next = NULL;
}

/**
  Removes the first node of the list
*/
int pop(Node* head) 
{
  Node* next = NULL;

  if (head == NULL) {
    return -1;
  }

	next = head->next;
  head = next;

  return 0;
}

/**
  Removes the node at position n in the list
*/
int removeNode(Node* head, int n)
{
	int i = 0;
  Node* current = head;
  Node* temp = NULL;

  if (n == 0) {
		return pop(head);
  }

  for (i = 0; i < n-1; i++) {
  	if (current->next == NULL) {
    	return 1;
    }
    current = current->next;
  }

  temp = current->next;
  current->next = temp->next;
  free(temp);

  return 0;
}

/**
  Prints contents of the list ot the terminal
*/
void printLinkedList(Node* head)
{
	if(head == NULL)
		return;

	Node* current = head;
	int count = 0;
	do
	{
		printf("%d ", count);
		printBusRoute(current->route);
		current = current->next;
		count++;
	} while(current != NULL);
}

/**
  Saves the current state of the list to the file passed in
*/
void fprintLinkedList(Node* head, FILE* fp)
{
	Node* current = head;
	int count = 0;
	do
	{
		current = current->next;
		count++;
	} while(current != NULL);

	fprintf(fp, "%d\n", count);	
	current = head;
	do
	{
		fprintBusRoute(current->route, fp);
		current = current->next;
	} while(current != NULL);

}

void freeLinkedList(Node* head)
{
  Node* temp = head;
  while(head->next != NULL)
  {
    head = head->next;
    free(temp);
    temp = head;
  }
}
