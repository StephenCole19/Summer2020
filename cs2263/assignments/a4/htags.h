#ifndef INTEGER_H
#define INTEGER_H

void instantiateInputArray(char** inputArr, char* line, FILE* fp);
int getlines(FILE* fp, char* line);
void scanWord(char* start, char* word);
int findSameTags(char** foundTags, char* tag, char** indexTable, int numTagsFound, int currentIndex);

#endif
