#include "pathfinder.h"

int main(int argc, char* argv[]){
    if(argc != 2){
        error_handler(WRONG_USAGE, NULL);
    }
    validate_file(argv[1]);
    int fd = open(argv[1], O_RDONLY);
    int numberOfIslands = parse_first_line(fd);
    t_graph* graph = create_graph(numberOfIslands);
    if(graph != NULL){
        int line;
        char* island1 = NULL;
        char* island2 = NULL;
        int* distance = NULL;
        long sumDistance = 0;
        while((line = parse_bridges(fd, &island1, &island2, &distance)) != 0){
            if(line > 0){
                close(fd);
                delete_graph(graph);
                error_handler(LINE_IS_NOT_VALID, &line);
            }
            sumDistance += *distance;
            if(sumDistance > INT_MAX){
                close(fd);
                mx_strdel(&island1);
                mx_strdel(&island2);
                delete_graph(graph);
                error_handler(INVALID_SUM_OF_BRIDGES, &line);
            }
            add_route(graph, island1, island2, distance);
            mx_strdel(&island1);
            mx_strdel(&island2);
            free(distance);
        }
    }
    close(fd);
    if(graph->countOfIslands != graph->totalIslands ){
        delete_graph(graph);
        error_handler(INVALID_NUMBER_OF_ISLANDS, NULL);
    }
    pathfinder(graph);
    delete_graph(graph);
    return 0;
}
