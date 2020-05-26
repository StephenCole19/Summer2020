/*
 *	arrayPosition.c - addresses and offsets for a character array
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char** argv)
{
	char*	sString =
		"Fifteen years ago I couldn't spell C, and now I can program in it!";
	int	iCount;
	int iStringLen;

	iStringLen = strlen(sString);
	/*
	 *	Print each character,
	 *	its position from the start of the array
	 *	and its address
	 */
	printf("Char\tPosition\tAddress\n");
	for(iCount = 0; iCount < iStringLen ; ++iCount)
	{
		printf("%c:\t%d\t\t%p\n", sString[iCount], iCount, &sString[iCount] );

	}/* End for(iCount...	*/

	printf("\n");

	return EXIT_SUCCESS;

}/* End main() */
