#include "String.h"
#include<stdlib.h>

// a cover function for malloc()
// malloc and return memory for a string of stringsize characters
// return (char*)NULL on failure
char* mallocString(int stringsize)
{
	return (char*) malloc(sizeof(char)*stringsize);
}

// just a cover function for free()
void freeString(char* s)
{
	free(s);
}

// create a duplicate string of s
// return it
// return (char*)NULL on failure
// should call mallocString(), and then strcpy()
char* duplicateString(char* s)
{
	char* duplicate = mallocString(sizeof(s));
	duplicate = strcpy(duplicate, s);

	return duplicate;
}

