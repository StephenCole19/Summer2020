// Strings.c
#include "Strings.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

String getfc(FILE* pFIn, String terminators, int n);
int charInString(String t, char c);

// a cover function for malloc()
// malloc and return memory for a string of stringsize characters
// return (String)NULL on failure
String mallocString(int stringsize)
{
  return (String)malloc(sizeof(char) * (stringsize + 1));
}

// just a cover function for free()
void freeString(String s) { free(s); }

// create a duplicate string of s
// return it
// return (String)NULL on failure
// should call mallocString(), and then strcpy()
String duplicateString(String s)
{
  String sCopy = mallocString(strlen(s));
  if (sCopy != (String)NULL) {
    strcpy(sCopy, s);
  }
  return sCopy;
}

int fputString(FILE* pFOut, String s)
{
  int stringLength = strlen(s);
  fprintf(pFOut, "%d", stringLength);
  return fprintf(pFOut, "%s\n", s);
}

// Return an allocated string from an open file,
// Stop reading when any character is in terminators list
// return allocated string or (String)NULL
String getfString(FILE* pFIn, String terminators)
{
  String s = getfc(pFIn, terminators, 0);
  return s;
}

String getString(String terminators)
{
  String s;
  s = getfc(stdin, terminators, 0);
  return s;
}

String getfc(FILE* pFIn, String terminators, int n)
{
  String s;
  char c = fgetc(pFIn);
  // base case
  if (c == EOF || charInString(terminators, c)) {
    // allocate a string
    s = mallocString(n);
    if (s != (String)NULL) {
      // terminate the string
      s[n + 1] = '\0';
    }
    return s;
  }
  s = getfc(pFIn, terminators, n + 1);
  s[n] = c;
  return s;
}

int charInString(String t, char c)
{
  int i = 0;
  while (t[i] != '\0') {
    if (t[i] == c)
      return 1;
    i++;
  }
  return 0;
}

// End
