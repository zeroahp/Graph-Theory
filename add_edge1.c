#include <stdio.h>

#define MAX_M 500   

typedef struct 
{
    int u,v;
}Edge;

typedef struct 
{
    int n,m;
    Edge edges[MAX_M];
}Graph;

void init_graph(Graph *pG, int n){
    pG->n = n;
    pG->m = 0;
}

void add_edge(Graph *pG, int u, int v){
    pG->edges[pG->m].u = u;
    pG->edges[pG->m].v = v;
    pG->m++;

}

int main(){
    Graph G;
    init_graph(&G,4);
    printf("Do thi co %d dinh va %d cung.\n", G.n, G.m);
    add_edge(&G,1,2);
    add_edge(&G,3,4);
    int i;
    for(i = 0; i< G.m ; i++)
        printf(" %d - %d\n", G.edges[i].u, G.edges[i].v);
    return 0;
}