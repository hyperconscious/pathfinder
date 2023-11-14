#include "../inc/libmx.h"

int mx_strlen(const char* s){
    int count = 0;
    const char *at = s;

    while(*at != '\0'){
        at++;
        count++;
    }

    return count;
}

