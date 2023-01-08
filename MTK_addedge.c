void add_edge(Graph *G, int u, int v){
    G->A[u][v] = 1;
    G->A[v][u] = 1;
    G->m ++;
}
void add_edge(Graph *G, int u, int v){
    G->A[u][v] = 1;
    G->m ++;
}
void add_edge(Graph *G, int u, int v){
    G->A[u][v] ++;
    if(u != v) G->A[v][u] ++;
    G->m ++;
}
void add_edge(Graph *G, int u, int v){
    G->A[u][v] ++;
    G->m ++;
}