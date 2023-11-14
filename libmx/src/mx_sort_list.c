#include "../inc/libmx.h"

t_list *mx_sort_list(t_list *lst, bool (*cmp)(void *, void *)){
        if (!lst || !cmp) {
        return NULL;
    }

    int swapped;
    t_list *ptr1 = NULL;
    t_list *lptr = NULL;

    while (1) {
        swapped = 0;
        ptr1 = lst;

        while (ptr1->next != lptr) {
            if (cmp(ptr1->data, ptr1->next->data)) {
                void *temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }

        if (!swapped) {
            break;
        }
        lptr = ptr1;
    } 
    return lst;
}

