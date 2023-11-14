#include "../inc/libmx.h"

char *mx_file_to_str(const char *file){
    if(!file)
        return NULL;
    int len = 0;
    char c;

    int r_file = open(file, O_RDONLY);
    if (r_file < 0) return NULL;
    while(read(r_file, &c, 1)) len++;
    if (len < 1) return NULL;
    close(r_file);
    char *str = mx_strnew(len);
    r_file = open(file, O_RDONLY);
    if(r_file < 0) return NULL;
    read(r_file, str, len);
    close(r_file);
    return str;
}

