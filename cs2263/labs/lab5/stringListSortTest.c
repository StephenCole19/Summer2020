#include"Strings.h"
#include<stdio.h>
#include<stdlib.h>


int main(int argc, char** argv)
{	
	String* dupel;	
	if(argc > 1)
	{
		dupel = duplicateStringList(argv, argc);
		sortStringList(dupel, argc);
		for(int i=0; i<argc; i++)
			printf("%s\n", dupel[i]);
	}
	else
		printf("Please enter a String to be copied!\n");
	
	for(int i=0; i<argc; i++)
		free(dupel[i]);

	free(dupel);
}
