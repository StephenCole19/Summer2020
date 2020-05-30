#include <stdio.h>
#include <stdlib.h>
#include "Strings.h"

#define MAX_STRING_LENGTH 100

int main(int argc, char* argv[])
{	
	char* str1;
	char* str2;
	FILE* fpr = fopen(argv[1], "r");

	str1 = getfString(fpr,"\n\r\t" );
	str2 = getfString(fpr,"\n\r\t");
	printf("String1: %s\nString2: %s\n", str1, str2);
	
	return EXIT_SUCCESS;
}


