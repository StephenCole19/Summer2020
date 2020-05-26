/*
 *	filePosition.c -random access example:
 *					using ftell to report the position within a file.
 *
 */

#include <stdio.h>
#include <stdlib.h>

void usage(char* pgmName);

int main(int argc, char* argv[])
{
	FILE		*pFIn;
	long int	lInLen;
	long int	lOffset;
	char		cIn;

	/* Argument check	*/
	if(argc != 2)
	{
		usage(argv[0]);
		return EXIT_FAILURE;

	}/* End if(argc...	*/

	/* Open the file given through the command line	*/
	pFIn = fopen(argv[1], "r");
	if(pFIn == (FILE*) NULL)
	{
		fprintf(stderr,"file %s not found\n", argv[1]);
		usage(argv[0]);
		return EXIT_FAILURE;

	}/* End if(pFIn...	*/


	
	/*	
	 *  Go to the end of the file and get it's position	.
	 *  PLEASE, PLEASE, PLEASE! This is for demonstration purposes only, since you'll read until EOF
	 *  Doing this as a standard thing and using it in a for loop will only show that you don't read 
	 *  your professor's comments (and you WILL look foolish)
	*/
	fseek(pFIn, 0L, SEEK_END);
	lInLen = ftell(pFIn);
	printf("%s is %ld bytes long:\n", argv[1], lInLen);

	/*
	 *	Read the file, report things about it.
	*/

	/* Print each character and it's position from the start of the file */
	fseek(pFIn, 0L, SEEK_SET);
	printf("Char\tPosition\n");
        lOffset = ftell(pFIn);
	cIn = fgetc(pFIn);
	while(cIn != EOF)
	{
		printf("%c\t: %ld\n", cIn, lOffset );
                lOffset = ftell(pFIn);
		cIn = fgetc(pFIn);

	}/* End for(lOffset...	*/
	printf("%c\t: %ld\n", cIn, lOffset );

	printf("\n");
	fclose(pFIn);

	return 0;

}/* End main() */


/*
 *	usage function
 */
 void usage(char* pgmName)
{
	fprintf(stderr,"%s <filename>\n", pgmName);
	return;

}/* End usage()	*/
