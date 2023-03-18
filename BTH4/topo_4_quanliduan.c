#include <stdio.h>

#define Max_vertices 100
#define Max_Queue 100
#define Max_List 100
#define oo 9999999
int bac_vao[Max_vertices], bac_ra[Max_vertices];

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
    bac_vao[y]++;
    bac_ra[x]--;
}

int adjacent(Graph *G, int x, int y){
    return G->A[x][y] > 0;
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

void copy_List(List *L2, List *L1){
    makenullList(L2);
    int i;
    for( i=1 ; i <= L1->size ; i++)
        push_back(L2,elements(L1,i));
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


void topo_sort(Graph *G, List *L){
    
    Queue Q;
    makenullQueue(&Q);
    //dua d[u] = 0 vao hang doi
    int i;
    for(i = 1; i <= G->n ; i++)
        if(bac_vao[i] == 0)
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
                bac_vao[v] --;
                if(bac_vao[v] == 0)
                    enQueue(&Q,v);
            }

        }
    }
    
}

int max(int a, int b){
    return (a>b)?a:b;
}

int min(int a, int b){
    return (a<b)?a:b;
}

int main(){
    Graph G;
    int n;
    scanf("%d", &n);
    initGraph(&G,n+2);
    int d[Max_vertices];
    int alpha = n+1, beta = n+2;
    d[alpha] = 0;

    int u, x, i;
    //doc danh sach cong viec
    for(u = 1 ; u <= n ; u++){
        scanf("%d", &d[u]);
        do{
            scanf("%d",&x);
            if(x>0)
                add_edge(&G,x,u);
        }while(x>0);
    }
    //them cung noi alpha cac dinh bac vao = 0
    int w;
    int v;
    //them cung noi beta cac dinh bac ra = 0
    for(i = 1 ;i <= G.n-2 ; i++){
        if(!bac_vao[i]) add_edge(&G,alpha,i);
        if(!bac_ra[i]) add_edge(&G,i,beta);
    }

    //xep thu tu theo giai thuat sap xep topo
    List L;
    topo_sort(&G,&L);
    
    //tinh t[u]
    int t[Max_vertices];
    t[alpha] = 0;

    for(i = 2; i <= L.size ;i++){
        int a = elements(&L,i);
        t[a] = -oo;
        for(w = 1; w <= G.n ;w++){
            if(G.A[w][a] > 0)
                t[a] = max(t[a],(t[w] + d[w]));
        }
    }

    //tinh T[u]
    int j,T[Max_vertices];
    T[beta] = t[beta];

    for(j = L.size-1; j >= 1 ; j--){
        int b = elements(&L,j);
        T[b] = oo;
        for(v = 1; v<=G.n ;v++){
            if(G.A[b][v] > 0)
                T[b] = min(T[b],(T[v]- d[b]));
        }
    }

    int e;
    for( e = 1 ; e <= n ; e++ ){
        printf("%d %d\n",t[e],T[e]);
    }
  
    return 0;
}
/*
10
7 0
3 1 0
1 2 0
8 1 0
2 3 4 0
1 3 4 0
1 3 4 0
2 6 0
2 8 0
1 5 7 9 0
*/