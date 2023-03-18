#include <stdio.h>
//DO THI VO HUONG

/*Mỗi đỉnh sẽ có 1 trong 3 trạng thái ứng với 3 màu:
- Chưa có màu: NO_COLOR
- Được tô màu xanh: BLUE
- Được tô màu đỏ: RED
Thuật toán duyệt đồ thị đệ quy kết hợp tô màu colorize(u, c) gồm các bước sau
- Tô màu c cho u
- Xét các đỉnh kề v của u, có 3 trường hợp:
o Nếu v chưa có màu => Gọi đệ quy tô màu ngược lại với c cho nó
o Nếu v đã có màu và giống màu với u => đụng độ, không tô được
o Nếu v đã có màu và khác màu với u => bỏ qua*/

#define No_color 0
#define red 1
#define blue 2
#define Max_vertices 100
typedef struct 
{
    int A[Max_vertices][Max_vertices];
    int n,m;
}Graph;

void init_graph(Graph *G, int n){
    G->n = n;
    int i, j;
    for( i = 1 ; i <= G->n ; i++)
        for( j = 1 ; j <= G->n ; j++)
            G->A[i][j] = 0;
}

void add_edge(Graph *G, int x, int y){
    G->A[x][y] = 1;
    G->A[y][x] = 1;
    G->m++;
}

int adjacent(Graph *G, int x, int y){
    return G->A[x][y] == 1;
}

int color[Max_vertices], conflict = 0;

void DFS(Graph *G, int u, int c){
    color[u] = c;
    int v;
    for(v = 1 ; v <= G->n ; v++){
        if(adjacent(G,u,v)){
            if(color[v] == No_color)
                DFS(G,v,3-c);
            else if(color[v] == color[u]){
                conflict = 1;
                return ;
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

    int i;

    for( i = 1 ; i <= n ; i++)
        color[i] = No_color;

    //1-KIEM TRA DO THI PHAN DOI
    // DFS(&G,1,No_color);
    
    // if(conflict) printf("NO");
    // else printf("YES");

    //2-IN RA DO THI PHAN DOI

    for( i = 1 ; i <= n ; i++)
        if(color[i] == No_color)
            DFS(&G,i,blue);

    if (conflict == 0)
    {
        for ( i = 1; i <= n; i++)
            if (color[i] == blue)
            {
                printf("%d ",i);
            }   
        printf("\n");
        for ( i = 1; i <= n; i++)
            if (color[i] == red)
            {
                printf("%d ",i);
            }   
    } else printf("IMPOSSIBLE");
    

    return 0;
}