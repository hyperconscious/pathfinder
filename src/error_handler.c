#include "pathfinder.h"

void error_handler(enum Error_code error, const void* data){
    switch(error){
        case WRONG_USAGE:
            printerr("usage: ./pathfinder [filename]\n");
            break;
        case FILE_DOES_NOT_EXIST:
            printerr("error: file ");
            printerr((char*)data);
            printerr(" does not exist\n");
            break;
        case FILE_IS_EMPTY:
            printerr("error: file ");
            printerr((char*)data);
            printerr(" is empty\n");
            break;
        case LINE_IS_NOT_VALID:
            printerr("error: line ");
            char* str = mx_itoa(*(int*)data);
            printerr(str);
            printerr(" is not valid\n");
            mx_strdel(&str);
            break;
        case INVALID_NUMBER_OF_ISLANDS:
            printerr("error: invalid number of islands\n");
            break;
        case DUPLICATE_BRIDGES:
            printerr("error: duplicate bridges\n");
            break;
        case INVALID_SUM_OF_BRIDGES:
            printerr("error: sum of bridges lengths is too big\n");
            break;
    }
    exit(1);
}
