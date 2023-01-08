#include <stdio.h>

#define MAX_M 50

typedef struct{
    int u, v;
}Edge;

typedef struct 
{
    int n,m;
    Edge edges[MAX_M];
}Graph;

void init_graph(Graph *pG, int n){
    pG->n = n;
    pG->m = 0;
}

void add_edge(Graph *pG, int u, int v){
    pG->edges[pG->m].u = u;
    pG->edges[pG->m].v = v;
    pG->m ++;
}

int degree(Graph *pG, int u){
    int i, cnt = 0;
    for(i =0 ;i<pG->m ;i++){
        if(pG->edges[i].u == u)
            cnt++;
        if(pG->edges[i].v == u)
            cnt++;
    }
    return cnt;
}

int main(){
    Graph G;
    int n = 4, u;
    //Khởi tạo đồ thị
    init_graph(&G, n);
    //Thêm cung vào đồ thị
    add_edge(&G, 1, 2);
    add_edge(&G, 1, 3);
    add_edge(&G, 1, 3);
    add_edge(&G, 3, 4);
    add_edge(&G, 1, 4);

    //In bậc của các đỉnh
    for (u = 1; u <= n; u++)
        printf("deg(%d) = %d\n", u, degree(&G, u));
    return 0;
}