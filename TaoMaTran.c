#include <stdio.h>

#define Max_vertices 20
typedef struct{
	int A[Max_vertices][Max_vertices];
	int n;
}Graph;

int main(){
	Graph G;
	G.n = 5;
	int i, j;
	printf("%d\n",G.n);
	for(i=0 ; i<G.n ; i++){
		for (j=0 ; j<G.n ; j++){
			G.A[i][j] = 0;
		}
	}
	for(i=0 ; i<G.n ; i++){
		for (j=0 ; j<G.n ; j++){
			printf("%d ",G.A[i][j]);
		}
		printf("\n");
	}
	

 }

