#include "Strings.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 4

int main(void)
{
	char* string = mallocString(MAX_LENGTH);
	
	if(string == (char*)NULL)
	{
		fprintf(stderr, "Memory allocation failed. terminating.");
		return EXIT_FAILURE;
	}	

	printf("Enter up to four characters: ");
	getchar();
	char c = getchar();
	int i=0;
	while(c != '\n' && i < MAX_LENGTH)
	{
		string[i] = c;
		i++;
		c = getchar();
	}

	string[i] = (char) NULL;
	printf("%s it is!\n", string);

	char* stringCopy = mallocString(MAX_LENGTH);
	stringCopy = duplicateString(string);
	freeString(string);

	printf("This is a dupe: %s", stringCopy);
	freeString(stringCopy);

}
