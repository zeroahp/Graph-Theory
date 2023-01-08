#include <stdio.h>

#define Max_length 50

typedef struct {
    int A[100][500];
    int n, m;
} Graph;

void init_graph(Graph *G, int n, int m){
    int u, i;
    G->n = n;
    G->m = m;
    for(u=1; u<= G->n ;u++){
        for(I=1;i<=m;i++){
            G->A[u][i] = 0;
        }
    }

}
void add_edge(Graph* pG, int e, int x, int y) {
    pG->A[x][e] = 1;
    pG->A[y][e] = 1;
}

int deg(Graph *G, int u){
    int i, cnt = 0;
    for ( i = 1; i <= G->m; i++)
    {
        if(G->A[i][u] != 0)
            cnt ++;
    }
    return cnt;
    
}

int main(){


    return 0;
}