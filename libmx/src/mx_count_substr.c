#include "../inc/libmx.h"

int mx_count_substr(const char *str, const char *sub){
     if (!str || !sub) return -1;

    int count = 0;

    while(*str){
        int checker = mx_get_substr_index(&*(str), &*(sub));
        if(checker == -1)
            break;
        count++;
        str += checker + mx_strlen(sub);
    }
    return count;
}

