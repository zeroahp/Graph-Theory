#include <stdio.h>

#define Max_verricse 100
#define No_edge -9999
typedef struct{
	int A[Max_verricse][Max_verricse];
	int n,m;
}Graph;

void init_graph(Graph *G, int n){
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

int mark[Max_verricse] = {0};
int parent[Max_verricse] = {-1};
void BFS(Graph *G, int s, int p){
	int Queue[Max_verricse], front = 0, rear = 0;
	Queue[rear++] = s;
	parent[s] = p;
	while(front < rear){
		int u = Queue[front++];
		if(mark[u] == 1) continue;
		mark[u] = 1;
		printf("%d\n",u);
		int v;
		for( v= 1; v <=G->n ; v++){
			if(mark[v] == 0 && G->A[u][v] != No_edge)
			{
				if(parent[v] == -1)
					parent[v] = u;
				Queue[rear++] = v;
			}
		}
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
	//bat dau dinh 1
//	BFS(&G,1);
	
	//bat dau dinh s
//	int s;
//	scanf("%d",&s);
//	BFS(&G,s);
	// duyet toan bo do thi
	
	int i ;
//	for(i =1; i <= G.n ;i++){
//		if(!mark[i] ){
//			BFS(&G,i,-1);
//		}
//	}
	

	return 0;
 }

