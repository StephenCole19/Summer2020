#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "htmllib.h"

//Pass in the input array, the array of htag pointers and the parrallel htag counting array
//Return: void
void addTagToList(char *inputPtr, char **htagsIndexArr, int *htagsCountingArr)
{
    char *dupeTag = (char *)NULL;
    char **indexPtr = htagsIndexArr;
    int isRepeatFound = 0;

    dupeTag = duplicateTag(inputPtr);

    int i = 0;
    while (*indexPtr != '\0')
    {
        if (0 == strcmp(dupeTag, *indexPtr))
        {
            isRepeatFound = 1;
            increaseTagCount(htagsCountingArr, i);
            break;
        }
        indexPtr++;
        i++;
    }

    if (isRepeatFound == 0)
    {
        *indexPtr = dupeTag;
        increaseTagCount(htagsCountingArr, i);
    }
}

//Pass in the input array
//returns 1 if it is a comment and 0 if it is not
int isStartOfComment(char *input)
{
    char *inputPtr = input;
    int isStartOfComment = 0;

    if (*inputPtr == '<')
    {
        inputPtr++;
        if (*inputPtr == '!')
        {
            inputPtr++;
            if (*inputPtr == '-')
                isStartOfComment = 1;
        }
    }
    return isStartOfComment;
}

//Pass in the array counting tags and the index of the tag
//Returns the count of tag
int getTagCount(int *htagsCountArr, int index)
{
    int *arrPtr = htagsCountArr;

    for (int i = 0; i < index; i++)
        arrPtr++;

    return *arrPtr;
}

//Pass in the counting tags array and the index of the incrementing tag
//Return: void
void increaseTagCount(int *htagsCountArr, int index)
{
    int *arrPtr = htagsCountArr;

    for (int i = 0; i < index; i++)
        arrPtr++;

    (*arrPtr)++;
}

//Pass in the input pointing at the first char of a tag
//Returns the length of that tag in the input string
int lengthOfTag(char *inputPtr)
{
    char *countingPtr = inputPtr;
    int tagLength = 0;

    while ((*countingPtr >= 65 && *countingPtr <= 90) ||
           (*countingPtr >= 97 && *countingPtr <= 122))
    {
        countingPtr++;
        tagLength++;
    }

    return tagLength;
}

//Pass in the input pointing at the first char of a tag
//Returns a deep copy string of the tag
char *duplicateTag(char *inputPtr)
{
    int tagLength = lengthOfTag(inputPtr);
    char *dupeString = mallocString(tagLength);
    char *dupePtr = inputPtr;

    for (int i = 0; i < tagLength; i++)
    { //Deep copy from the dummy input pointer onto the duplicate string
        *dupeString = *dupePtr;
        dupeString++;
        dupePtr++;
    }

    dupeString = dupeString - tagLength; //Move duplicate string pointer back to beginning
    if (dupeString == (char *)NULL)
    {
        fprintf(stderr, "Memory allocation failed. Program terminating.");
        return (char *)NULL;
    }

    return dupeString;
}

//Pass in the size of the string you wish to malloc
//returns the malloc'd memory pointer
char *mallocString(int stringsize)
{
    char *strMem = (char *)malloc(sizeof(char) * stringsize);

    if (strMem == (char *)NULL)
    {
        fprintf(stderr, "Memory allocation failed. Program terminating.");
        return (char *)NULL;
    }

    return strMem;
}

//Pass in the desired array size
//Returns the array of desired size with allocated memory and all init null
char **initHtagsIndexArr(int arrSize)
{
    char **htagsArr = (char **)malloc(sizeof(char *) * arrSize);
    char **htagsPointer = htagsArr;

    int i = 0;
    while (i < arrSize)
    {
        *htagsPointer = '\0';
        i++;
        htagsPointer++;
    }

    return htagsArr;
}

//Pass in the desired array size
//Returns the array of desired size with allocated memory and all init 0
int *initHtagsCountingArr(int arrSize)
{
    int *countingArr = (int *)malloc(sizeof(int) * arrSize);
    int *arrPointer = countingArr;

    int i = 0;
    while (i < arrSize)
    {
        *arrPointer = 0;
        i++;
        arrPointer++;
    }

    return countingArr;
}