/*
 *	backwards.c -	random access example:
 *					using fseek and ftell to move within a file.
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

	}/* End if(FpIn...	*/


	/*
	 *	Write the file backwards
	 */

	/*	Go to the end of the file and get it's position	*/
	fseek(pFIn, 0L, SEEK_END);
	lInLen = ftell(pFIn);

	/*
	 * Starting at the end,
	 * get the character, print it, backup
	 */
	printf("%s is %ld bytes long:\n", argv[1], lInLen);
	printf("Char\tPosition\n");
	for(lOffset = lInLen; lOffset >=0 ; --lOffset)
	{
		fseek(pFIn, lOffset, SEEK_SET);
		cIn = fgetc(pFIn);
		printf("%c\t: %ld\n", cIn, lOffset );

	}/* End for(lOffset...	*/

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

/*
 *	Done!
 */


/** OUTPUT

U:\teach\cs1003\2001W\Classes\Week13.1\code\backwards\Debug> backwards ..\theFile.txt
..\TheFile.txt is 117 bytes long:
Char	Position
�	: 117
l	: 116
l	: 115
o	: 114
t	: 113
S	: 112
 	: 111
d	: 110
r	: 109
o	: 108
f	: 107
f	: 106
i	: 105
l	: 104
C	: 103
-	: 102
		: 101
		: 100

	: 99

	: 98
.	: 97
e	: 96
s	: 95
l	: 94
e	: 93
 	: 92
g	: 91
n	: 90
i	: 89
h	: 88
t	: 87
e	: 86
m	: 85
o	: 84
s	: 83
 	: 82
g	: 81
n	: 80
i	: 79
o	: 78
d	: 77
 	: 76
t	: 75
o	: 74
n	: 73
 	: 72
e	: 71
r	: 70
'	: 69
u	: 68
o	: 67
y	: 66
 	: 65
t	: 64
a	: 63
h	: 62
t	: 61
 	: 60
s	: 59
e	: 58
t	: 57
u	: 56
n	: 55
i	: 54
m	: 53
 	: 52
y	: 51
t	: 50
x	: 49
i	: 48
s	: 47
 	: 46
s	: 45
i	: 44

	: 43

	: 42
d	: 41
r	: 40
a	: 39
o	: 38
b	: 37
y	: 36
e	: 35
k	: 34
 	: 33
e	: 32
h	: 31
t	: 30
 	: 29
d	: 28
n	: 27
i	: 26
h	: 25
e	: 24
b	: 23
 	: 22
e	: 21
r	: 20
'	: 19
u	: 18
o	: 17
y	: 16
 	: 15
t	: 14
a	: 13
h	: 12
t	: 11
 	: 10
r	: 9
u	: 8
o	: 7
h	: 6
 	: 5
y	: 4
r	: 3
e	: 2
v	: 1
E	: 0
*/
