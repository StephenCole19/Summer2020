#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "Strings.h"

String getfc(FILE* pFIn, String terminators, int n);
int StringInString(String t, String c);

// a cover function for malloc()
// malloc and return memory for a string of stringsize Stringacters
// return (String*)NULL on failure
String mallocString(int stringsize){
    return (String*)malloc(sizeof((stringsize+1)));
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
    if(sCopy != (String*)NULL){
        strcpy(sCopy,s);
    }
    return sCopy;
}

String* duplicateStringList(String* s,int n){
    String* slCopy;
    // Allocate the list
    slCopy = (String**)malloc(sizeof(String*)*n);
    if(slCopy == (String**)NULL) return slCopy;

    // Allocate/duplicate the strings
    for(int i = 0; i<n; i++){
        slCopy[i] = duplicateString(s[i]);
        if(slCopy[i] == (String*)NULL){
            // Bad stuff - clean up and return
            for(int j=0; j<i; j++){
                freeString(slCopy[j]);
            }
            free(slCopy);
            slCopy = (String**)NULL;
            break;
        }
    }
    return slCopy;
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
    String c = fgetc(pFIn);
    //base case
    if(c == EOF || StringInString(terminators, c)){
        // allocate a string
        s = mallocString(n);    
        if(s != (String*)NULL){
            // terminate the string
            s[n+1] = (String)NULL;
        }    
        return s;
    }
    s = getfc(pFIn, terminators, n+1);
    s[n] = c;
    return s;
}

int StringInString(String t, String c){
    int i = 0;
    while(t[i] != (String)NULL){
        if(t[i] == c) return 1;
        i++;
    }
    return 0;
}

int compareStrings(String a, String b)
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
