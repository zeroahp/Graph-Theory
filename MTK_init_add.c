void init_graph(Graph *G, int n){
    G->n = n;
    G->m = 0;
    int i,j;
    for(i = 0; i< G->n ; i++){
        for(j = 0; j< G->n ;j++){
            G->A[i][j] = 0;
        }
    }
}

void add_edge(Graph *G, int u, int v){
    G->A[u][v] = 1;
    G->A[v][u] = 1;
    G->m ++;
}