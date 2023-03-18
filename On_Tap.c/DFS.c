#include <stdio.h>

#define Max_vertices 100
#define Max_stack 100
typedef struct 
{
    int A[Max_vertices][Max_vertices];
    int n,m;
}Graph;

void init_graph(Graph *G, int n){
    G->n = n;
    int i, j;
    for(i = 1 ; i <= G->n ; i++)
        for(j = 1; j <= G->n ; j++)
            G->A[i][j] = 0;
    
}

void add_edge(Graph *G, int x, int y){
    G->A[x][y] = 1;
    G->A[y][x] = 1;
    G->m ++;
}

int adjacent(Graph *G, int x, int y){
    return G->A[x][y] == 1;
}


int mark[Max_vertices], parent[Max_vertices];

void DFS(Graph *G, int x, int mark[], int parent[], int p){
    if(mark[x] == 1) 
        return;
    printf("%d\n",x);
    mark[x] = 1;
    parent[x] = p;
    int v; 
    for(v = 1 ; v<= G->n ; v++){
        if(adjacent(G,x,v)){
            DFS(G,v,mark,parent,x);
        }
    }
}


int main(){
    Graph G;
    int n, m, u, v, w, e;
    scanf("%d%d", &n, &m);
    init_graph(&G, n);

    for (e = 0; e < m; e++) {
        scanf("%d%d", &u, &v);
        add_edge(&G, u, v);
    }
    
    for(w = 1 ; w<=n ; w++){
        mark[w] = 0;
        parent[w] = -1;
    }

	DFS(&G,1,mark,parent,-1);
//    for(w = 1 ; w<=n ; w++){
//        DFS(&G,w,mark,parent,-1);
//    }
//
//    for(w = 1; w <= n ; w++){
//        printf("%d %d\n",w, parent[w]);
//    }
int i;
	for(i = 1; i<= G.n ;i++){
		printf("%d %d\n",i,parent[i]);
	}
    return 0;
}
