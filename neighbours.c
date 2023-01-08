#include <stdio.h>

#define MAX_M 50
#define Max_length 50

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
// vo huong******************************************
int adjacent(Graph *pG, int u, int v){
    int i;
    for(i = 0; i< pG->m ; i++){
        if((pG->edges[i].u == u && pG->edges[i].v == v ) || (pG->edges[i].u == v && pG->edges[i].v == u))
            return 1;
    }
    return 0;
}

void neighbours(Graph *G, int u){
    int i;
    for(i = 1; i<= G->n ; i++){
        if(adjacent(G,i,u))// vo huong G,i,u
            printf("%d ", i);
    }
    
}

// co huong ******************************************
int adjacent(Graph *pG, int u, int v){
    int i;
    for(i = 0; i< pG->m ; i++){
        if((pG->edges[i].u == u && pG->edges[i].v == v ))
            return 1;
    }
    return 0;
}

void neighbours(Graph *G, int u){
    int i;
    for(i = 1; i<= G->n ; i++){
        if(adjacent(G,u,i)) // co huong G,u,i
            printf("%d ", i);
    }
    
}
//****************************************************

int main(){
    Graph G;
    int n, m;
    scanf("%d%d",&n,&m);
    G.n = n;
    init_graph(&G,n);
    int i,u,v;
    for( i = 0; i< m ; i++){
        scanf("%d %d", &u, &v);
        add_edge(&G,u,v);
    }
    
    for( i = 1 ; i<= G.n ; i++){
        printf("neighbours(%d) = ",i);
        neighbours(&G,i);
        printf("\n");
    }
    
    return 0;
}