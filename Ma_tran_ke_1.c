#include <stdio.h>
#define MAX_N 100

typedef struct {
	int n, m;
	int A[MAX_N][MAX_N];
} Graph;

void init_graph(Graph *G, int n){
    G->n = n;
    G->m = 0;
    int i, j;
    for(i = 0; i< G->n ; i++){
        for(j = 0; j< G->n ;j++){
            G->A[i][j] = 0;
        }
    }
}
// vo huong thuong
void add_edge(Graph *G, int u, int v){
    G->A[u][v] = 1;
    G->A[v][u] = 1;
    G->m ++;
}

// da do thi vo huong co khuyen
void add_edge(Graph *G, int u, int v){
    G->A[u][v] ++;
    if (u != v)
        G->A[v][u] ++;
    G->m ++;
}

// đồ thị có hướng (có thể chứa đa cung và chứa khuyên). 
void add_edge(Graph *G, int u, int v){
    G->A[u][v] ++;
    G->m ++;
}

int main() {
    Graph G;
    int n, m,u,v;
    scanf("%d%d", &n, &m);
    init_graph(&G, n);

    //Đọc m cung và thêm vào đồ thị
    for (int e = 0; e < m; e++) {
        scanf("%d%d", &u, &v);
        add_edge(&G, u, v);
    }
    
    //In ma trận kề của đồ thị
    for (int u = 1; u <= G.n; u++) {
        for (int v = 1; v <= G.n; v++)
            printf("%d ", G.A[u][v]);
        printf("\n");	
    }	
    return 0;
}