/*
 * lineLength - read in a line of 2D cartesian coordinates from a file,
 *    and calculate the length of the line.
 * 
 * Rick Wightman, May 2020
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float calcDistance(float x1, float y1, float x2, float y2);

int main(int argc, char* argv[]){
    FILE* pFIn; // a pointer for a FILE data type
    int iNRead;
    float x1;
    float x2;
    float y1;
    float y2;
    float distance;
    /* program requires a file name to read from */
    if(argc !=2){
        fprintf(stderr,"Usage: %s <file name>\n", argv[0]);
        return EXIT_FAILURE;
    }

    /* open the file or die */
    pFIn = fopen(argv[1], "r");
    if(pFIn == (FILE*)NULL){
        fprintf(stderr,"Unable to open file (%s)\n", argv[1]);
        return EXIT_FAILURE;
    }

    /* 
     * We need to read at least 2 points, calculate the indivdual distances and sum them.
     */
    distance = 0;
    iNRead = fscanf(pFIn, "%f %f", &x1, &y1);
    if(iNRead !=  2){
        fclose(pFIn);
        fprintf(stderr,"No values (%s)\n", argv[1]);
        return EXIT_FAILURE;
    }
    iErr = fscanf(pFIn, "%f %f", &x2, &y2);
    while(iErr == 2){
        distance += calcDistance(x1,y1,x2,y2);
        x2=x1;
        y2=y1;

        iNRead = fscanf(pFIn, "%f %f", &x2, &y2);
    }
    printf("Line length: %.2f\n", distance);

    /*
     * Done - close up!
     */
    fclose(pFIn);

    return EXIT_SUCCESS;
}

float calcDistance(float x1, float y1, float x2, float y2){
    float dX;
    float dY;
    float hypotenuse;
    dX = x2-x1;
    dY = y2-y1;
    hypotenuse = sqrt(dX*dX + dY*dY);
    return hypotenuse;
}