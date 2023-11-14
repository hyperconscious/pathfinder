#include "pathfinder.h"

bool validate_island(const char* is){
    int len = mx_strlen(is);
    if(len == 0) return false;
    for(int i = 0; i < len; ++i){
        if(!((is[i] >= 'A' && is[i] <= 'Z') || (is[i] >= 'a' && is[i] <= 'z')))
            return false;
    }
    return true;
}

bool validate_lenght(const char* s){
    int len = mx_strlen(s);
    if(len == 0) return false;
    for(int i = 0; i < len; ++i){
        if(!mx_isdigit(s[i] - '0'))
            return false;
    }
    return true;
}

void validate_file(const char* filename){
    char buf;
    int fd = open(filename, O_RDONLY);
    if(fd == -1) error_handler(FILE_DOES_NOT_EXIST, filename);
    ssize_t check = read(fd, &buf, 1);
    close(fd);
    if(check <= 0) error_handler(FILE_IS_EMPTY, filename);
}

int parse_first_line(int fd){
    static int first_line = 1;
    int str_len = 0;
    char* str = NULL;
    str_len += mx_read_line(&str, 1, '\n', fd);
    str[str_len] = '\0';
    for(int i = 0; str[i] != '\0'; ++i){
        if(!mx_isdigit(str[i] - '0')){
            mx_strdel(&str);
            close(fd);
            error_handler(LINE_IS_NOT_VALID, &first_line);
        }
    }

    int num_of_islands = mx_atoi(str);
    mx_strdel(&str);
    if(num_of_islands <= 0){
        mx_strdel(&str);
        error_handler(LINE_IS_NOT_VALID, &first_line);
    }
    return num_of_islands;
}

int parse_bridges(int fd, char** r_island1, char** r_island2, int** r_distance){
    static int line = 2;
    char* island1 = NULL;
    char* island2 = NULL;
    char* bridge_len_n = NULL;
    int* bridge = (int*)malloc(sizeof(int));
    int len = 0;
    if((len = mx_read_line(&island1, 1, '-', fd)) < 0){
        free(bridge);
        if(len == -1){
            return 0;
        }
        return line;
    }
    if((len = mx_read_line(&island2, 1, ',', fd)) < 0){
        mx_strdel(&island1);
        free(bridge);
        return line;
    }
    if((len = mx_read_line(&bridge_len_n, 1, '\n', fd)) < 0){
        mx_strdel(&island1);
        mx_strdel(&island2);
        free(bridge);
        return line;
    } 
    if(!validate_lenght(bridge_len_n)){
        mx_strdel(&island1);
        mx_strdel(&island2);
        mx_strdel(&bridge_len_n);
        free(bridge);
        return line;
    }
    *bridge = mx_atoi(bridge_len_n);
    mx_strdel(&bridge_len_n);
    if(*bridge <= 0 || !validate_island(island1) || !validate_island(island2)
            || mx_strcmp(island1, island2) == 0){
        mx_strdel(&island1);
        mx_strdel(&island2);
        free(bridge);
        return line;
    }
    *r_island1 = island1;
    *r_island2 = island2;
    *r_distance = bridge;
    line++;
    return -1;
}

