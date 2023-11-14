#include "../inc/libmx.h"

int mx_count_words(const char *str, char c){
    if(!str) return -1;

    int count = 0;
    int checker = 0;

    for(int i = 0; str[i] != '\0'; ++i){
        if(str[i] != c && checker == 0){
            count++;
            checker = 1;
        }
        else if(str[i] == c)
            checker = 0;
    }
    return count;
}

