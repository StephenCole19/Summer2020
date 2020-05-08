#include <stdio.h>

int main()
{
    int value;
    int iErr;
    printf("Value to examine: ");
    iErr = scanf("%d",&value);
    if(iErr != 1){
        printf("Unable to read the value\n");
        return 0;
    }
    else if(value < 0){
        printf("Negative value!\n");
        return 0;
    }
    int ones = 0;
    
    while(value > 0)
    {
        if(value == 1){
            ones++;
            value = -1;
        }
        if(value%2 > 0){
            ones++;
            value = value/2 - 0.5;
        }
        else{
            value = value/2;
        }
    }
    
    printf("%d", ones);
    return 0;
    
}
