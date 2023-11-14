#include "pathfinder.h"

t_graph* create_graph(int numIslands) {
    t_graph* myGraph = (t_graph*)malloc(sizeof(t_graph));
    myGraph->islands = (char**)malloc(sizeof(char*) * numIslands);
    myGraph->matrix = (int**)malloc(sizeof(int*) * numIslands);
    for (int i = 0; i < numIslands; i++) {
        myGraph->islands[i] = NULL;
        myGraph->matrix[i] = (int*)malloc(sizeof(int) * numIslands);
        for(int j = 0; j < numIslands; j++){
            myGraph->matrix[i][j] = 0;
        }
    }
    myGraph->countOfIslands = 0;
    myGraph->totalIslands = numIslands;
    return myGraph;
}

int find_island(t_graph* graph, char* island) {
    for (int i = 0; i < graph->countOfIslands; i++) {
        if (mx_strcmp(island, graph->islands[i]) == 0)
            return i;
    }
    return -1;
}

void add_route(t_graph* graph, char* island1, char* island2, int* distance) {
    int index1 = find_island(graph, island1);
    int index2 = find_island(graph, island2);
    if(index1 != -1 && index2 != -1){
        if(graph->matrix[index1][index2] != 0){
            mx_strdel(&island1);
            mx_strdel(&island2);
            free(distance);
            delete_graph(graph);
            error_handler(DUPLICATE_BRIDGES, NULL);
        }
    }
    else {
        if((graph->countOfIslands + 1 > graph->totalIslands 
                    && graph->countOfIslands != 0) || graph->totalIslands == 1){
            mx_strdel(&island1);
            mx_strdel(&island2);
            free(distance);
            delete_graph(graph);
            error_handler(INVALID_NUMBER_OF_ISLANDS, NULL);
        }
    }
    if (index1 == -1) {
        graph->islands[graph->countOfIslands++] = mx_strdup(island1);
        index1 = graph->countOfIslands - 1;
    }
    if (index2 == -1) {
        graph->islands[graph->countOfIslands++] = mx_strdup(island2);
        index2 = graph->countOfIslands - 1;
    }

    graph->matrix[index1][index2] = *distance; 
    graph->matrix[index2][index1] = *distance; 
}

void delete_graph(t_graph* graph) {
    for (int i = 0; i < graph->totalIslands; i++) {
        mx_strdel(&graph->islands[i]);
        free(graph->matrix[i]);
    }
    free(graph->islands);
    free(graph->matrix);
    free(graph);
}

