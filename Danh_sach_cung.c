#include <stdio.h>

#define MAX_EDGES 50
typedef struct  {
	 int x, y;
} Edge;
typedef struct {
	int n, m;
	Edge edges[MAX_EDGES];
} Graph;

void init_graph(Graph* G, int n){
	G->n = n;
	G->m = 0;
}

void add_edge(Graph *G, int x, int y) {
    if(x<1 || x > G->n || y<1 || y>G->n)
        return;
    G->edges[G->m].x = x;
    G->edges[G->m].y = y;
    G->m++;
}