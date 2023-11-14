#include "pathfinder.h"
int minDistance(int dist[], bool vertex[], int size){
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
void printLine(){
    for(int i = 0; i < 40; i++)
        mx_printchar('=');
    mx_printchar('\n');
}
void printPaths(t_graph* graph, int size, int dist[], int parent[][size], int
        src, int dest, int path_count[]) {
    for (int count = 0; count < path_count[dest]; count++) {
        if (dist[dest] != INT_MAX) {
            mx_printstr("Path: ");
            mx_printstr(graph->islands[src]);
            mx_printstr(" -> ");
            mx_printstr(graph->islands[dest]);
            mx_printstr("\nRoute: ");
            int current = dest;
            int path[size];
            int path_len = 0;
            while (current != src) {
                path[path_len++] = current;
                current = parent[current][count];
                if(current == -1)
                    break;
            }
                path[path_len++] = src;
                for (int i = path_len - 1; i > 0; i--) {
                    mx_printstr(graph->islands[path[i]]);
                    mx_printstr(" -> ");
                }
                mx_printstr(graph->islands[path[0]]);
                mx_printstr("\nDistance: ");
                int distance = 0;
                if(path_len - 1 != 1){
                    for (int i = path_len - 1; i > 0; i--) {
                        distance += graph->matrix[path[i]][path[i - 1]];
                        mx_printint(graph->matrix[path[i]][path[i - 1]]);
                        if(i == 1){
                            mx_printstr(" = ");
                        }
                        else {
                            mx_printstr(" + ");
                        }
                    }
                    mx_printint(distance);
                    mx_printchar('\n');
                }
                else {
                    mx_printint(dist[path[0]]);
                    mx_printchar('\n');
                }
        }
    }
}

void dijkstra(t_graph* graph, char* island){
    int takenVertex = -1;
    int size = graph->countOfIslands;
    bool vertex[size];
    int parent[size][size];
    int path_count[size];
    int dist[size];
    for(int i = 0; i < size; i++){
        if(mx_strcmp(graph->islands[i], island) == 0){
            takenVertex = i;
        }
        dist[i] = INT_MAX;
        vertex[i] = false;
        path_count[i] = 0;
        for(int j = 0; j < size; j++)
            parent[i][j] = -1;
    }
    dist[takenVertex] = 0;
    path_count[takenVertex] = 1;
    for (int count = 0; count < size - 1; count++) {
        int u = minDistance(dist, vertex, size);
        vertex[u] = true;
        for (int v = takenVertex; v < size; v++) {
            if (!vertex[v] && graph->matrix[u][v] && dist[u] != INT_MAX &&
                    dist[u] + graph->matrix[u][v] <= dist[v]) {
                if(dist[u] + graph->matrix[u][v] == dist[v]){
                    parent[v][path_count[v]] = u;
                    path_count[v]++;
                }
                else {
                    dist[v] = dist[u] + graph->matrix[u][v];
                    parent[v][0] = u;
                    path_count[v] = 1;
                }
            }
        }
    }
    for (int i = takenVertex + 1; i < size; i++) {
        if (dist[i] != INT_MAX) {
            printLine();
            printPaths(graph,size, dist, parent, takenVertex, i, path_count);
            printLine();
        }
    }
}
