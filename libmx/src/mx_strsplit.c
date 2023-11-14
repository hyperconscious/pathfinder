#include "../inc/libmx.h"

char **mx_strsplit(const char *s, char c){
    if(!s) return NULL;
    char **res = (char **)malloc((mx_count_words(s, c) + 1) * sizeof(char *));
    int i = 0;
    int j = 0;
    int checker = 0;

    while(s[i] != '\0'){
        if(s[i] == c){
            checker = 0;
            ++i;
        }
        else if(checker == 0){
            int start = i;
            while(s[i] != c && s[i] != '\0') i++;
            int len = i - start;
            res[j++] = mx_strndup(s + start, len);
            checker = 1;
        }
        else{
           ++i;
        }
    }
    res[j] = NULL;
    return res;
}

