#include <stdio.h>

#define Max_vertices 20
typedef struct{
	int A[Max_vertices][Max_vertices];
	int n;
}Graph;

void init_Graph(Graph *G, int n){
	int i, j;
	G->n = n;
	printf("%d\n",G->n);
	for(i=1 ; i<=G->n ; i++){
		for (j=1 ; j<=G->n ; j++){
			G->A[i][j] = 0;
		}
	}
}

void print_Graph(Graph G, int n){
	int i, j;
	for(i=1 ; i<=G.n ; i++){
		for (j=1 ; j<=G.n ; j++){
			printf("%d ",G.A[i][j]);
		}
		printf("\n");
	}
}


int main(){
	Graph G;
	int n;
	init_Graph(&G,5);
	G.A[1][1] = 1;
	G.A[1][3] = 1;
	print_Graph(G,n);
	return 0;
 }

