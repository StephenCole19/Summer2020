#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include"htags.h"

#define MAX_TYPE_TAGS 99
#define MAX_TAG_SIZE 20
#define MAX_NUM_TAGS 5000
#define MAX_STRING_LENGTH 255

void instantiateInputArray(char** inputArr, char* line, FILE* fp)
{
	int i = 0;
	while(fgets(line, MAX_STRING_LENGTH, fp))
	{
		inputArr[i] = (char*)malloc(MAX_STRING_LENGTH);
		strcpy(inputArr[i], line);
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
     word[counter] = *start;
     counter++;
     start++;
   }
   word[counter] = '\0';
   return;
}
