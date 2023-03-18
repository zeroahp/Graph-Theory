#include <stdio.h>

#define Max_vertices 100
#define Max_queue 100
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
    // G->A[y][x] = 1;
    G->m ++;
}

int adjacent(Graph *G, int x, int y){
    return G->A[x][y] == 1;
}

typedef struct
{
    int data[Max_queue];
    int front,rear;
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
    return Q->front >Q->rear;
}

int mark[Max_vertices],parent[Max_vertices];

void BFS(Graph *G, int u, int mark[], int parent[], int p){
    Queue Q;
    makenullQueue(&Q);
    enQueue(&Q,u);
    parent[u] = p;
    while (!emptyQueue(&Q))
    {
        int v = front(&Q); deQueue(&Q);
        if(mark[v] != 0) continue;
        mark[v] = 1;
        int i;
        for(i = 1 ; i <= G->n ; i++){
            if(adjacent(G,v,i)){
                if(mark[i] == 0){
                    if(parent[i] == -1)
                        parent[i] = v;
                    enQueue(&Q,i);
                }
            }
        }
    }   
}


int main(){
    // freopen("dt.txt", "r", stdin); //Khi nộp bài nhớ bỏ dòng này.
    Graph G;
    int n, m, u, v, w, e;
    scanf("%d%d", &n, &m);
    init_graph(&G, n);

    for (e = 0; e < m; e++) {
        scanf("%d%d", &u, &v);
        add_edge(&G, u, v);
    }

    for(w = 1; w <= n ; w++){
        mark[w] = 0;
        parent[w] = -1;
    }

    for(w = 1; w <= n ; w++){
        if(mark[w] == 0)
            BFS(&G,w,mark,parent,-1);
    }

    for(w = 1; w <= n ; w++){
        printf("%d %d\n",w, parent[w]);
    }

    return 0;
}