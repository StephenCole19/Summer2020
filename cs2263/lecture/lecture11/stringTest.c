#include <stdio.h>
#include <stdlib.h>
#include "Strings.h"

// copies the program name (argv[0]) to a new string, prints it out
int main(int argc, char* argv[]){

	char* programName;

	programName = duplicateString(argv[0]);
	if(programName == (char*)NULL){
		fprintf(stderr,"Memory failure, terminating");
		return EXIT_FAILURE;
	}
	// Did we do it? Can we print it out?
		printf("%s\n", programName);

	free(programName);

	return EXIT_SUCCESS;
}


