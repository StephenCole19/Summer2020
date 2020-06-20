#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdlib.h>
#include "Point2D.h"
#include "BusRoute.h"

typedef struct node {
	BusRoute* route;
	struct node* next;
} Node;

/**
  creates the head node
  return a pointer to that node
*/
Node* mallocHead();

/**
  Adds a bus route to the end of the list
*/
void push(Node* head, BusRoute* route);

/**
  Removes the first node of the list
*/
int pop(Node* head);

/**
  Removes the node at position n in the list
*/
int removeNode(Node* head, int n); 

/**
  Prints contents of the list ot the terminal
*/
void printLinkedList(Node* head);

/**
  Saves the current state of the list to the file passed in
*/
void fprintLinkedList(Node* head, FILE* fp);

void freeLinkedList(Node* head);

#endif
