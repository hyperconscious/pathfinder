#include "pathfinder.h"
void dfs(t_graph* graph, int start, int end, int* visited, int* path,
        int* path_len, int** pathes, int* dist, int min_dist, int* path_count) {

    visited[start] = 1;
    path[(*path_len)++] = start;

    if (start == end && *path_len > 1) {
        int path_distance = 0;

        for (int i = 0; i < *path_len - 1; ++i) {
            path_distance += graph->matrix[path[i]][path[i + 1]];
        }

        if (path_distance == min_dist) {
            int k = 0;

            while (pathes[k][0] != -1) {
                k++;
            }

            for (int i = *path_len - 1; i >= 0; i--) {
                pathes[k][*path_len - 1 - i] = path[i];
            }

            pathes[k + 1][0] = -1; 
            (*path_count)++;
        }
    }

    for (int i = 0; i < graph->countOfIslands; ++i) {
        if (graph->matrix[start][i] != 0 && !visited[i]) {
            dfs(graph, i, end, visited, path, path_len, pathes, dist, min_dist, path_count);
        }
    }

    (*path_len)--;
    visited[start] = 0;
}

int findPaths(t_graph* graph, int startIdx, int endIdx, int** pathes, int* dist) {
    int visited[graph->countOfIslands];
    int path[graph->countOfIslands];
    int path_len = 0;
    int path_count = 0;
    int min_dist = dist[endIdx];

    for (int i = 0; i < graph->countOfIslands; ++i) {
        visited[i] = 0;
        path[i] = -1;
    }

    pathes[0][0] = -1;

    dfs(graph, endIdx, startIdx,  visited, path, &path_len, pathes, dist, min_dist, &path_count);

    return path_count;
}
