#include"StringList.h"
#include"Strings.h"
#include<stdlib.h>
#include<stdio.h>


int main(int argc, char** argv)
{
		StringList* sl = mallocStringList(argc);
		printf("Original\n");
		for(int i=0; i < argc; i++)
		{
			printf("%s\n", argv[i]);
			setElementStringList(sl,argv[i],i);
		}
		
		StringList* slDup;

		slDup = duplicateStringList(sl);
		printf("Duplicate\n");
		for(int i=0; i < argc; i++)
       printf("%s\n", getElementStringList(sl,i));

	return 0;

}
