#include <stdio.h>

#define Max_vertices 100
#define No_edge 0
#define red 1
#define blue 2
typedef struct{
	int A[Max_vertices][Max_vertices];
	int n,m;
}Graph;

void init_graph(Graph *G, int n)
{
	G->n = n;
	int i,j;
	for(i = 1; i <= G->n ; i++)
		for(j = 1; j <= G->n ;j++)
			G->A[i][j] = No_edge;
}

void add_edge(Graph *G, int x, int y){
	G->A[x][y] = 1;
	G->A[y][x] = 1;
	G->m++;
}

int color[Max_vertices] ;
int conflict = 0;

void DFS(Graph *G, int s, int c){
	color[s] = c;
	int v;
	for( v= 1 ; v<= G->n ; v++){
		if(G->A[s][v] != No_edge){
			if(color[v] == No_edge){
				DFS(G,v,3-c);
			}
			else if(color[v] == color[s]){
				conflict = 1;
				return;
			}
		}
		
	}
}
int main(){
	
	Graph G;
	int n, m, u, v,  e;
	scanf("%d%d", &n, &m);
	init_graph(&G, n);
		
	for (e = 0; e < m; e++) {
	    scanf("%d%d", &u, &v);
	    add_edge(&G, u, v);
	}
	
	int i;
	for(i = 1; i<= G.n ;i++){
		color[i] = No_edge;
	}
	
	for(i = 1; i<= G.n ;i++){
		if(color[i] == No_edge)
			DFS(&G,i,blue);
	}
	
//	if(conflict) printf("NO");
//	else printf("YES");

	if(conflict == 0) {
		for(i = 1; i <= G.n ;i++){
			if(color[i] == blue){
				printf("%d ",i);
			}
		}
		printf("\n");
		for(i = 1; i <= G.n ;i++){
			if(color[i] == red){
				printf("%d ",i);
			}
		}
	}else printf("IMPOSSIBLE");
	
	
	
	return 0;

 }

