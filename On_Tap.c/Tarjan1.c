#include <stdio.h>
#include <math.h>

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
// 	G->A[y][x] = 1;
	G->m++;
}


int num[Max_vertices], min_num[Max_vertices], k,size =0;
int On_stack[Max_vertices], stack[Max_vertices];
int check = 0, cnt = 0, max =0;

void Tarjan(Graph *G, int u){
	num[u] = min_num[u] = k++;
	On_stack[u] = 1;
	stack[size++] = u;
	
	int v;
	for( v= 1 ; v <= G->n ; v++){
		if(G->A[u][v] != No_edge){
			if(num[v] < 0){
				Tarjan(G,v);
				min_num[u] = fmin(min_num[u], min_num[v]);
			}
			else if(On_stack[v]){
				min_num[u] = fmin(min_num[u],num[v]);
			}
		}
	}
	
	if(num[u] == min_num[u]){
		int w;
		check++;
		do{
			w = stack[--size];
			cnt++;
			On_stack[w] = 0;
			
		}while(w != u);
		if(max < cnt)
			max = cnt;
		cnt = 0;
//	printf("%d ", cnt);
	}

}


int main(){
	Graph G;
	int n, m, u, v, e;
	scanf("%d%d", &n, &m);
	init_graph(&G, n);
	
	for (e = 0; e < m; e++) {
	    scanf("%d%d", &u, &v);
	    add_edge(&G, u, v);
	}
	
	int i;
	for( i = 1 ; i <= G.n ;i++){
		num[i] = -1;		
	}
	k = 1;
	for( i = 1 ; i <= G.n ;i++)
		if(num[i] == -1)
			Tarjan(&G,i);
	
	
//	for( i = 1 ; i <= G.n ;i++){
//		printf("%d %d\n",num[i],min_num[i]);
//	}
	
	 printf("%d", max);
//	else printf("DISCONNECTED");

	
	return 0;

 }

