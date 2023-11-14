#include "../inc/libmx.h"

int mx_binary_search(char **arr, int size, const char *s, int *count){
    int left = 0;
    int right = size - 1;
    int cc = 0;

    while(left <= right){
        ++cc;
        int mid = left + (right - left) / 2;

        if(mx_strcmp(arr[mid], s) == 0){
            *count = cc;
            return mid;
        }

        if(mx_strcmp(arr[mid], s) > 0)
            right = mid - 1;
        else
            left = mid + 1;
    }
    cc = 0;
    *count = cc;
    return -1;
}

