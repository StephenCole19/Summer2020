#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "htmllib.h"
#define MAX_FILE_SIZE 10000
#define MAX_UNIQUE_TAGS 100

int main(int argc, char* argv[])
{
    if (argc < 1){//check if a file is passed in
        printf("File input missing\n");
        return EXIT_FAILURE;
    }
    //Read file form stdin
    char *input = malloc(MAX_FILE_SIZE * sizeof(char));
    fread(input, MAX_FILE_SIZE, 1, stdin);


    //initialize the index array and the counting array
    char **htagsList = initHtagsIndexArr(MAX_UNIQUE_TAGS);
    int *htagsCountingArr = initHtagsCountingArr(MAX_UNIQUE_TAGS);

    //Process through every character in the input array
    for(int i=0; i<MAX_FILE_SIZE; i++){
        if(isStartOfComment(input) == 1){ //Check if the char is an html comment and skip it
            while(*input != '\n'){
                input++;
            }
        }   
        else{
            if(*input == '<'){//Check for beginning of a tag      
                input++;
                if ((*input >= 65 && *input <= 90) || 
                    (*input >= 97 && *input <= 122)){
                    addTagToList(input, htagsList, htagsCountingArr);
                }
            }
            input++;
        }
    }

    //Print out the tags and their corresponding counts
    int i = 0;
    while (*htagsList != '\0')
    {
        printf("%s\t%d\n", *htagsList, getTagCount(htagsCountingArr, i));
        htagsList++;
        i++;
    }

    return EXIT_SUCCESS;
}
