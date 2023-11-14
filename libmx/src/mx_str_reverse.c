#include "../inc/libmx.h"

void mx_str_reverse(char *s){
    if(!s) return;
    int size = mx_strlen(s) - 1;
    int i = 0;

    while(i < size){
        mx_swap_char(&s[i], &s[size]);
        i++;
        size--;
    }
    return;
}

