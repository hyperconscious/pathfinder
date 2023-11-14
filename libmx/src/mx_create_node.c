#include "../inc/libmx.h"

t_list *mx_create_node(void *data){
    t_list *ptr = (t_list *)malloc(sizeof(t_list));
    if(!ptr)
        return NULL;
    ptr->data = data;
    ptr->next = NULL;
    return ptr;
}

