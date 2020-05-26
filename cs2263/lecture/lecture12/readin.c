#include <stdio.h>

int main(int argc, char** argv)
{
	FILE* fp = fopen(argv[1], "r");
	int c;

	c = fgetc(fp);

  while (!feof(fp))
  {
      printf("%c",c);
			c = fgetc(fp);
  }

	fclose(fp);
}
