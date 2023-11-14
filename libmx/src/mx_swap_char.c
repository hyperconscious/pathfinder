#include "../inc/libmx.h"

void mx_swap_char(char *s1, char *s2){
    if(s1 != NULL && s2 != NULL 
        && *s1 != '\0' && *s2 != '\0'){
        char temp = *s1;
        *s1 = *s2;
        *s2 = temp;
    }
}

