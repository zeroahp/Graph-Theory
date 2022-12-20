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

int degree(Graph *G, int x){
	int i, cnt = 0;
	for(i = 1; i<=G->n ; i ++){
		if(G->A[i][x] == 1)
			cnt ++;
	}
	return cnt;
}

int main(){
	Graph G;
	int n;
	scanf("%d", &n);
	init_Graph(&G,n);
	print_Graph(G, n);
	printf("\n************\n");
	add_edge(&G,2,6);
	add_edge(&G,6,4);
	add_edge(&G,5,6);
	add_edge(&G,1,4);
	add_edge(&G,1,5);
	add_edge(&G,2,3);
	add_edge(&G,2,4);
	add_edge(&G,4,5);
	print_Graph(G, n);
//	int x;
//	scanf("%d",&x);
//	printf("So bac x la : %d ", degree(&G, x));
	printf("\n************\n");

	int i;
	for(i =1 ; i<G.n ; i++){
		printf("degree (%d) = %d\n",i, degree(&G, i));
	}

	return 0;

 }

