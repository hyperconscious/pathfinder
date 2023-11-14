#include "../inc/libmx.h"

char *mx_realloc(char *ptr, size_t size){
    if(size == 0){
        if(ptr)
            free(ptr);
        return NULL;
    }

    void *new_ptr = malloc(size);

    if(!new_ptr){
        return NULL;
    }

    if(ptr){
        mx_memcpy(new_ptr, ptr, size);
        free(ptr);
    }
    return new_ptr;
}

