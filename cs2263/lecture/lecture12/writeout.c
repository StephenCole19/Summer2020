#include <stdio.h>

int main(int argc, char** argv)
{
	FILE* fp = fopen(argv[1], "w");
	int c = fgetc(stdin);

  while (!feof(stdin))
    {
      fprintf(fp, "%c",c);
			c = fgetc(stdin);
    }

	fclose(fp);
}
