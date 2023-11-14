#include "../inc/libmx.h"

int mx_bubble_sort(char **arr, int size){
    int swap_operations = 0;
    char *temp;
    while(size != 0){
        for(int i = 0; i < size - 1; ++i){
            if(mx_strcmp(arr[i], arr[i + 1]) > 0){
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                ++swap_operations;
            }
        }
        --size;
    }
    return swap_operations;
}

