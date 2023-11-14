#include "../inc/libmx.h"

char *mx_strtrim(const char *str){
    if(!str) return NULL;
    int str_end = mx_strlen(str);
    int str_start = 0;

    while(str_end >= 0 && str[str_end] < 33) str_end--;
    while(str_start <= str_end && str[str_start] < 33) str_start++;

    return mx_strndup(str + str_start, str_end - str_start + 1);
}

