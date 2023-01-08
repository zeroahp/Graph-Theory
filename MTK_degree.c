#include <stdio.h>

#define MAX_N 100

typedef struct 
{
    int n,m;
    int A[MAX_N][MAX_N];
}Graph;

void init_graph(Graph *G, int n){
    G->n = n;
    G->m = 0;
    int i, j;
    for(i = 0; i< G->n ;i++){
        for(j =0 ;j<G->n ; j++){
            G->A[i][j] = 0;
        }
    }
}

void add_edge(Graph *G, int u, int v){
    G->A[u][v] = 1;
    G->A[v][u] = 1;
    G->m ++;
}

// đồ thị vô hướng (có thể chứa đa cung và chứa khuyên).
int degree(Graph *G, int u){
    int cnt = 0, i;
    for(i = 1; i<= G->n ; i++){
        cnt += G->A[u][i];
    }
    return cnt + G->A[u][u];
}

// đồ thị có hướng (có thể chứa đa cung và chứa khuyên).
int degree(Graph *G, int u){
    int i, cnt = 0;
    for(i = 1; i<= G->n ;i++){
        cnt += G->A[i][u] + G->A[u][i];
    }
    return cnt;
}

// <bac vao> đồ thị có hướng (có thể chứa đa cung và chứa khuyên).
int indegree(Graph *G, int u) {
    int cnt = 0, i;
    for( i =1 ;i <=G->n; i++){
        cnt += G->A[i][u];
    }
    return cnt + G->A[u][i];
}

// <bac ra> đồ thị có hướng (có thể chứa đa cung và chứa khuyên).
int outdegree(Graph *G, int u) {
    int cnt = 0, i;
    for( i=1 ;i<=G->n ; i++){
        cnt += G->A[u][i];
    }
    return cnt + G->A[i][u];
}

int main(){
    Graph G;
    int  n, m;
    scanf("%d%d",&n,&m);
    init_graph(&G,n);
    int i,j,u,v;
    for(i = 1; i<= m ;i++){
        scanf("%d %d", &u, &v);
        add_edge(&G,u,v);
    }
    printf("Ma tran ke:\n");
    for(i = 1; i<= G.n ;i++){
        for(j = 1 ;j<= G.n ; j++){
            printf("%d ", G.A[i][j]);
        }
        printf("\n");
    }

    return 0;
}