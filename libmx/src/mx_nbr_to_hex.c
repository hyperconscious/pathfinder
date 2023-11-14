#include "../inc/libmx.h"

char *mx_nbr_to_hex(unsigned long nbr){
    int i = 0;
    int size = 155;
    char buff[size];

    while(nbr > 16){
        if(nbr % 16 > 9)
        {
            buff[i] = (nbr % 16) % 10 + 97;
        }
        else
            buff[i] = nbr % 16 + 48;
        nbr /= 16;
        ++i;
    }
    if(nbr > 9)
        buff[i++] = nbr % 10 + 97;
    else
        buff[i++] = nbr + 48;

    char *hex_nbr = mx_strnew(i);
    for(int k = 0; k < i; ++k)
        *(hex_nbr + k) = buff[i - k - 1];

    return hex_nbr;
}

