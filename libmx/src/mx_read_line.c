#include "../inc/libmx.h"

int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd){
    if (!lineptr || buf_size < 1 || buf_size > 2147483647 || fd < 0) {
        return -2; 
    }

    static char* str_rest = NULL;
    char *text = NULL;
    size_t text_len = 0;

    if(str_rest != NULL){
        text = str_rest;
        int delimIndex = mx_get_char_index(text, delim);
        if(delimIndex > -1){
            text[delimIndex] = '\0';
            str_rest = mx_strdup(&text[delimIndex] + 1);
        }
        else {
            str_rest = NULL;
        }

        char* text_ptr = text;
        text_len = mx_strlen(text);
        text = mx_strndup(text, text_len);
        mx_strdel(&text_ptr);
        if(str_rest != NULL){
            if(mx_strlen(str_rest) == 0)
                mx_strdel(&str_rest);
            *lineptr = text;
            return text_len;
        }

    }

    char *line = mx_strnew(buf_size);
    ssize_t read_bytes = -1;

    while((read_bytes = read(fd, line, buf_size)) > 0){
        int delimIndex = mx_get_char_index(line, delim);
        if(delimIndex > -1){
            line[delimIndex] = '\0';
            str_rest = mx_strdup(&line[delimIndex] + 1);
        }
        else {
            str_rest = NULL;
        }

        char* text_ptr = text;
        text_len += mx_strlen(line);
        text = mx_strjoin(text, line);
        mx_strdel(&text_ptr);
        if(str_rest != NULL){
            if(mx_strlen(str_rest) == 0)
                mx_strdel(&str_rest);
            break;
        }
    }
    mx_strdel(&line);

    if(read_bytes == -1){
        mx_strdel(&text);
        mx_strdel(&str_rest);
        return -2;
    }
    if(text == NULL){
        return -1;
    }

    *lineptr = text;
    return text_len;
}
