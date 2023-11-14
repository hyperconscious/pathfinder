#include "../inc/libmx.h"

void *mx_memmem(const void *big, size_t big_len,
                const void *little, size_t little_len){
    if(big_len < little_len || big_len == 0 || little_len == 0)
        return NULL;

    const unsigned char *haystack = big;
    const unsigned char *needle = little;

    size_t j = 0;
    if(big_len >= little_len && little_len > 0){
        for(size_t i = 0; i < big_len; ++i){
            for(j = 0; j < little_len; ++j){
                if(haystack[i + j] != needle[j])
                    break;
            }
            if(j == little_len)
                return (void *)&haystack[i];
        }
    }
    return NULL;
}

