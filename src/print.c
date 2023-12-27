#include "pathfinder.h"

void printLine(){
    for(int i = 0; i < 40; i++)
        mx_printchar('=');
    mx_printchar('\n');
}


void printPaths(t_graph* graph, int* dist, int** primary_pathes, int src, int
        dest, int paths_count) {
    printLine();
    for(int count = 0; count < paths_count; count++){
        if(primary_pathes[dest][count] == -1) break;
        if (dist[dest] != INT_MAX) {
            mx_printstr("Path: ");
            mx_printstr(graph->islands[src]);
            mx_printstr(" -> ");
            mx_printstr(graph->islands[dest]);
            mx_printstr("\nRoute: ");

            int current = dest;
            int path[graph->countOfIslands];
            int path_len = 0;

            while (current != src) {
                path[path_len++] = current;
                current = primary_pathes[current][count];
                if (current == -1) {
                    break;
                }
            }
            path[path_len++] = src;

            for (int i = path_len - 1; i > 0; i--) {
                mx_printstr(graph->islands[path[i]]);
                mx_printstr(" -> ");
            }
            mx_printstr(graph->islands[path[0]]);
            mx_printstr("\nDistance: ");

            int distance = 0;

            if (path_len - 1 != 1) {
                for (int i = path_len - 1; i > 0; i--) {
                    distance += graph->matrix[path[i]][path[i - 1]];
                    mx_printint(graph->matrix[path[i]][path[i - 1]]);
                    if (i == 1) {
                        mx_printstr(" = ");
                    } else {
                        mx_printstr(" + ");
                    }
                }

                mx_printint(distance);
                mx_printchar('\n');
            } else {
                mx_printint(dist[path[0]]);
                mx_printchar('\n');
            }
        }
    }
    printLine();
}

void printPath(t_graph* graph, int** pathes, int path_index, int end) {
    mx_printstr("========================================\n");

    mx_printstr("Path: ");
    mx_printstr(graph->islands[pathes[path_index][0]]);
    mx_printstr(" -> ");
    mx_printstr(graph->islands[end]);
    mx_printchar('\n');

    mx_printstr("Route: ");
    int i = 0;
    int path_len = 0;
    while(pathes[path_index][path_len + 1] != -1){
        if(pathes[path_index][path_len] == end){
            break;
        }
        path_len++;
    }
    for(i = 0; i < path_len; i++){
        if(graph->islands[pathes[path_index][i]]
                == graph->islands[end]){
            break;
        }
        mx_printstr(graph->islands[pathes[path_index][i]]);
        mx_printstr(" -> ");
    }
    mx_printstr(graph->islands[end]);
    mx_printchar('\n');

    mx_printstr("Distance: ");
    int distance = 0;
    bool isPlus = false;
    for (i = 0; i < path_len; ++i) {
        int from = pathes[path_index][i];
        int to = pathes[path_index][i + 1];
        if(graph->matrix[from][to] != 0){
            if(isPlus){
                mx_printstr(" + ");
            }
            distance += graph->matrix[from][to];
            mx_printint(graph->matrix[from][to]);
            isPlus = true;
        }
    }
    if(i != 1){
        mx_printstr(" = ");
        mx_printint(distance);
    }
    mx_printstr("\n");

    mx_printstr("========================================\n");
}

