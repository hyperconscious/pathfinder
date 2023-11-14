#include "libmx.h"

int mx_atoi(const char* s){
    int number = 0;
    int i = 0;
    int sign = 1;
    if(s[i] == '+' || s[i] == '-'){
        if(s[i] == '-') sign -= 2;
        i += 1;
    }
    for(; s[i] != '\0'; ++i){
        if(mx_isdigit(s[i] - '0')){
            if(number > INT_MAX / 10 
                    || (number == INT_MAX / 10 
                        && (s[i] - '0') > INT_MAX % 10)){
                        return 0;
                    }
            number *= 10;
            number += s[i] - '0';
        }
    }
    return number * sign;
}

