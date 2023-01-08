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
    G->m ++;
}

int adjacent(Graph *G, int u, int v){
    return G->A[u][v] > 0;
}
//đồ thị vô hướng (có thể chứa đa cung và chứa khuyên)
// void neighbours(Graph *G, int u){
//     int i;
//     for( i = 1; i<= G->n ; i++){
//         if(G->A[i][u] != 0)
//             printf("%d ", i);
//     }
// }

//đồ thị có hướng (có thể chứa đa cung và khuyên)
void neighbours(Graph *G, int u){
    int i;
    for( i = 1; i<= G->n ; i++){
        if(G->A[u][i] != 0)
            printf("%d ", i);
    }
}


int main(){
    Graph G;
    int  n, m;
    scanf("%d%d",&n,&m);
    init_graph(&G,n);
    int i,u, j,v;
    for(i = 1; i<= m ;i++){
        scanf("%d %d", &u, &v);
        add_edge(&G,u,v);
    }
    for(i = 1; i<= n ;i++){
        for ( j = 1; j <= G.n; j++)
        {
           printf("%d ", G.A[i][j]);

        }
        printf("\n");
    }
    for(i = 1; i<= G.n ;i++){
        printf("neighbours(%d) = ", i);
        neighbours(&G,i);
        printf("\n");
    }

    return 0;
}