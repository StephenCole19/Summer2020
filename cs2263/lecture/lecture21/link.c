#include<stdio.h>
#include<stdlib.h>

typedef struct link{
	char payload;
	struct link* next;
} Link;

int main(void)
{
	Link* head;
	
	Link* headLink = (Link*)malloc(sizeof(Link));
	headLink->payload = 'w';

	head = headLink;
	
	printf("%c\n", head->payload);
}


