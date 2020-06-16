#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "Strings.h"

String getfc(FILE* pFIn, String terminators, int n);
int StringInString(String t, char c);

// a cover function for malloc()
// malloc and return memory for a string of stringsize Stringacters
// return (String*)NULL on failure
String mallocString(int stringsize){
    return (String)malloc(sizeof((stringsize+1)));
}

// just a cover function for free()
void freeString(String s){
    free(s);
}

// create a duplicate string of s
// return it
// return (String*)NULL on failure
// should call mallocString(), and then strcpy()
String duplicateString(String s){
    String sCopy = mallocString(strlen(s));
    if(sCopy != (String)NULL){
        strcpy(sCopy,s);
    }
    return sCopy;
}

String* duplicateStringList(String* s,int n){
	String* ret = (String*)malloc(sizeof(String) * n);
	for(int i=0; i<n; ++i)
	{
		size_t size = strlen(s[i]);
		ret[i] = (String)malloc(size+1);
		for(size_t j=0; j<size; ++j)
		{
			ret[i][j] = s[i][j];
		}
		ret[i][size] = '\0';
	}
	return ret;
}

// Return an allocated string from an open file,
// Stop reading when any Stringacter is in terminators list
// return allocated string or (String*)NULL
String getfString(FILE* pFIn, String terminators){
    String s = getfc(pFIn, terminators, 0);
    return s;
}

String getString(String terminators){
    String s;
    s = getfc(stdin, terminators, 0);
    return s;
}

String getfc(FILE* pFIn, String terminators, int n){

    String s;
    char c = fgetc(pFIn);
    //base case
    if(c == EOF || StringInString(terminators, c)){
        // allocate a string
        s = mallocString(n);    
        if(s != NULL){
            // terminate the string
            s[n+1] = (char)NULL;
        }    
        return s;
    }
    s = getfc(pFIn, terminators, n+1);
    s[n] = c;
    return s;
}

int StringInString(String t, char c){
    int i = 0;
    while(&(t[i]) != NULL){
        if(t[i] == c) return 1;
        i++;
    }
    return 0;
}

int compareStrings(const void*  a, const void* b)
{
	const String sa = *(const String*)a;
	const String sb = *(const String*)b;

	return strcmp(sa,sb);	
}

void sortStringList(String strings[], int n)
{
	qsort(strings, n, sizeof(String), compareStrings);
}

//End
