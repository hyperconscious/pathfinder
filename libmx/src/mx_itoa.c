#include "../inc/libmx.h"

char *mx_itoa(int number){
    if(number == -2147483648){
        char *resultString = mx_strnew(11);
        if(!resultString)
            return NULL;
        return mx_strcpy(resultString, "-2147483648");
    }
    if(number == 0){
        char *resultString = mx_strnew(1);
        if(!resultString)
            return NULL;
        *resultString = '0';
        return resultString; 
    }
    char buff[32];
    int isNegative = 1;
    int i = 0;
    int j = 0;
    if(number < 0){
        number = ~number + 1;
        isNegative = 0;
    }
    for(;number; ++i){
        buff[i] = (number % 10) + 48;
        number /= 10;
    }
    char *resultString = mx_strnew(i);
    if(isNegative == 0)
        *(resultString + j++) = '-';
    for(; j <= i; ++j){
        *(resultString + j) = buff[i - j - isNegative];
    }
    return resultString;
}

