#ifndef HTMLLIB_H
#define HTMLLIB_H

//Pass in the input array, the array of htag pointers and the parrallel htag counting array
//Return: void
void addTagToList(char *inputPtr, char **htagsIndexArr, int *htagsCountingArr);

//Pass in the input pointing at the first char of a tag
//Returns the length of that tag in the input string
int lengthOfTag(char *inputPtr);

//Pass in the input pointing at the first char of a tag
//Returns a deep copy string of the tag
char *duplicateTag(char *inputPtr);

//Pass in the size of the string you wish to malloc
//returns the malloc'd memory pointer
char *mallocString(int stringsize);

//Pass in the desired array size
//Returns the array of desired size with allocated memory and all init null
char **initHtagsIndexArr(int arrSize);

//Pass in the desired array size
//Returns the array of desired size with allocated memory and all init 0
int *initHtagsCountingArr(int arrSize);

//Pass in the array counting tags and the index of the tag
//Returns the count of tag
int getTagCount(int *htagsCountArr, int index);

//Pass in the counting tags array and the index of the incrementing tag
//Return: void
void increaseTagCount(int *htagsCountArr, int index);

//Pass in the input array
//returns 1 if it is a comment and 0 if it is not
int isStartOfComment(char *input);

#endif