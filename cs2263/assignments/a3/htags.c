#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include"htags.h"

#define MAX_TYPE_TAGS 99
#define MAX_TAG_SIZE 20
#define MAX_NUM_TAGS 5000
#define MAX_STRING_LENGTH 255


int findSameTags(char** foundTags, char* tag, char** indexTable, int numTagsFound, int currentIndex)
{
	int i;
	for(i=1; i<numTagsFound+1; i++)
	{
		if(strcmp(tag, *(foundTags + i)) == 0)
			return numTagsFound;
	}
	
	int numReps = 0;
	int j=1;
	for(j=1; j<currentIndex; j++)
	{
		char* start = *(indexTable + j);
		start++;
		
		if(*start == '/' || *start == '!')
		{
			start++;
			if(*start == '-')
				continue;
		}
		
		char* word = (char*)malloc(MAX_STRING_LENGTH);
		scanWord(start, word);
		
		if(strcmp(tag, word) == 0)
			numReps++;
	}	

	printf("%s   %d\n", tag, numReps);
  strcpy(*(foundTags + i), tag);
	return ++numTagsFound;
}

void instantiateInputArray(char** inputArr, char* line, FILE* fp)
{
	int i = 1;
	while(fgets(line, MAX_STRING_LENGTH, fp))
	{
		*(inputArr + i) = (char*)malloc(MAX_STRING_LENGTH);
		strcpy(*(inputArr + i), line);
		i++;
	}
}	

int getlines(FILE* fp, char* line)
{
	int numLines=0;
	while(fgets(line, MAX_STRING_LENGTH, fp))
		numLines++;
	
	rewind(fp);

	return numLines;
}

void scanWord(char* start, char* word)
{
   int counter = 0;
   if(*start == '<')
     start++;
   while(*start != '>' && *start != ' ' && *start != '/')
   {
     *(word + counter) = *start;
     counter++;
     start++;
   }
   *(word + counter) = '\0';
   return;
}
