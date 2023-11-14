#include "../inc/libmx.h"

bool mx_isPrime(const int num){
    if(num <= 1) return false;

    for(int i = 2; i < mx_sqrt(num); i++){
        if(num % i == 0) return false;
    }
    return true;
}

