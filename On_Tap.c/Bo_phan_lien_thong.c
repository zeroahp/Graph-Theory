#include <stdio.h>
    // do thi vo huong

#define Max_vertices 100
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

int mark[Max_vertices];

//3 - DEM SO DINH CUA BO PHAN LIEN THONG
int nb_u;
void DFS(Graph *G, int u, int mark[]){
    mark[u] =1;
    nb_u++;
    int v;
    for(v = 1 ; v <= G->n ; v++)
        if(mark[v] == 0 && adjacent(G, v, u))
            DFS(G,v, mark);   
}

// 1 - KTRA BO PHAN LIEN THONG
int connected(Graph *G){
    int i;
    for( i = 1 ; i <= G->n ; i++)
        mark[i] = 0;
    
    DFS(G,1,mark);

    for( i = 1 ; i <= G->n ; i++)
        if(mark[i] == 0)
            return 0;
    return 1;
}

int main(){
    Graph G;
    int n, m, u, v, e;
    scanf("%d%d", &n, &m);
    init_graph(&G, n);

    for (e = 0; e < m; e++) {
        scanf("%d%d", &u, &v);
        add_edge(&G, u, v);
    }

    // 1 - KTRA BO PHAN LIEN THONG
    if(connected(&G))
        printf("CONNECTED\n");
    else  printf("DISCONNECTED\n");
    printf("\n****************\n");

    //2 - DEM SO PHAN LIEN THONG
    int i,cnt = 0;

    for( i = 1 ; i <= G.n ; i++)
        mark[i] = 0;

    for( i = 1 ; i <= G.n ; i++)
        if(mark[i] == 0){
            DFS(&G,i,mark);
            cnt ++;
        }
    
    printf("\n%d",cnt);
    printf("\n****************\n");

    //3 - DEM SO DINH CUA BO PHAN LIEN THONG
    nb_u = 0;
    DFS(&G,1,mark);
    printf("%d", nb_u);
    printf("\n****************\n");

    //4 - TIM BO PHAN LIEN THONG CO NHIEU DINH NHAT
    int cnt_max = 0;
    for( i = 1 ; i <= G.n ; i++){
        if(mark[i] == 0){
            nb_u = 0;
            DFS(&G,i,mark);
        }
        if(nb_u > cnt_max)
            cnt_max = nb_u;
    }
    
    printf("%d", cnt_max);
 
    return 0;
}