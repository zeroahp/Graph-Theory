#include <stdio.h>

#define Max_length 100
#define oo 9999999

typedef struct{
	int u,v,w;
}Edge;

typedef struct{
	Edge edges[Max_length];
	int n,m;
}Graph;

void init_graph(Graph *G, int n){
	G->n = n;
	G->m = 0;
}

void add_edge(Graph *G, int x, int y, int w){
	G->edges[G->m].u = x;
	G->edges[G->m].v = y;
	G->edges[G->m].w = w;
	G->m++;
}

int pi[Max_length], p[Max_length];
int chutrinham = 0;
void Bell_man(Graph *G, int s){
	
	pi[s] = 0;
	p[s] =-1;
	
	int i,j,u,v,w;
	for(i = 1 ; i< G->n ;i++){
		for(j = 0; j < G->m ;j++)//duyet qua cac cung
		{
			u = G->edges[j].u ;
			if(pi[u] == oo) continue;
			v = G->edges[j].v ;
			w = G->edges[j].w ;
			
			if(pi[u] + w < pi[v]){
				pi[v] = pi[u]+w;
				p[v] =u;
			}
		}
	}
	
	for(j = 0; j <G->m ;j++){
		u = G->edges[j].u ;
		if(pi[u] == oo) continue;
		v = G->edges[j].v ;
		w = G->edges[j].w ;
		
		if(pi[u] + w < pi[v]){
			chutrinham = 1;
			break;
		}
	}
}

int main(){
	Graph G;
	int n, m, u, v, w, e;
	scanf("%d%d", &n, &m);
	init_graph(&G, n);
	
	for (e = 0; e < m; e++) {
		scanf("%d%d%d", &u, &v, &w);
		add_edge(&G, u, v, w);
	}
	
	int i;
	for(i = 1 ; i <= G.n ; i++){
		pi[i] = oo;
		p[i] = 0;
	}
	
	//di tu dinh 1*******************
//	Bell_man(&G,1);
//	if(pi[n] == oo) printf("-1");
//	else printf("%d",pi[n]);
	
	//di tu dinh s -> t**************
	int s;
	scanf("%d",&s);
//	int t;
//	scanf("%d",&t);
	Bell_man(&G,s);
//	
//	if(pi[n] == oo) printf("-1");
//	else printf("%d",pi[t]);
	
	// in duong di tu s -> t********************
	
//	int path[Max_length], cnt = 0;
//	int temp = t;
//	while(temp != s){
//		path[cnt++] = temp;
//		temp = p[temp];
//	}
//	path[cnt] = s;
//	for(e = cnt; e>0 ;e--){
//		printf("%d -> ",path[e]);
//	}
//		printf("%d",path[0]);

	//kiem tra chu trinh am tu s -> n ***************
	
	if(chutrinham) printf("YES");
	else printf("NO");	
	
	
	return 0;
 }

