#include <stdio.h>

#define Max_vertices 100
#define No_Edge -99999
#define oo 99999

typedef struct 
{
    int A[Max_vertices][Max_vertices];
    int n,m;
}Graph;

void init_graph(Graph *G, int n){
    int i, j;
    G->n = n;
    for(i = 1; i <= G->n ; i++){
        for(j = 1 ; j <= G->n ; j++)
            G->A[i][j] = No_Edge;
    }
}


void add_edge(Graph *G, int x, int y, int w){
    G->A[x][y] = w;
    G->m ++;
}

int pi[Max_vertices][Max_vertices], next[Max_vertices][Max_vertices];
int negative_cycle = 0;

void Floyd_Warshall(Graph *G){
    int i,j,k;

    for(i = 1 ; i <= G->n ; i++){
        pi[i][i] = 0;
        for(j = 1 ; j <= G->n ; j++){
            if(G->A[i][j] != No_Edge){
                pi[i][j] = G->A[i][j];
                next[i][j] = j;
            }
        }
    }

    for(i = 1 ; i <= G->n ; i++){
        for(j = 1 ; j <= G->n ; j++){
            if(pi[j][i] == oo) continue;
            for(k = 1; k <= G->n; k++){
                if(pi[i][k] == oo) continue;
                if(pi[j][i] + pi[i][k] < pi[j][k]){
                    pi[j][k] = pi[j][i] + pi[i][k] ;
                    next[j][k] = next[j][i];
                }
            }

        }  
    }
    for(i = 1; i <= G->n ; i++){
            if(pi[i][i] < 0){
                negative_cycle = 1;
                break;
            }
        }
}
int main(){
    Graph G;
    int n, m,x,y,w, e;
    scanf("%d%d", &n, &m);
    init_graph(&G, n);
    
    for (e = 0; e < m; e++) {
        scanf("%d %d %d", &x, &y, &w);
        add_edge(&G, x, y, w);
    }

    int i, j;

    for(i = 1 ; i <= G.n ; i++){
        for(j = 1 ; j <= G.n ; j++){
            pi[i][j] = oo;
            next[i][j] = -1;
        }
    }

    Floyd_Warshall(&G);

    if(negative_cycle == 1) printf("YES");
    else printf("NO");

    return 0;
}