#include "../inc/libmx.h"

char *mx_replace_substr(const char *str, const char *sub, const char *replace){
    if(!str || !sub || !replace) return NULL;

    int count_sub = mx_count_substr(str, sub);
    int len_str = mx_strlen(str);
    int len_sub = mx_strlen(sub);
    int len_replace = mx_strlen(replace);

    char *result_string = mx_strnew(len_str - count_sub * (len_replace -
                len_sub));
    int i = 0;
    int j = 0;
    while(i < len_str){
        if(mx_strncmp(str + i, sub, len_sub) == 0){
            for(int k = 0; k < len_replace; ++k){
                result_string[j++] = replace[k];
            }
            i += len_sub;
        } else {
            result_string[j++] = str[i++];
        }
    }

    return result_string;
}

