#include <stdio.h>

#define Max_length 100
#define oo 9999999
#define No_edge -1

typedef struct{
	int n,m;
	int A[Max_length][Max_length];
}Graph;

void init_graph(Graph *G, int n){
	int i,j;
	G->n = n;
	for(i = 1; i <= G->n ; i++)
		for(j = 1 ; j <= G->n ; j++)
			G->A[i][j] = No_edge;
}

void add_edge(Graph *G, int x, int y, int w){
	G->A[x][y] = w;
	G->A[y][x] = w; //vo huong
	G->m++;
}

int mark[Max_length];
int pi[Max_length],p[Max_length];

void Dijkstra(Graph *G, int s){
	
	pi[s] = 0;
	p[s] = -1;
	
	int i,j , u;
	for(i = 1; i<G->n ; i++){
		int min_pi = oo;
		for(j = 1; j <= G->n ;j++){
			if(mark[j] == 0 && pi[j] < min_pi){
				
				min_pi = pi[j];
				u = j;
			}
		}
		mark[u] = 1;
		int v;
		for(v= 1 ; v<= G->n ;v++){
			if(G->A[u][v] != No_edge && mark[v] == 0){
				if(pi[u] + G->A[u][v] < pi[v]){
					
					pi[v] = pi[u] + G->A[u][v];
					p[v] = u;
				}
			}
		}
	}
}

int main(){
	Graph G;
	int n,m;
	scanf("%d %d",&n,&m);
	init_graph(&G,n);
	int i,y,x,w;
	for(i = 0; i <m ;i++){
		scanf("%d%d%d",&x,&y,&w);
		add_edge(&G,x,y,w);
	}	
	
	int j;
	for(j = 1; j <= G.n ; j++){
		pi[j] = oo;
		p[j] = -1;
		mark[j] = 0;
	}
	
//	Dijkstra(&G,1);
	
	//********in duong di ngan nhat**************

	if(pi[n] == oo) printf("-1");
	else printf("%d",pi[n]);
	
	//*********in p[i] & pi[i]******************

	for(j = 1; j <= G.n ; j++){
		printf("pi[%d] = %d, p[%d] = %d\n",j,pi[j],j,p[j]);
	}
	
	//********di tu s->t*************************

	int s,t;
	scanf("%d%d",&s,&t);
	Dijkstra(&G,s);
	
	int temp = t;
	int path[Max_length], cnt = 0;
	while(temp != s){
		path[cnt++] = temp;
		temp = p[temp];
	}
	path[cnt] = s;
	for(j = cnt; j>0 ;j--){
		printf("%d -> ",path[j]);
	}
	printf("%d",path[0]);
	
	
	return 0;
}
