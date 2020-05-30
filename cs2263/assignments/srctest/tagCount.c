//Test for increasing and getting the tag count from an array

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "htmllib.h"
#define COUNT_ARR_SIZE 100

void printArray(int *arrayIn, int arraySize);

int main()
{
    //Read file form stdin
    int *countArr = initHtagsCountingArr(COUNT_ARR_SIZE);
    int indexArr[] = {3,4,1,5,6,2,2};
    int indexArrSize = 7;

    for(int i=0; i<indexArrSize; i++){
        int j = 0;
        while(j<indexArr[i]){
            increaseTagCount(countArr, i);
            j++;
        }
    }

    printf("indexArr: ");
    printArray(indexArr, indexArrSize);

    printf("counntArr: ");
    printArray(countArr, indexArrSize);

    return EXIT_SUCCESS;
}

void printArray(int *arrayIn, int arraySize){
    printf("[");
    for(int i=0; i<arraySize; i++){
        if(i==(arraySize-1))
            printf("%d", arrayIn[i]);
        else
            printf("%d, ", arrayIn[i]);
    }
    printf("]\n");
}