#include "../inc/libmx.h"

int mx_strncmp(const char *s1, const char *s2, size_t n) {
    while (n--) {
        if (*s1 != *s2)
            return *s1 - *s2;
        if (*s1 == '\0')
            return 0;
        s1++;
        s2++;
    }
    return 0;
}
