#include "../inc/libmx.h"

char *mx_upstr(const char *str){
    if(!str) return NULL;
    char *res = mx_strdup(str);

    for(int i = 0; i < mx_strlen(res); ++i){
        if(res[i] >= 'a' && res[i] <= 'z'){
            res[i] = res[i] - 32;
        }
    }
    return res;
}

