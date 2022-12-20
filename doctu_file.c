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
	FILE* file = fopen("graph.txt","r");
	int n, m;
	fscanf(file,"%d%d", &n, &m);
	init_Graph(&G,n);
	int x,y,e;
	for(e = 1; e<=m; e++){
		fscanf(file,"%d%d",&x,&y);
		add_edge(&G,x,y);
	}
	
//	print_Graph(G, n);
//	printf("\n************\n");
//	int x;
//	scanf("%d",&x);
//	printf("So bac x la : %d ", degree(&G, x));
//	printf("\n************\n");
	int i;
	for(i =1 ; i<G.n ; i++){
		printf("degree (%d) = %d\n",i, degree(&G, i));
	}
//	fclose(file);
	return 0;

 }

