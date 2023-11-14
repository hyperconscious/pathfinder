#include "../inc/libmx.h"

int mx_memcmp(const void *s1, const void *s2, size_t n){
    const unsigned char *b1 = s1;
    const unsigned char *b2 = s2;

    for(size_t i = 0; i < n; ++i){
        if(b1[i] != b2[i])
            return (int)(b1[i] - b2[i]);
    }
        return 0;
}

