#include "../inc/libmx.h"

void *mx_memmove(void *dst, const void *src, size_t len){
    unsigned char *d = dst;
    const unsigned char *s = src;

    if (d == s || len == 0) {
        return dst;
    }

    if (d < s || d >= s + len) {
        while (len--) {
            *d++ = *s++;
        }
    } else {
        unsigned char *temp = (unsigned char *)malloc(len);
        if (!temp) {
            return NULL;
        }
        mx_memcpy(temp, s, len);
        mx_memcpy(d, temp, len);
        free(temp);
    }

    return dst;
}

