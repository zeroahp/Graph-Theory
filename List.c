#include <stdio.h>
#define Max_vertices 20
#define Max_length 20

typedef struct{
	int A[Max_vertices][Max_vertices];
	int n;
}Graph;

typedef struct {
	int A[Max_length];
	int size;
}List;

void makenullList(List *L){
	L->size = 0;
}

void push(List *L, int x){// them phan tu dinh vao cuoi danh sach
	L->A[L->size] = x;
	L->size ++;
}

int element_List(List *L, int i){//lay phan tu tai vi tri dinh 'i'
	return L->A[i-1];
}


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

List neighbors(Graph *G, int x){
	List L;
	makenullList(&L);
	int i;
	for(i = 1 ; i<=G->n ; i++){
		if(G->A[i][x] == 1)
			push(&L,i);
	}
	return L;
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

//	for(i = 1; i<=L.size ; i++){
//		printf("%d ", element_List(&L,i));
//	}

	int i, j;
	for(i = 1 ; i<=G.n ; i++){
		List L = neighbors(&G,i);
		printf("neighbor(%d) = [",i);
		for(j = 1; j<=L.size ; j++)
			printf("%d, ", element_List(&L,j));
		printf("]\n");
	}
	
	
//	int i;
//	for(i =1 ; i<G.n ; i++){
//		printf("degree (%d) = %d\n",i, degree(&G, i));
//	}
//	
	fclose(file);
	return 0;

 }

