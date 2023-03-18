#include <stdio.h>

#define Max_vertices 100
#define Max_Queue 100
#define Max_List 100
int indegree[Max_vertices];
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
    indegree[y] ++;
}

int adjacent(Graph *G, int x, int y){
    return G->A[x][y] == 1;
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
//luu hang cac dinh

int r[Max_vertices];
void rank(Graph *G){

    List L1, L2;
    int i;
    //tim goc dua va L1
    makenullList(&L1);
    for(i = 1 ; i <= G->n ;i++)
        if(!indegree[i])
            push_back(&L1,i);

    int k = 0;//hang
   
    //lap den khi L1 rong thi dung
    while (!emptyList(&L1))
    {
        makenullList(&L2);
        int j;
        for(j = 1; j <=L1.size ; j++){//sd element cho i =1
            
            int u = elements(&L1,j); 
            r[u] = k;

            int v;
            for(v = 1; v <= G->n ; v++){
                if(adjacent(G,u,v)){
                    indegree[v]--;
                    if(!indegree[v])
                        push_back(&L2,v);
                }
            }
        }
        k++;
        copy_List(&L1,&L2);
        
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

    rank(&G);

    for(i = 1 ;i <=G.n; i++){
        printf("r[%d] = %d\n",i,r[i]);
    }


    return 0;
}