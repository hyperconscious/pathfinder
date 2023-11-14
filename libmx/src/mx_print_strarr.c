#include "../inc/libmx.h"

void mx_print_strarr(char **arr, const char *delim){
    if (arr && delim){
        int i = 0;
        while(arr[i] != NULL){
            if(i != 0)
                mx_printstr(delim);
            mx_printstr(arr[i++]);
        }
        mx_printchar('\n');
    }
}

