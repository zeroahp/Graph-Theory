#include <stdio.h>

#define Max_vertices 100
#define No_edge -999

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

int mark[Max_vertices] = {0};
int parent[Max_vertices] = {-1};
void DFS(Graph *G, int s, int p){
	if(mark[s] ==1 )
		return;
	printf("%d\n",s);
	mark[s] = 1;
	parent[s] = p;
	int v;
	for(v = 1; v <=G->n ;v++){
		if(!mark[v] && G->A[s][v] != No_edge)
			DFS(G,v,s);
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
	
	
	int s;
	scanf("%d",&s);

	DFS(&G,s,-1);

 }

