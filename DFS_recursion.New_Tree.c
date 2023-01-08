#include <stdio.h>

#define Max_vertices 20
#define Max_length 20

typedef struct 
{
    int A[Max_vertices][Max_vertices];
    int n;
}Graph;

void initGraph(Graph *G, int n){
    G->n = n;
    int i, j;
    for(i = 1; i<=G->n ; i++){
        for(j = 1; j<=G->n ; j++){
            G->A[i][j] = 0;
        }
    }
}

void add_edge(Graph *G, int x, int y){
    G->A[x][y] = 1;
    G->A[y][x] = 1;
}

int adjacent(Graph *G, int x, int y){
    return G->A[x][y] == 1;
}

int degree(Graph *G, int x){
    int i, cnt = 0;
    for(i =1; i<=G->n ; i++){
        if(adjacent(G,i,x))
            cnt++;
    }
    return cnt;
}

typedef struct 
{
    int data[Max_length];
    int size;
}List;

void makenullList(List *L){
    L->size = 0;
}

void push_List(List *L, int x){
    L->data[L->size] = x;
    L->size ++;
}

int element(List *L, int i){
    return L->data[i - 1];
}

List neighbor(Graph *G, int x){
    List L;
    makenullList(&L);
    int i;
    for(i = 1; i<= G->n ; i++){
        if(G->A[i][x])
            push_List(&L,i);
    }
    return L;
}

int mark[Max_vertices];
int parent[Max_vertices];
void DFS_Recursion(Graph *G, int u, int p){
    if(mark[u] == 1)
        return;
    printf("Duyet : %d\n",u);
    parent[u] = p;
    mark[u] =1;
    List L = neighbor(G,u);
    int i;
    for(i = 1; i<=L.size; i++){
        int v = element(&L,i);
        DFS_Recursion(G,v,u);
    }

}

int main(){
    Graph G;
    freopen("DFS_Recursion.txt","r", stdin);
    int n,m;
    scanf("%d %d", &n, &m);
    initGraph(&G,n);
    int i, u,v;
    for(i = 1; i <= m ;i++){
        scanf("%d %d",&u,&v);
        add_edge(&G,u,v);
    }

    for(i = 1; i<= G.n ;i ++){
        mark[i] = 0;
        parent[i] = -1;
    }

    for(i = 1; i<= G.n ;i ++){
        if(mark[i] == 0)
            DFS_Recursion(&G,i,0);   
    }
    
    // for(i = 1; i<= n ;i ++)
    //     printf("%d %d\n",i,parent[i]);
    return 0;
}
