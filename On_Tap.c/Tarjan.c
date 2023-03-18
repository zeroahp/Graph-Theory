#include <stdio.h>
    // do thi vo huong

#define Max_vertices 100
#define Max_stack 100

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
    int data[Max_stack];
    int top_idx;
}stack;

void makenullStack(stack *S){
    S->top_idx = -1;
}

int emptyStack(stack *S){
    return S->top_idx == -1;
}

void push(stack *S, int x){
    S->top_idx++;
    S->data[S->top_idx] = x;
}

void pop(stack *S){
    S->top_idx--;
}

int top(stack *S){
    return S->data[S->top_idx];
}

int min(int a, int b){
    return (a>b)?b:a;
}
int num[Max_vertices], min_num[Max_vertices], k ;
stack S;
int On_stack[Max_vertices], check = 0, cnt = 0, max = 0;

void Tarjan(Graph *G, int u){
    num[u] = min_num[u] = k++;
    push(&S,u);
    On_stack[u] = 1;
    int v; 
    for( v = 1; v <= G->n ; v++){
        if(adjacent(G,u,v)){
            if(num[v] < 0){
                Tarjan(G,v);
                min_num[u] = min(min_num[u],min_num[v]);
            }else if( On_stack[v] == 1){
                min_num[u] = min(min_num[u],num[v]);
            }
        }
    }
    if(num[u] == min_num[u]){
        int w;
        check++;
        do{
            w = top(&S);
            cnt++;
            pop(&S);
            On_stack[w] = 0;
        }while (w != u);   
        if(max < cnt)
            max = cnt;   
        cnt = 0; 
    }
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

    int i;
    for( i = 1 ; i<= G.n ; i++){
        num[i] = -1;
    }
    makenullStack(&S);
    k = 1;

    for( i = 1 ; i<= G.n ; i++){
        if(num[i] == -1)
            Tarjan(&G,i);
    }

    //1- IN RA NUM[] VA MIN_NUM[]
    for( i = 1 ; i<= G.n ; i++){
        printf("%d %d\n",num[i],min_num[i]);
    }

    //2 - KIEM TRA LIEN THONG MANH
    if(check==1) printf("STRONG CONNECTED");
    else printf("DISCONNECTED");

    //3 - DEM SO BO PHAN LIEN THONG MANH
    if(check) printf("%d", check);

    //4 - BO PHAN LIEN THONG MANH CO NHIEU DINH NHAT
    printf("%d", max);

    return 0;
}