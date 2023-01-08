#include <stdio.h>
#define Max_vertices 20
#define Max_length 20
#define Max_element 40

typedef struct 
{
    int A[Max_vertices][Max_vertices];
    int n;
}Graph;

void initGraph(Graph *G, int n){
    G->n = n;
    int i, j;
    for(i = 1; i<=G->n ;i++){
        for(j = 1; j<= G->n ;j++){
            G->A[i][j] = 0;
        }
    }
}

void add_edge(Graph *G, int x, int y){
    G->A[x][y] = 1;
    G->A[y][x] = 1;
}

int adjacent(Graph *G, int x, int y){
    return G->A[x][y] != 0;
}

int degree(Graph *G, int x){
    int cnt = 0, i;
    for( i =1; i<= G->n ; i++){
        if(adjacent(G,i,x))
            cnt ++;
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

//Queue

typedef struct 
{
    int Data[Max_element];
    int Front;
    int Rear;
}Queue;

void makenullQueue(Queue *Q){
    Q->Front = 0;
    Q->Rear = -1;
}

void pushQueue(Queue *Q, int x){
    Q->Rear ++;
    Q->Data[Q->Rear] = x;
}

int emptyQueue(Queue *Q){
    return Q->Front > Q->Rear;
}

int topQueue(Queue *Q){
    return Q->Data[Q->Front];
}

void popQueue(Queue *Q){
    Q->Front ++;
}

List breath_first_search(Graph *G, int x){
    Queue Q;
    makenullQueue(&Q);
    List bfs ;
    makenullList(&bfs);
    int mark[Max_vertices]; 
    int i;
    for( i = 1; i<= G->n ;i++)
        mark[i] = 0;
    pushQueue(&Q, x);
    while(!emptyQueue(&Q))
    {
        int u = topQueue(&Q);
        popQueue(&Q);
        if(mark[u] == 1)
            continue;
        mark[u] = 1;
        // printf("Duyet : %d\n",u);
        push_List(&bfs,u);
        List L = neighbor(G,u);
        int j;
        for(j=1 ; j<= L.size ;j++){
            int v = element(&L,j);
            if(mark[v] == 0)
                pushQueue(&Q,v);
        }
    }
    return bfs;
}


int main(){
    Graph G;
    freopen("BFS.txt","r", stdin);
    int n, m;
    scanf("%d%d", &n, &m);
    initGraph(&G,n);
    int e, u, v;
    for(e = 1; e<= m ; e++){
        scanf("%d %d", &u, &v);
        add_edge(&G,u,v);
    }
    
    int mark_bfs[Max_vertices];
    int i;
    for(i =1; i<= G.n ; i++)
        mark_bfs[i] = 0;
    
    for(i =1; i<= G.n ; i++){
        if(mark_bfs[i] == 0){
            List bfs = breath_first_search(&G,i);
            int j, v;
            for(j = 1; j <= bfs.size ; j++){
                v = element(&bfs,j);
                printf("%d\n", v);
                mark_bfs[v] = 1;
            }
        }
    }

    return 0;
}