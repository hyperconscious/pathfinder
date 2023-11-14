#include "../inc/libmx.h"

char *mx_lowstr(const char *str){
    if(!str) return NULL;
    char *res = mx_strdup(str);

    for(int i = 0; i < mx_strlen(res); ++i){
        if(res[i] >= 'A' && res[i] <= 'Z'){
            res[i] = res[i] + 32;
        }
    }
    return res;
}

