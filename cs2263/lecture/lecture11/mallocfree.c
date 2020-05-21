#include <stdio.h>
#include <stdlib.h>

#define MAXVALS 4

int main(void){

	// allocate space for a float on the heap, 
	// return a pointer to it, 
	// cast it to a float* ,
	// store it in f;
	float* pf = (float*) malloc( sizeof(float) );
	if(pf == (float*)NULL){ 
		fprintf(stderr, "Memory allocation failed. Program terminating.");
		return EXIT_FAILURE;
	}
	printf("Please enter a float value: ");
	scanf("%f",pf); // pf is a pointer, with space allocated to it
	printf("%f it is!\n", *pf);
	free(pf); // all done with fp

	// allocate space for an integer [] that hold MAXVALS ints on the heap,
	// return a pointer to it, cast the void* to a int* , and store it in arr;
	int iErr;
	int* arr = (int*) malloc( sizeof(int)*MAXVALS );
	if(arr == (int*)NULL){ 
		fprintf(stderr, "Memory allocation failed. Program terminating.");
		return EXIT_FAILURE;
	}
	printf("Please enter %d integer values: ", MAXVALS);
	for(int i=0; i<MAXVALS; i++){
		iErr = scanf("%d",&arr[i]); // arr is a pointer, with space allocated
		if(iErr != 1){
			fprintf(stderr, "Read failed. Program terminating.");
			free(arr);
			return EXIT_FAILURE;
		}
		printf("%d it is!\n", arr[i]);
	}
	free(arr); //all done with arr

	// allocate space for an char [] of that hold MAXVALS chars on the heap 
	// (with room for the NULL), return a pointer to it, cast it to a char* ,
	// and store it in s. 
	// Note that although s isn't YET a string, that's the intention.
	char* s = (char*) malloc( sizeof(char)*(MAXVALS+1) );
	if(pf == (float*)NULL){ 
		fprintf(stderr, "Memory allocation failed. Program terminating.");
		return EXIT_FAILURE;
	}
	printf("Enter up to four characters: ");
	getchar(); // flushes newline feed from last response
	char c = getchar();
	int i = 0;
	while(c != '\n' && i < MAXVALS){ // leave room for the terminating NULL!
		s[i] = c;
		i++;
		c = getchar();
	}
	s[i] = (char) NULL; // terminate the string
	printf("%s it is!\n", s);
	free(s); // all done with s

	return EXIT_SUCCESS;
}


