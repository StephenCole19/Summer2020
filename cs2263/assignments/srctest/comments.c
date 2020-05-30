#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "htmllib.h"
#define MAX_FILE_SIZE 10000

int main()
{
    //Read file form stdin
    char *input = (char *)NULL;
    input = malloc(MAX_FILE_SIZE * sizeof(char));
    fread(input, MAX_FILE_SIZE, 1, stdin);

    int numberOfComments = 0;

    while(*input != '\0')
    {
        if (isStartOfComment(input) == 1){
            numberOfComments++;
        }
        input++;
    }

    printf("Number of comments is: %d\n", numberOfComments);

    return EXIT_SUCCESS;
}