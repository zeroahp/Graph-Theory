#include <stdio.h>
/*Chu trình là một đường đi có đỉnh 
đầu trùng với đỉnh cuối*/
#define Max_vertices 100
#define white 0
#define gray 1
#define black 2

/*
Khởi tạo tất cả các đỉnh đều có màu trắng
Hàm đệ quy DFS(u) gồm các bước:
- Tô màu màu xám (đang duyệt) cho u và
- Xét các đỉnh kề v của u:
o Nếu v có màu trắng => gọi đệ quy duyệt v
o Nếu đỉnh kề v nào đó có màu xám -> có chu trình(has_circle)
o Nếu v có màu đen => duyệt xong rồi, bỏ qua
*/
typedef struct 
{
    int A[Max_vertices][Max_vertices];
    int n,m;
}Graph;

void init_graph(Graph *G, int n){
    G->n = n;
    int i, j;
    for(i = 1 ; i <= G->n ; i++)
        for(j = 1; j <= G->n ; j++)
            G->A[i][j] = 0;
    
}

void add_edge(Graph *G, int x, int y){
    G->A[x][y] = 1;
    // G->A[y][x] = 1;
    G->m ++;
}

int adjacent(Graph *G, int x, int y){
    return G->A[x][y] == 1;
}

int has_circle = 0;
int color[Max_vertices];

int parent[Max_vertices], start, end;

void circle(Graph *G, int u,int p){
    color[u] = gray;
    parent[u] = p;
    int v;
    for( v = 1; v <= G->n ; v++){
        if(v == p) continue; // do thi "vo huong"
        if(adjacent(G,u,v)){
            if(color[v] == white)
                circle(G,v,u);
            else if(color[v] == gray){
                has_circle = 1;
                //2 - IN CAC DINH CO TRONG CHU TRINH
                start = u;
                end = v;
                
                return;
            }
        }  
    }
    color[u] = black;
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
    for( i = 1; i <= n ; i++)
        color[i] = white;

    //1 - KIEM TRA DO THI CHUA CHU TRINH
    for( i = 1; i <= n ; i++)
        if(color[i] == white)
           circle(&G,i);
    if(has_circle)
        printf("CIRCLED");
    else printf("NO CIRCLED");

    //2 - IN CAC DINH CO TRONG CHU TRINH
    for(e =1; e<= n; e++){
        if(color[e] == white)
            circle(&G,e,-1);
    }

    int A[Max_vertices];
    int a,b, cnt;

    if(has_circle){
        A[0] = start;
        a = start, b = end, cnt = 1;
        do{
            a = parent[a];
            A[cnt++] = a;
        }while(a != b);
    }

    if(has_circle){
        while(cnt--){
            printf("%d ",A[cnt]);
        }
        printf("%d", end);
    }
    else printf("-1");
    return 0;
}