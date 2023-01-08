#include <stdio.h>
#define Max_vertices 20
#define Max_length 20

typedef struct{
    int A[Max_vertices][Max_vertices];
    int n;
}Graph;


typedef struct 
{
   int Data[Max_length];
   int Size; 
}List;

void initGraph(Graph *G, int n)
{   
    int i,j;
    G->n = n;
    for(i = 1 ; i <= G->n ; i++) 
        for(j = 1 ; j <= G->n ; j++)
            G->A[i][j] = 0;
}

void printGraph(Graph G, int n){
    int i, j;
    for(i = 1; i<= G.n ; i++)
        for(j = 1; j<=G.n ;j++)
            printf("%d ",G.A[i][j]);
}

void add_edge(Graph *G, int x, int y)
{   
    G->A[x][y] = 1;
    G->A[y][x] = 1;
}

int ajacent(Graph *G, int x, int y)
{
    return (G->A[x][y] != 0);
}

int degree(Graph *G, int x)
{
    int cnt = 0;
    int i;
    for(i = 1 ; i<= G->n ; i++){
        if(G->A[i][x] == 1) //ajecent(G, i, x)
            cnt++;
    }
    return cnt;
}


void makenullList(List *L){
    L->Size = 0;
}

void pushback(List *L, int x){
    L->Data[L->Size] = x;
    L->Size ++;
}

int element_at(List *L, int i){
    return L->Data[i-1];
}

List neighbors(Graph *G, int x){
    List L;
    makenullList(&L);
    int i;
    for(i = 1; i<=G->n ; i++)
        if(G->A[i][x] == 1)
            pushback(&L,i);

    return L;
}

int main(){
        Graph G;
        freopen("graph.txt", "r", stdin);
        int n, m;
        scanf("%d%d",&n,&m);
        initGraph(&G,n);
        int x,y,e;
        for(e = 1; e<= m ;e++){
            scanf("%d%d",&x,&y);
            add_edge(&G,x,y);
        }

        int i, j;
        for(i = 1; i<G.n; i++){
            List L = neighbors(&G,i);
            printf("neighbors(%d) = [",i);
            for(j = 1; j<= L.Size ; j++){
                printf("%d, ",element_at(&L,j));
            }
            printf("]\n");
        }

        return 0;
}