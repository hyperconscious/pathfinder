#include "../inc/libmx.h"

unsigned long mx_hex_to_nbr(const char *hex){
 if (hex == NULL){
        return 0;
    }
    unsigned long res = 0;
    unsigned long pow = 1;;
    int len = 0;
    while (hex[len] != '\0'){
        ++len;
    }
    for (int i = len - 1; i >= 0; --i){
        if (hex[i] >= '0' && hex[i] <= '9'){
            res += ((hex[i] - 48) * pow);
            pow *= 16;
        }   
        if(hex[i] >= 'A' && hex[i] <= 'z'){
            if(hex[i] >= 'A' && hex[i] <= 'Z'){
                res += ((hex[i] - 55) * pow);
                pow *= 16;
            }
            else {
                res += ((hex[i] - 87) * pow);
                pow *= 16;
            }
        }
    }
    return res;
}

