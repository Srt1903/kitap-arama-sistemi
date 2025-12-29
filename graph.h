#ifndef GRAPH_H
#define GRAPH_H


#define MAX_BOOKS 100
#define MAX_NEIGHBORS 20


typedef struct {
    int neighbors[MAX_NEIGHBORS];
    int neighborCount;
} GraphNode;


typedef struct {
    GraphNode nodes[MAX_BOOKS];
    int bookCount;
} Graph;


/* Grafik işlemleri */
void initGraph(Graph *g, int bookCount);
void addEdge(Graph *g, int src, int dest);


/* BFS */
void bfs(Graph *g, int start);


#endif