
#ifndef STRINGS_H
#define STRINGS_H

// a cover function for malloc()
// malloc and return memory for a string of stringsize characters
// return (char*)NULL on failure
char* mallocString(int stringsize);

// just a cover function for free()
void freeString(char* s);

// create a duplicate string of s
// return it
// return (char*)NULL on failure
// should call mallocString(), and then strcpy()
char* duplicateString(char* s);

int fputString(FILE* pFOut, char* s);

char* fgetString(FILE* pFIn);

#endif
