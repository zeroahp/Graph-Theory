#include <stdio.h>

#define Max_vertices 100
#define oo 99999

typedef struct 
{
    int u,v,w;
}Edge;

typedef struct 
{
    Edge edges[Max_vertices];
    int n,m;
}Graph;

void init_graph(Graph *G, int n){
    G->n = n;
    G->m = 0;
}

void add_edge(Graph *G, int u, int v, int w){
    G->edges[G->m].u = u;
    G->edges[G->m].v = v;
    G->edges[G->m].w = w;
    G->m++;
}

int pi[Max_vertices], p[Max_vertices];
int negative_circle = 0;

void Bellman_Ford(Graph *G, int s){
    pi[s] = 0;
    p[s] = -1;

    int u,v,w,i,j;
    for(i = 1 ; i < G->n ;i++)
    {

        for(j = 0 ; j < G->m ; j++)
        {
            u = G->edges[j].u ;
            v = G->edges[j].v ;
            w = G->edges[j].w ;

            if(pi[u] == oo) continue;

            if(pi[u] + w < pi[v])
            {
                pi[v] = pi[u] + w;
                p[v] = u;
            }
        }
    }

    for(j = 0 ; j < G->m ; j++)
        {
            u = G->edges[j].u ;
            v = G->edges[j].v ;
            w = G->edges[j].w ;

            if(pi[u] == oo) continue;

            if(pi[u] + w < pi[v])
            {
                negative_circle = 1;
                break;
            }
        }
}

int main(){
    Graph G;
    int n, m;
    scanf("%d %d", &n, &m);
    init_graph(&G,n);
    int u, v, w, i;
    for(i = 1 ; i <= m ; i++){
        scanf("%d %d %d", &u, &v, &w);
        add_edge(&G,u,v,w);
    }

    int x;
    for(x = 1 ; x <= n ; x++){
        pi[x] = oo;
        p[x] = -1;
    }

    int s;
    scanf("%d", &s);
    Bellman_Ford(&G,s);

    if(negative_circle)
        printf("YES");
    else printf("NO");

    return 0;
}

