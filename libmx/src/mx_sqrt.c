#include "../inc/libmx.h"

int mx_sqrt(int x){
    if(x <= 0)
        return 0;
    int left = 1;
    int right = x / 2;

    while(left <= right){
        int mid = left + (right - left) / 2;
        if(mid * mid == x)
            return mid;
        else if(x / mid < mid)
            right = mid - 1;
        else
            left = mid + 1;
         }
    return 0;
}

