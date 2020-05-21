#ifndef INTEGER_H
#define INTEGER_H

// a cover function for malloc()
// malloc and return memory for a int array of intsize
// return (int*)NULL on failure
int* mallocIntArray(int intsize);

// create a duplicate int array of iArr
// return it
// return (int*)NULL on failure
// should call mallocIntArray(), then copy
int* duplicateInt(int* iArr);

int** duplicateIntArrays(int** iArrs, int size1d, int size2d);

#endif
