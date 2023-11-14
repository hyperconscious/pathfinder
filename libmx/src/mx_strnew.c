#include "../inc/libmx.h"

char *mx_strnew(const int size){
    if(size < 0)
        return NULL;

    char *str;
    str = (char*) malloc((size + 1) * sizeof(char));
    if(str == NULL) return str;

    for(int i = 0; i < size + 1; ++i)
        *(str + i) = '\0';
    return str;
}

