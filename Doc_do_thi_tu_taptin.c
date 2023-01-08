#include <stdio.h>

#define Max_M 50
typedef struct 
{
    int n,m;
    int A[Max_M][Max_M];
}Graph;

void initgraph(Graph *G, int n){
    G->n = n;
    G->m = 0;
}

void add_egdes(Graph *G, int x, int y){
    G->A[x][y] = 1;
    G->A[y][x] = 1;
    G->m ++;
}

int main(){
    Graph G;
    int n, m;
    freopen("dt1.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    int i, u,v;
    initgraph(&G, n);
    for( i=1 ;i <=m ;i++){
        scanf("%d %d",&u,&v);
        add_egdes(&G, u,v);
    }
    int j;
    for( i=1 ;i <=G.n ;i++){
        for(j=1;j<=G.n;j++)
            printf("%d ",G.A[i][j]);
        printf("\n");
    }
    return 0;
}