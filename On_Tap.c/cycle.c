#include <stdio.h>

#define Max_vertices 100
#define INF -999
#define white 0
#define gray 1
#define black 2

typedef struct{
	int A[Max_vertices][Max_vertices];
	int n,m;
}Graph;

void init_graph(Graph *G, int n){
    G->n = n;
    int i, j;
    for(i = 1 ; i <= G->n ; i++)
        for(j = 1; j <= G->n ; j++)
            G->A[i][j] = white;
    
}

void add_edge(Graph *G, int x, int y){
    G->A[x][y] = 1;
     G->A[y][x] = 1;
    G->m ++;
}

int has_circle = 0;
int color[Max_vertices] = {0};
int parent[Max_vertices] = {-1};
int start,end;
void DFS(Graph *G, int s, int p){
	
	color[s] = gray;
	int v;
	parent[s] = p;
	for( v= 1 ; v<= G->n ; v++){
		if(G->A[s][v] != white){
			if( v == p) continue;
			if(!color[v])
				DFS(G,v,s);
			else if(color[v] == gray){
				has_circle =1;
				start = s;
				end = v;
			}
		}
	}
}
int main(){
	Graph G;
	int n,m;
	scanf("%d%d",&n,&m);
	int i,x,y;
	init_graph(&G,n);
	for(i = 0 ; i < m ;i++){
		scanf("%d%d",&x,&y);
		add_edge(&G,x,y);
	}
	
	int j;
	for(j = 1; j <= G.n ; j++){
		if(!color[j])
			DFS(&G,j,-1);
	}
	
//	if(has_circle) printf("CIRCLED");
//	else printf("NO CIRCLE");
	int A[Max_vertices], a,b,cnt;
	if(has_circle){
		A[0] = start, a = start, b = end, cnt = 1;
		do{
			a = parent[a];
			A[cnt++] = a;
		}while(a != b);
	}
	
	if(has_circle){
		while(cnt--){
			printf("%d ",A[cnt]);
		}
		printf("%d",b);
	} else printf("-1");
	
	return 0;

 }

