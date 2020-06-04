// Strings.h
#ifndef STRINGS_H
#define STRINGS_H

#include <stdio.h>

typedef char* String;

// a cover function for malloc()
// malloc and return memory for a string of stringsize characters
// return (char*)NULL on failure
String mallocString(int stringsize);

// just a cover function for free()
void freeString(String s);

// create a duplicate string of s
// return it
// return (char*)NULL on failure
// should call mallocString(), and then strcpy()
char* duplicateString(String s);

int fputString(FILE* pFOut, String s);

// Return an allocated string from an open file,
// Stop reading when any character is in terminators list
// return allocated string or (char*)NULL
String getfString(FILE* pFIn, String terminators);
String getString(String terminators);

#endif
