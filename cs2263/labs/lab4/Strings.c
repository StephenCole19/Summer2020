#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Strings.h"

char* mallocString(int stringsize){
    char *strMem = (char *)malloc(sizeof(char) * stringsize);

    if (strMem == (char *)NULL)
    {
        fprintf(stderr, "Memory allocation failed. Program terminating.");
        return (char*)NULL;
    }

    return strMem;
}

void freeString(char *s){
    free(s);
}

// create a duplicate string of s
// return it
// return (char*)NULL on failure
// should call mallocString(), and then strcpy()
char *duplicateString(char *s){
    int stringSize = 0;

    while (s[stringSize] != '\0')
        stringSize++;

    char *dupeString = mallocString(stringSize);
    strcpy(dupeString, s);
    if(dupeString == (char *)NULL)
    {
        fprintf(stderr, "Memory allocation failed. Program terminating.");
        return (char *)NULL;
    }

    return dupeString;
}