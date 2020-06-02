#include"Strings.h"
#include<stdio.h>
#include<stdlib.h>


int main(int argc, char** argv)
{	
	String dupe;	
	if(argc > 1)
	{
		dupe = duplicateString(argv[1]);
 		printf("Original: %s, Duplicate: %s\n", argv[1], dupe);
	}
	else
		printf("Please enter a String to be copied!\n");

	free(dupe);
}
