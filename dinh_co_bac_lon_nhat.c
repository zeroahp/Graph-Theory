#include <stdio.h>

#define Max_length 50

typedef struct {
    int A[100][500];
    int n, m;
} Graph;

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
void add_edge(Graph* pG, int x, int y) {
    pG->A[x][y] = 1;
    pG->A[y][x] = 1;
    pG->m++;
}

int deg(Graph *G, int u){
    int i, cnt = 0;
    for ( i = 1; i <= G->n; i++)
    {
        if(G->A[i][u] != 0)
            cnt ++;
    }
    return cnt;
    
}

typedef struct 
{
    int A[Max_length];
    int size;
}List;


void makenullList(List *L){
    L->size = 0;
}

void push_List(List *L, int x){
    L->A[L->size ] = x;
    L->size ++;
}

int element(List *L, int i){
    return L->A[i-1];
}


List neighbors(Graph *G, int u) {
    List L;
    makenullList(&L);
    int i, j;
    for( i = 1; i<=G->n ;i++){
        if(u == i) continue;
        for(j = 1 ; j<=G->m ;j++){
            if(G->A[u][j] != 0 && G->A[i][j] != 0){
                push_List(&L,i);
                break;
            }
        }
    }
    return L;

}



int main(){
    
    Graph G;
    int n,m;
    freopen("dt.txt", "r", stdin);
    scanf("%d%d",&n,&m);
    init_graph(&G,n);
    int i,u,v;
    for ( i = 1; i <= m; i++)
    {
        scanf("%d %d",&u,&v);
        add_edge(&G,u,v);
    }
    // int j;
    // for ( i = 1; i <= G.n; i++)
    // {
    //     for ( j = 1; j <= G.n; j++)
    //         {
    //             printf("%d ",G.A[i][j]);
    //         }
    //         printf("\n");
    // }
    int tmp = 0;
    int max = deg(&G,1);
    for( i = 2; i <= G.n ;i++){
        if(max < deg(&G,i)){
            max = deg(&G,i);
            tmp = i;
        }
            
    }
    printf("%d %d",tmp, max);
    return 0;
}