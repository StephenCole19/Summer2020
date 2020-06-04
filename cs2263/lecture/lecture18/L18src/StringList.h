
/*
 *	StringList.h file -- header file for StringLists (list of Strings)
 *
 * Original: Rick Wightman, June, 2020
 */
#include "Strings.h"
#include <stdlib.h>

#ifndef STRINGLIST_H
#define STRINGLIST_H

typedef struct stringlist {
  int length;
  String* Slist;
} StringList;

StringList* mallocStringList(int iNElements);

void freeStringList(StringList* pSLThis);

int setElementStringList(StringList* pSLThis, String sThis, int index);

String getElementStringList(StringList* pSLThis, int index);

StringList* duplicateStringList(StringList* pSLThis);

#endif
