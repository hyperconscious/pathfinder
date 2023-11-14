#include "../inc/libmx.h"

char *mx_del_extra_spaces(const char *str){
    if(!str) return NULL;
    int str_end = mx_strlen(str);
    int str_start = 0;
    int flag = 0;

    while(str_end >= 0 && str[str_end] < 33) str_end--;
    while(str_start <= str_end && str[str_start] < 33) str_start++;
    char *result_str = mx_strnew(str_end - str_start);
    int j = 0;
    for(int i = str_start; i <= str_end; i++){
        if(str[i] <= 32){
            if(flag == 0){
                result_str[j++] = ' ';
                flag = 1;
            }
        }
        else {
            result_str[j++] = str[i];
            flag = 0;
        }
    }
    return result_str;
}

