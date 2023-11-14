#include "../inc/libmx.h"

void *mx_memrchr(const void *s, int c, size_t n){
    const unsigned char *ptr = s;

    while(n-- > 0){
        if(ptr[n] == (unsigned char)c)
            return (void *)&ptr[n];
    }

    return NULL;
}

