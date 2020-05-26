#include <stdio.h>
#include <stdlib.h>
#include "Strings.h"

#define MAX_STRING_LENGTH 100

int main(int argc, char* argv[]){

	char* string1;
	char* string2;
	FILE* fp = fopen(argv[1], "w"); 
	string1 = mallocString(MAX_STRING_LENGTH);
	string2 = mallocString(MAX_STRING_LENGTH);
	int length1;
	int length2;
	
	if( fgets(string1, 100, stdin) != NULL )
	{
        	length1 = fputString(fp, string1);
	}	

	if( fgets(string2, 100, stdin) != NULL )
        {
                length2 = fputString(fp, string2);
        }
		
	printf("length1: %d, length2: %d\n", length1, length2);


	free(string2);
	free(string1);	
	fclose(fp);

	char* str1;
	char* str2;
	FILE* fpr = fopen(argv[1], "r");

	str1 = fgetString(fpr);
	str2 = fgetString(fpr);
	printf("String1: %sString2: %s", str1, str2);
	
	return EXIT_SUCCESS;
}


