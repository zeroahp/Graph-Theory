#include <stdio.h>

#define MAX_M 50

typedef struct{
    int u, v;
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
    pG->m ++;
}

int degree(Graph *pG, int u){
    int i, cnt = 0;
    for(i =0 ;i<pG->m ;i++){
        if(pG->edges[i].u == u)
            cnt++;
        if(pG->edges[i].v == u)
            cnt++;
    }
    return cnt;
}

int main(){
    Graph G;
    freopen("dt.txt","r", stdin);
    int n, m;
    scanf("%d %d",&n,&m);
    init_graph(&G, n);
    int i, u,v;
    for(i = 0 ; i< m ;i++){
        scanf("%d %d", &u,&v);
        add_edge(&G, u,v);
    }

    for( i = 1 ; i<= n ; i++){
        printf("deg(%d) = %d\n",i,degree(&G,i));
    }
    return 0;
}