#include<stdio.h> 

int main(int argc,char* argv[])
{
    int i;
    printf("Number Of Arguments Passed: %d\n",argc);
   	for(i=0;i<argc;i++)
    	printf("argv[%d]: %p\n", i, &argv[i]);
    return 0;
}

/*
int main(int argc,char* argv[]) 
{ 
    int counter; 
    printf("\nNumber Of Arguments Passed: %d\n",argc); 
   	for(counter=0;counter<argc;counter++) 
    	printf("\nargv[%d]: %p\n",counter, &argv[counter]); 
    return 0;

}
*/
