#include <stdio.h>
#include "graph.h"
#include "queue.h"


void initGraph(Graph *g, int bookCount) {
    g->bookCount = bookCount;
    for (int i = 0; i < bookCount; i++) {
        g->nodes[i].neighborCount = 0;
    }
}


void addEdge(Graph *g, int src, int dest) {
    if (g->nodes[src].neighborCount < MAX_NEIGHBORS) {
        g->nodes[src].neighbors[g->nodes[src].neighborCount++] = dest;
    }
}


void bfs(Graph *g, int start) {
    int visited[MAX_BOOKS] = {0};
    Queue q;


    initQueue(&q);
    enqueue(&q, start);
    visited[start] = 1;


    printf("BFS traversal starting from book %d:\n", start);


    while (!isQueueEmpty(&q)) {
        int current = dequeue(&q);
        printf("Visited book %d\n", current);


        for (int i = 0; i < g->nodes[current].neighborCount; i++) {
            int neighbor = g->nodes[current].neighbors[i];
            if (!visited[neighbor]) {
                visited[neighbor] = 1;
                enqueue(&q, neighbor);
            }
        }
    }
}