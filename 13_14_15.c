#include <stdio.h>

#define MAX_N 100

typedef struct 
{
    int n,m;
    int A[MAX_N][MAX_N];
}Graph;

void init_graph(Graph *G, int n){
    G->n = n;
    G->m = 0;
    int i, j;
    for(i = 0; i< G->n ;i++){
        for(j =0 ;j<G->n ; j++){
            G->A[i][j] = 0;
        }
    }
}

void add_edge(Graph *G, int u, int v){
    G->A[u][v] = 1;
    G->m ++;
}

// vo huong
// int main(){
//     int n;
//     Graph G;
//     scanf("%d", &n);
//     G.n = n;
//     int i, j;
//     for(i = 1 ; i <= G.n ;i++){
//         for(j=1 ; j<=G.n ;j++){
//             scanf("%d",&G.A[i][j]);
//         }
//     }
//     int e;
//     for(i = 1 ; i <= G.n ;i++){
//         for(j=i ; j<=G.n ;j++){
//             for(e = 1; e<= G.A[i][j] ;e++)
//                 printf("%d %d\n", i, j);
//         }
//     }
    
//     return 0;
// }

//co huong
// int main(){
//     Graph G;
//     int n; 
//     scanf("%d",&n);
//     int i,j;
//     for ( i = 1; i <= n ; i++)
//     {
//         for (j = 1; j<= n; j++)
//         {
//             scanf("%d",&G.A[i][j]);
//         } 
//     }
//     int e;
//     for ( i = 1; i <= n ; i++)
//     {
//         for (j = 1; j<= n; j++)
//         {
//             for( e=1 ; e<=G.A[i][j] ; e++){
//                 printf("%d %d\n",i,j);
//             }
//         } 
//     }
    

//     return 0;
// }

//in danh sach ke
// void neighbours(Graph *G, int u){
//     int i,j;
//     for(i=1 ; i<= G->n;i++){
//         for( j = 1; j<=G->A[u][i] ;j++)
//             printf("%d ", i);
//     }
// }

// int main(){

//     Graph G;
//     int n;
//     scanf("%d",&n);
//     init_graph(&G, n);
//     int i,j;
//     for ( i = 1; i <= n ; i++)
//     {
//         for (j = 1; j<= n; j++)
//         {
//             scanf("%d",&G.A[i][j]);
//         } 
//     }

//     for(i = 1 ; i<=n ;i++){
//         neighbours(&G,i);
//         printf("0\n");
//     }


//     return 0;
// }

//đồ thị có hướng in danh sach ke y chang tren

int main(){
    Graph G;
    int n;
    scanf("%d", &n);
    init_graph(&G,n);
    int i, j;
    
    int x;
    for( i = 1; i<= n; i++){
        do{
            scanf("%d",&x);
            G.A[i][x]++;
        }
        while(x != 0);
    }

    for(i = 1; i<= G.n ; i++){
        for (j = 1; j <= G.n; j++)
        {
            printf("%d ",G.A[i][j]);
        }
        printf("\n");
    }
    


    return 0;
}


