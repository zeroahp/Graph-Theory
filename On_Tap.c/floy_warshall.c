#include <stdio.h>

#define Max_length 100
#define oo 9999999
#define No_edge -9999

typedef struct{
	int A[Max_length][Max_length];
	int n,m;
}Graph;

void init_graph(Graph *G, int n){
	int i,j;
	G->n = n;
	for(i = 1; i <= G->n ;i++){
		for(j = 1; j <= G->n ; j++)
			G->A[i][j] = No_edge;
	}
}

void add_edge(Graph *G, int x, int y, int w){
	G->A[x][y] = w;
	G->m++;
}

int pi[Max_length][Max_length];
int next[Max_length][Max_length];
int negative_cycle = 0;

void floy_warshall(Graph *G){
	
	int u,v,k;
	for(u = 1; u <= G->n ; u++)
		pi[u][u] = 0;
	
	for(u = 1; u <= G->n ; u++)
		for(v = 1; v <= G->n ; v++){
			if(G->A[u][v] != No_edge){
				pi[u][v] = G->A[u][v];
				next[u][v] = v;
			}
		}
		
	for(k = 1 ; k <= G->n ; k++){
		for(u = 1; u <= G->n ; u++){
			if(pi[u][k] == oo) continue;
			for(v = 1; v <= G->n ; v++){
				if(pi[k][v] == oo) continue;
				if(pi[u][k] + pi[k][v] < pi[u][v]){
					pi[u][v] = pi[u][k] + pi[k][v];
					next[u][v] = next[u][k];
				}
			}

		}
	}
	
	for(u = 1; u <= G->n ; u++)
		if(pi[u][u] < 0){
			negative_cycle = 1;
			break;
		}		
	
	
}
int main(){

	Graph G;
	int n,m;
	scanf("%d%d",&n,&m);
	init_graph(&G,n);
	int i,j,x,y,w;
	for(i = 0; i<m;i++){
		scanf("%d%d%d",&x,&y,&w);
		add_edge(&G,x,y,w);
	}
	
	for(i = 1; i <= G.n ;i++){
		for(j = 1; j <= G.n ;j++){
			pi[i][j] = oo;
			next[i][j] = -1;
		}
	}
	
	floy_warshall(&G);
	
//	//in chieu dai
//	for(i = 1; i <= G.n ;i++){
//		for(j = 1; j <= G.n ;j++)
//		if(pi[i][j] != oo)
//			printf("%d -> %d: %d\n",i,j,pi[i][j]);
//		else 
//			printf("%d -> %d: NO PATH\n",i,j);
//	}
//	
//	//in duong di
//	for(i = 1; i <= G.n ;i++)
//		for(j = 1; j <= G.n ;j++){
//			if(pi[i][j] == oo) printf("path(%d, %d): NO PATH\n",i,j);
//			else {
//				printf("path(%d, %d): %d",i,j,i);
//				int s = i;
//				while(s != j){
//					s = next[s][j];
//					printf(" -> %d",s);
//				}
//				printf("\n");
//			}
//		}
//	
	//kiem tra chu trinh am
	if(negative_cycle ) printf("YES");
	else printf("NO");
	
	return 0;

 }

