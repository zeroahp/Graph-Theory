#include <stdio.h>
#define Max_vertices 20

typedef struct{
	int A[Max_vertices][Max_vertices];
	int n;
}Graph;

void init_Graph(Graph *G, int n){
	int i,j;
	G->n = n;
	for(i = 1 ; i<=G->n ; i++){
		for(j = 1; j<=G->n ; j++){
			G->A[i][j] = 0;
		}
	}
}
 
void print_Graph(Graph G, int n){
	int i,j;
	for(i = 1 ; i<=G.n ; i++){
		for(j = 1; j<=G.n ; j++){
			printf("%d ",G.A[i][j]);
		}
		printf("\n");
	}
}

void add_edge(Graph *G, int x, int y) // Them o bang 1;
{
	G->A[x][y] = 1;
	G->A[y][x] = 1;
}

int adjacent(Graph *G, int x, int y){
	return (G->A[x][y] != 0);
}


int main(){
	Graph G;
	int n;
	scanf("%d", &n);
	init_Graph(&G,n);
//	print_Graph(G, n);
//	printf("*********\n");
	add_edge(&G,1,1);
	printf("%d",adjacent(&G,1,4));
	return 0;

 }

