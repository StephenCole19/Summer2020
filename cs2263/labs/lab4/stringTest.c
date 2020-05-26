#include <stdio.h>
#include <stdlib.h>
#include "Strings.h"

int main(int argc, char* argv[]){

	char* programName;

	programName = duplicateString(argv[0]);
	if(programName == (char*)NULL){
		fprintf(stderr,"Memory failure, terminating");
		return EXIT_FAILURE;
	}
		printf("%s\n", programName);

	free(programName);

	return EXIT_SUCCESS;
}


