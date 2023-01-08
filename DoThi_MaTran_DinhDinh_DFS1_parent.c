#include <stdio.h>
#define Max_vertices 20
#define Max_length 20
#define Max_Stack 40

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

void pushList(List *L, int x){
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
            pushList(&L,i);

    return L;
}

typedef struct 
{
    int Data[Max_Stack];
    int size;
}Stack;

void makenullStack(Stack *S){
    S->size = 0;
}

void push_stack(Stack *S, int x){
    S->Data[S->size] = x;
    S->size ++;
}

int top(Stack *S){
    return S->Data[S->size- 1];
}

void pop(Stack *S){
    S->size --;
}

int emptyStack(Stack *S){
    return S->size == 0;
}

List depth_first_search(Graph *G, int x, int parent[])
{
    Stack S;
    makenullStack(&S);
    push_stack(&S,x);
    parent[x] = 0;
    List dfs;
    makenullList(&dfs);
    int i;
    int mark[Max_vertices];
    for( i =1 ;i<=G->n ; i++)
        mark[i] = 0;
    while (!emptyStack(&S))
    {
        int u = top(&S);
        pop(&S);
        if(mark[u] != 0)
            continue;
        // printf("Duyet : %d\n", u);
        pushList(&dfs,u);
        mark[u] = 1;
        List L = neighbors(G,u);
        for(i=1; i<=L.Size;i++){
            int v = element_at(&L,i);
            if(mark[v] == 0){
                push_stack(&S,v);
                parent[v] = u;
            }
                
        }
    }
    return dfs;
}

int main(){
    Graph G;
    freopen("DFS.txt", "r", stdin);
    int n, m;
    scanf("%d%d",&n,&m);
    initGraph(&G,n);
    int x,y,e;
    for(e = 1; e<= m ;e++){
        scanf("%d%d",&x,&y);
        add_edge(&G,x,y);
    }
    
    int i, j;
    
    int mark_dfs[Max_vertices];
    for(i = 1; i<= G.n ; i++)
        mark_dfs[i] = 0;
   
    int parent[Max_vertices];
    for(j =0;j<G.n;j++)
        parent[j] = -1;
    for(i = 1; i<= G.n ; i++){
        if(mark_dfs[i] == 0){
            List dfs = depth_first_search(&G,i, parent);
            for(j = 1; j<= dfs.Size ; j++){
                int k = element_at(&dfs,j);
                // printf("%d\n",k);
                mark_dfs[k] = 1;
            }
        }     
    }
    for(i = 1; i <= G.n ;i++)
        printf("%d %d\n",i,parent[i]);
        
    return 0;
}