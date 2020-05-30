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
		
	char** tagTable = (char**)malloc(MAX_NUM_TAGS*sizeof(char*));
	for(int i=0;i < MAX_NUM_TAGS;i++){
		tagTable[i] = (char*)malloc(MAX_TAG_SIZE);
	}
	
	int tagIndex = 0;
	for(int i=1; i<numLines; i++)
	{
		char* tagLocation;
		tagLocation = strstr(inputArr[i], "<");
		if(tagLocation != NULL)
		{
			if(*(tagLocation + 1) == '/' || *(tagLocation + 1) == '!')
			{
				if(*(tagLocation + 2) == '-')
					continue;
				tagLocation++;
				tagLocation++;
			}
			
			scanWord(tagLocation, tagTable[tagIndex]);
			tagIndex++;
			
			tagLocation = strstr((tagLocation + 1), "<");
			while(tagLocation != NULL)
			{
				if(*(tagLocation + 1) == '/' || *(tagLocation + 1) == '!')
				{
					if(*(tagLocation + 2) == '-')
						break;

					tagLocation++;
					tagLocation++;
				}
			
				scanWord(tagLocation, tagTable[tagIndex]);
				tagIndex++;
				tagLocation = strstr((tagLocation + 1), "<");
			}
		}
	}	

	char** foundTags = (char**)malloc(MAX_TYPE_TAGS*sizeof(char*));
	for(int i=0;i < MAX_TYPE_TAGS;i++){
		foundTags[i] = (char*)malloc(MAX_TAG_SIZE);
	}
	
	int numFoundTags = 0;
	bool check = true;
	for(int i=0;i<tagIndex; i++)
	{
		for(int j=0;j<numFoundTags;j++)
		{
			if(strcmp(tagTable[i],foundTags[j]) == 0)
			{
				check = false;
				break;
			}	
		}

		if(check)
		{
			strcpy(foundTags[numFoundTags],tagTable[i]);
			int tagCount = 1;

			for(int k=i+1; k<tagIndex; k++)
			{
				if(strcmp(foundTags[numFoundTags],tagTable[k]) == 0)
					tagCount++;
			}

			printf("%s\t%d\n",foundTags[numFoundTags], tagCount);
			numFoundTags++;
		}
		
		check = true;
	}


	fclose(fp);
	free(line);
	free(tagTable);
	free(inputArr);
	free(foundTags);

	return EXIT_SUCCESS;
}
