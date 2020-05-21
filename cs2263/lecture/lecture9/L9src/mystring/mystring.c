// mystring.c
#include "mystring.h"
#include <stdlib.h>
#include <ctype.h>
int my_strlen(const char * str){
    int len = 0;
    while (str[len] != (char)NULL)
        len++;
    return len;
}

int my_countchar(const char * str, char ch){
    int count = 0;
    while (* str != (char)NULL) {
        if (* str == ch)
            count++;
    str ++;
    }
    return count;
}

void my_strupper(char * str){
    while (* str != (char)NULL) {
        * str = toupper(* str);
        str++;
    }
}
char * my_strchr(const char * str, char ch){
    int ind = 0;
    while (str[ind] != (char)NULL){
        if (str[ind] == ch)
            // generates a warning, but we're OK with discarding the 'const' qualifier.
            return (& str[ind]);
        ind ++;
    }
// if the program reaches here, ch is not in str
return (char*)NULL;
}
