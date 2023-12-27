#include "pathfinder.h"

void pathfinder(t_graph* graph){
   int** primary_pathes = (int**) malloc(sizeof(int*) * (graph->countOfIslands+1));
    int** pathes = (int**) malloc(sizeof(int*) * (graph->countOfIslands *
                graph->countOfIslands));
    for (int i = 0; i <= graph->countOfIslands; ++i) {
        primary_pathes[i] = (int *)malloc(graph->countOfIslands  * sizeof(int));
    }
    for(int i = 0; i < graph->countOfIslands * graph->countOfIslands; i++){
        pathes[i] = (int *)malloc((graph->countOfIslands *
                    graph->countOfIslands) * sizeof(int));
    }

    for(int i = 0; i < graph->countOfIslands * graph->countOfIslands; i++){
        for(int j = 0; j <= graph->countOfIslands * graph->countOfIslands; j++){
            pathes[i][j] = -1;
        }
    }

    int* dist = NULL;
    for(int startIdx = 0; startIdx < graph->countOfIslands; startIdx++){
        dist = dijkstra(graph, startIdx, primary_pathes);

        for (int dest = startIdx + 1; dest < graph->countOfIslands; ++dest) {
            if(primary_pathes[dest][1] == -1){
                printPaths(graph, dist, primary_pathes, startIdx, dest, 1);
            }
            else{
                int paths_count = findPaths(graph, startIdx, dest, pathes, dist);

                for (int i = 0; i < paths_count; ++i) {
                    printPath(graph, pathes, i, dest);
                }
            }
        }
        free(dist);
    }


    for (int i = 0; i <= graph->countOfIslands; ++i) {
        free(primary_pathes[i]);
    }
    for (int i = 0; i < graph->countOfIslands * graph->countOfIslands; ++i) {
        free(pathes[i]);
    }
    free(primary_pathes);
    free(pathes);
}

