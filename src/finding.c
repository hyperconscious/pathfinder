#include "pathfinder.h"
int minDistance(int* dist, bool vertex[], int size){
    int min = INT_MAX;
    int idx = -1;
    int i = 0;
    for(; i < size; i++){
        if(vertex[i] == false && dist[i] <= min){
            min = dist[i];
            idx = i;
        }
    }
    return idx;
}

int* dijkstra(t_graph* graph, int startIdx, int** primary_pathes){
    int size = graph->countOfIslands;
    int path_count[size];
    bool vertex[size];
    int* dist = (int *) malloc(sizeof(int) * size);
    for(int i = 0; i < size; i++){
        dist[i] = INT_MAX;
        vertex[i] = false;
        path_count[i] = 0;
        for(int j = 0; j < size; j++)
            primary_pathes[i][j] = -1;
    }
    dist[startIdx] = 0;
    path_count[startIdx] = 0;
    for (int count = 0; count < size - 1; count++) {
        int u = minDistance(dist, vertex, size);
        vertex[u] = true;
        for (int v = 0; v < size; v++) {
            if (!vertex[v] && graph->matrix[u][v] && dist[u] != INT_MAX &&
                    dist[u] + graph->matrix[u][v] <= dist[v]) {
                if(dist[u] + graph->matrix[u][v] < dist[v]){
                    dist[v] = dist[u] + graph->matrix[u][v];
                    primary_pathes[v][0] = u;
                    path_count[v] = 1;
                }
                else if(dist[u] + graph->matrix[u][v] == dist[v]){
                    primary_pathes[v][path_count[v]] = u;
                    path_count[v]++;
                }

            }
        }
    }
    for(int i = startIdx + 1; i < size; i ++){
        int dest = i;
        for(int count = 0; count < path_count[dest]; count++){
            int current = dest;
            while (current != startIdx) {
                if(path_count[current] > 1){
                    primary_pathes[dest][path_count[dest]]++;
                    break;
                }
                current = primary_pathes[current][count];
                if(current == -1)
                    break;
            }
        }
    }


    return dist;
}
