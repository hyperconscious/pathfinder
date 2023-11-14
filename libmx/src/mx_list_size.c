#include "../inc/libmx.h"

int mx_list_size(t_list *list){
    if(list == NULL)
        return 0;

    t_list *curr = list;
    int sz = 0;
    
    while(curr){
        ++sz;
        curr = curr->next;
    }
    return sz;
}

