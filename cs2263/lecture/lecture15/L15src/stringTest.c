#include <stdlib.h>
#include <stdio.h>
#include "Strings.h"

int main(int argc, char* argv[]){
	FILE *pFIn;
	char* string;
    char terminators[2];
    terminators[0] = 'E';
    terminators[0]= (char)NULL;

	/* Argument check	*/
	if(argc != 2)
	{
		fprintf(stderr,"Usage: %s <filename>\n", argv[0]);
		return EXIT_FAILURE;

	}/* End if(argc...	*/

	/* Open the file given through the command line	*/
	pFIn = fopen(argv[1], "r");
	if(pFIn == (FILE*) NULL)
	{
		fprintf(stderr,"Could not open %s\n", argv[1]);
		return EXIT_FAILURE;

	}/* End if(pFIn...	*/

    string = getfString(pFIn, terminators);
    fclose(pFIn);
    printf("%s", string);

    return EXIT_SUCCESS;
}