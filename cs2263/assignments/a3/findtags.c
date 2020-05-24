#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include"htags.h"

#define MAX_TYPE_TAGS 99
#define MAX_TAG_SIZE 20
#define MAX_NUM_TAGS 5000
#define MAX_STRING_LENGTH 255

/*
 * This whole program is a mess
 *
 */
int main(int argc, char* argv[])
{
	FILE *fp;
	char *line = (char*)malloc(MAX_STRING_LENGTH);

	fp = fopen(argv[1], "r");
	if(!fp)
		perror(argv[1]), exit(1);
	
	int numLines = getlines(fp, line);	
	
	char** inputArr = (char**)malloc(numLines*sizeof(char*));
	instantiateInputArray(inputArr, line, fp);
		
	char** indexTable = (char**)malloc(MAX_NUM_TAGS);
	int i = 1;
	while(i < MAX_NUM_TAGS)
	{
		*(indexTable + i) = (char*)malloc(1);
		i++;
	}

	int currentIndex = 1;
	for(i=1; i<=numLines; i++)
	{
		char* tagLocation;
		tagLocation = strstr(*(inputArr + i), "<");
		if(tagLocation != NULL)
		{
			*(indexTable + currentIndex) = tagLocation;
			currentIndex++;
			tagLocation++;
			tagLocation = strstr(tagLocation, "<");
			if(tagLocation != NULL)
	    {
				*(indexTable + currentIndex) = tagLocation;
				currentIndex++;
			}
		}
		
	}

	char** foundTags = (char**)malloc(MAX_NUM_TAGS);
	i = 1;
	while(i < MAX_NUM_TAGS)
	{
		*(foundTags + i) = (char*)malloc(MAX_TAG_SIZE);
		i++;
	}	
	
	int numTagsFound = 1;
	for(i=1; i<currentIndex; i++)
	{
		char* start = *(indexTable + i);
		start++;
		
		if(*start == '/' || *start == '!')
		{
			start++;
			if(*start == '-')
				continue;
		}
		
		char* tag = (char*)malloc(MAX_STRING_LENGTH);
		scanWord(start, tag);
		
		numTagsFound = findSameTags(foundTags, tag, indexTable, numTagsFound, currentIndex);
		
	}

	fclose(fp);
	free(line);
	free(indexTable);
	free(inputArr);

	return EXIT_SUCCESS;
}
