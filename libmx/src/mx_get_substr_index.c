#include "../inc/libmx.h"

int mx_get_substr_index(const char *str, const char *sub){
    if(!str || !sub) return -2;

    int str_len = mx_strlen(str);
    int substr_len = mx_strlen(sub);

    for(int i = 0; i <= str_len - substr_len; ++i){
        int j;
        for(j = 0; j < substr_len; ++j){
            if(str[i + j] != sub[j])
                break;
        }
        if(j == substr_len)
            return i;
    }

    return -1;
}

