#include "libmx.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct s_graph {
    char** islands;
    int** matrix;
    int countOfIslands;
    int totalIslands;
} t_graph;
typedef struct s_path {
    char* from;
    char* to;
    int* distances;
    int length;
    struct s_path* next;
} t_path;
enum Error_code {
    WRONG_USAGE,
    FILE_DOES_NOT_EXIST,
    FILE_IS_EMPTY,
    LINE_IS_NOT_VALID,
    INVALID_NUMBER_OF_ISLANDS,
    DUPLICATE_BRIDGES,
    INVALID_SUM_OF_BRIDGES
};

void printerr(const char* message);
void error_handler(enum Error_code error, const void* data);

void validate_file(const char* filename);
int parse_first_line(int fd);
int parse_bridges(int fd, char** r_island1, char** r_island2, int** r_distance);

t_graph* create_graph(int numIslands);
void add_route(t_graph* graph, char* island1, char* island2, int* distance);
void delete_graph(t_graph* graph);
int find_island(t_graph* graph, char* island);

void dijkstra(t_graph* graph, char* startIsland);
//void dijkstra(t_graph* graph, char* startIsland, char* endIsland);
