#include <stdio.h>

#define Max_vertices 100
#define Max_Queue 100
#define Max_List 100

typedef struct 
{
    int A[Max_vertices][Max_vertices];
    int n,m;
}Graph;

void initGraph(Graph *G, int n){
    G->n = n;
    int i,j;
    for(i = 1; i <= G->n ; i++)
        for(j = 1 ; j <= G->n ; j++)
            G->A[i][j] = 0;
}

void add_edge(Graph *G, int x, int y){
    G->A[x][y] = 1;
    G->m++;
}

int adjacent(Graph *G, int x, int y){
    return G->A[x][y] == 1;
}

typedef struct 
{
    int front, rear;
    int data[Max_Queue];
}Queue;

void makenullQueue(Queue *Q){
    Q->front = 0;
    Q->rear = -1;
}

void enQueue(Queue *Q, int x){
    Q->rear++;
    Q->data[Q->rear] = x;
}

void deQueue(Queue *Q){
    Q->front++;
}

int front(Queue *Q){
    return Q->data[Q->front];
}

int emptyQueue(Queue *Q){
    return Q->front > Q->rear;
}

typedef struct 
{
    int Element[Max_List];
    int size;
}List;

void makenullList(List *L){
    L->size = 0;
}

int emptyList(List *L){
    return L->size == 0;
}

void push_back(List *L, int x){
    L->Element[L->size++] = x;
}

int elements(List *L, int i){
    return L->Element[i-1];
}

void topo_sort(Graph *G, List *L){
    int d[Max_vertices];
    int i,x;
    for(i = 1; i <= G->n ; i++){
        d[i] = 0;
        for(x = 1 ; x <= G->n ;x++){
            if(G->A[x][i] != 0)
                d[i]++;
        }
    }

    Queue Q;
    makenullQueue(&Q);
    //dua d[u] = 0 vao hang doi
    for(i = 1; i <= G->n ; i++)
        if(d[i] == 0)
            enQueue(&Q,i);

    makenullList(L);
    while (!emptyQueue(&Q))
    {
        int u = front(&Q);
        deQueue(&Q);
        push_back(L,u);
        int v;
        for(v=1 ; v<=G->n ;v++){
            if(adjacent(G,u,v)){
                d[v] --;
                if(d[v] == 0)
                    enQueue(&Q,v);
            }

        }
    }
    
}

int main(){
    Graph G;
    int n, m;
    scanf("%d %d", &n, &m);
    initGraph(&G,n);
    int u, v, i;
    for(i = 1 ; i <= m ; i++){
        scanf("%d %d", &u, &v);
        add_edge(&G,u,v);
    }
    
    List L;
    topo_sort(&G,&L);

    for(i = 0 ;i <L.size ; i++){
        printf("%d\n",L.Element[i]);
    }


    return 0;
}