#include <stdio.h>
#include <string.h>
#define LINEL 200
int main(void){
	char line[LINEL+1], longest[LINEL+1]={'\0'};
	int maxline = 0, length;
	while(fgets(line, LINEL+1, stdin) != NULL){
		length = strlen(line)-1;
		if(length > maxline){
			maxline = length;
			strcpy(longest, line);
		}
	}
	printf("longest line: %s", longest);
	return 0;
}
