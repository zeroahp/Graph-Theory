#include <stdio.h>
#define No_edge -1
#define Max_length 100
#define oo 999999

typedef struct{
	int n,m;
	int A[Max_length][Max_length];
}Graph;

void init_graph(Graph *G, int n){
	G->n = n;
	G->m = 0;
	int i,j;
	for(i = 1 ; i <= G->n ; i++){
		for(j = 1; j <= G->n ;j++)
			G->A[i][j] = No_edge;
	}
}

void add_edge(Graph *G, int x, int y, int w){
	G->A[x][y] = w;
	G->m++;
}

int mark[Max_length], pi[Max_length], p[Max_length];

void Dijkstra(Graph *G, int s){
	
	int i,u,j;
	
	for(i = 1 ; i <= G->n; i++){
		mark[i] = 0;
		p[i] = -1;
		pi[i] = oo;
	}
	pi[s] = 0;
	p[s] = -1;
	
	
	for(i = 1 ; i< G->n ; i++){
		int min_pi = oo;
		for(j = 1; j <= G->n ;j++){
			if(!mark[j] && min_pi > pi[j]){
				min_pi = pi[j];
				u = j;
			}
		}
		
		mark[u] = 1;
		
		int v;
		for(v = 1; v <= G->n ; v++)
			if(!mark[v] && G->A[u][v] != No_edge)
				if(pi[u] + G->A[u][v] < pi[v]){
					pi[v] = pi[u] + G->A[u][v] ;
					p[v] = u;
				}
			
		
	}
	
}

int main(){
	Graph G;
    int n, m;
    scanf("%d%d", &m, &n);
    
	init_graph(&G, n*m);
    
    int i,u;
    for(i = 1; i <= n*m ; i++){
    	
		scanf("%d",&u);
    	if(i+n <= n*m) 
			add_edge(&G,i+n,i,u); //down
    	if(i > n) 
			add_edge(&G,i-n,i,u); //up
    	if(i % n != 1) 
			add_edge(&G,i-1,i,u);//left
    	if(i % n != 0) 
			add_edge(&G,i+1,i,u); //right 	
	}
	
	int j;
	for(j = 1 ; j <= n ; j++){
		mark[j] = 0;
		p[j] = -1;
		pi[j] = oo;
	} 
	
	Dijkstra(&G,1);
	
	printf("%d\n", pi[n*m]);
	
	return 0;
 }

