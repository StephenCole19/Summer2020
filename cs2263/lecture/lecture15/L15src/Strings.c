#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "Strings.h"

char* getfc(FILE* pFIn, char* terminators, int n);
int charInString(char* t, char c);

// a cover function for malloc()
// malloc and return memory for a string of stringsize characters
// return (char*)NULL on failure
char* mallocString(int stringsize){
    return (char*)malloc(sizeof(char)*(stringsize+1));
}

// just a cover function for free()
void freeString(char* s){
    free(s);
}

// create a duplicate string of s
// return it
// return (char*)NULL on failure
// should call mallocString(), and then strcpy()
char* duplicateString(char* s){
    char* sCopy = mallocString(strlen(s));
    if(sCopy != (char*)NULL){
        strcpy(sCopy,s);
    }
    return sCopy;
}

char** duplicateStringList(char** s,int n){
    char** slCopy;
    // Allocate the list
    slCopy = (char**)malloc(sizeof(char*)*n);
    if(slCopy == (char**)NULL) return slCopy;

    // Allocate/duplicate the strings
    for(int i = 0; i<n; i++){
        slCopy[i] = duplicateString(s[i]);
        if(slCopy[i] == (char*)NULL){
            // Bad stuff - clean up and return
            for(int j=0; j<i; j++){
                freeString(slCopy[j]);
            }
            free(slCopy);
            slCopy = (char**)NULL;
            break;
        }
    }
    return slCopy;
}

// Return an allocated string from an open file,
// Stop reading when any character is in terminators list
// return allocated string or (char*)NULL
char* getfString(FILE* pFIn, char* terminators){
    char* s = getfc(pFIn, terminators, 0);
    return s;
}

char* getString(char* terminators){
    char* s;
    s = getfc(stdin, terminators, 0);
    return s;
}

char* getfc(FILE* pFIn, char* terminators, int n){

    char* s;
    char c = fgetc(pFIn);
    //base case
    if(c == EOF || charInString(terminators, c)){
        // allocate a string
        s = mallocString(n);    
        if(s != (char*)NULL){
            // terminate the string
            s[n+1] = (char)NULL;
        }    
        return s;
    }
    s = getfc(pFIn, terminators, n+1);
    s[n] = c;
    return s;
}

int charInString(char* t, char c){
    int i = 0;
    while(t[i] != (char)NULL){
        if(t[i] == c) return 1;
        i++;
    }
    return 0;
}

int compareStrings(char* a, char* b)
{
   int c = 0;

   while (*a == *b) {
      if (*a == '\0' || *b == '\0')
         break;
      a++;
			b++;
   }

   if (*a == '\0' && *b == '\0')
      return 0;
   else
      return -1;
}

//End
