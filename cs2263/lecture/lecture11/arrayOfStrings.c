#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char* argv[]){

	char** stringList;

	// allocate an array of pointers to strings (each string is a char*)
	stringList = (char**) malloc(sizeof(char*) * argc);
	if(stringList == (char**)NULL){
		fprintf(stderr,"Memory failure, terminating");
		return EXIT_FAILURE;
	}
	for(int i=0; i<argc; i++){
		// allocate the string
		stringList[i] = (char*) malloc( sizeof(char)* (strlen(argv[i]) +1) );
		if(stringList[i] == (char*)NULL){
			fprintf(stderr,"Memory failure, terminating");
			for(int j=0; j<i; i++){
				free(stringList[j]);
			}
			free(stringList);
			return EXIT_FAILURE;
		}
		// copy commandline arguement
		strcpy(stringList[i], argv[i]);
	}

	// Did we do it? Can we print them out?
	for(int i=0; i<argc; i++){
		printf("%s\n", stringList[i]);
	}

	// Cleaning up after ourselves, from the end to the beginning
	for(int i=0; i<argc; i++){
		free(stringList[i]);
	}
	free(stringList);

	return EXIT_SUCCESS;
}


