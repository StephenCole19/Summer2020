#include <stdio.h>
#include <stdlib.h>


typedef struct node BTreeNode, *pBTreeNode;

struct node {
	char* payload;
	pBTreeNode left;
	pBTreeNode right;

};

void printPre(pBTreeNode head);
void freeBTreeNode(pBTreeNode head);

int main(void)
{	
	pBTreeNode head = (pBTreeNode)malloc(sizeof(BTreeNode));
	char w1 = 'w';
	head->payload = &w1;

	pBTreeNode l = (pBTreeNode)malloc(sizeof(BTreeNode));
	char o = 'o';
	l->payload = &o;

	pBTreeNode r = (pBTreeNode)malloc(sizeof(BTreeNode));
	char w2 = 'w';
	r->payload = &w2;

	head->left = l;
	head->right = r;

	printPre(head);
	freeBTreeNode(head);
	return 1;
}

void printPre(pBTreeNode head)
{
	printf("%c %c %c\n", *head->payload, *head->left->payload, *head->right->payload); 
	return;
}

void freeBTreeNode(pBTreeNode head)
{
	free(head->left);
	free(head->right);
	free(head);
	return;
}

