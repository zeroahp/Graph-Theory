#include <stdio.h>

#define Max_length 50

typedef struct {
    int A[100][500];
    int n, m;
} Graph;

void init_graph(Graph *G, int n, int m){
    int u, i;
    G->n = n;
    G->m = m;
    for(u=1; u<= G->n ;u++){
        for(I=1;i<=m;i++){
            G->A[u][i] = 0;
        }
    }

}
void add_edge(Graph* pG, int e, int x, int y) {
    pG->A[x][e] = 1;
    pG->A[y][e] = 1;
}

int deg(Graph *G, int u){
    int i, cnt = 0;
    for ( i = 1; i <= G->m; i++)
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
    make_null(&L);
    int i, j;
    for( i = 1; i<=G->n ;i++){
        if(u == i) continue;
        for(j = 1 ; j<=G->m ;j++){
            if(G->A[u][j] != 0 && G->A[i][j] != 0){
                push_back(&L,i);
                break;
            }
        }
    }
    return L;

}



int main(){


    return 0;
}