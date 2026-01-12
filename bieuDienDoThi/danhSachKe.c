
#include <stdio.h>
#define MAX_N 100

//Khai báo CTDL List và các phép toán cơ bản
#define MAX_ELEMENTS 100
typedef int ElementType;
typedef struct {
    ElementType data[MAX_ELEMENTS];
    int size;
} List;

//Tạo danh sách rỗng
void make_null(List *pL) {
    pL->size = 0;
}

//Thêm một phần tử vào cuối danh sách
void push_back(List *pL, ElementType x) {
    pL->data[pL->size] = x;
    pL->size++;
}

//Lấy phần tử thứ i, phần tử bắt đầu có vị trí 1
ElementType element_at(List *pL, int i){
    return pL->data[i-1];
}

//Trả về số phần tử của danh sách
int count_list(List *pL) {
    return pL->size;
}

typedef struct {
    int n;
    List adj[MAX_N];
} Graph;


//Khởi tạo đồ thị có n đỉnh và 0 cung
void init_graph(Graph *pG, int n) {
    int u;
    pG->n = n;
    //Khởi tạo các danh sách kề rỗng
    for (u = 1; u <= n; u++)
        make_null(&pG->adj[u]);
}

//Thêm cung (u, v) vào đồ thị vô hướng *pG
void add_edge(Graph *pG, int u, int v) {
    push_back(&pG->adj[u], v); //v là kề của u
    push_back(&pG->adj[v], u); //u là kề của v
}

int adjacent(Graph *pG, int u, int v) {
    int j;
    for (j = 1; j <= pG->adj[u].size; j++)
        if (element_at(&pG->adj[u], j) == v)
            return 1;
    return 0;
}

int degree(Graph *pG, int u){
    return pG->adj[u].size;
}
int main(void){
    Graph G;
    int n, m, u, v, e;
    freopen("dothi.txt","r",stdin);
    
    scanf("%d%d",&n,&m);
    init_graph(&G, n);
    
    for(e=0; e<m; e++){
        scanf("%d%d",&u,&v);
        add_edge(&G, u, v);
    }
    
    for(int u = 1; u <= G.n; u++){
        printf("neighbors(%d) = ", u);
        for(int v = 1; v <= G.n; v++){
            if(adjacent(&G,u,v)){
                printf("%d ", v);
            }
        }
        printf("\n");
    }
    
    for(int u = 1; u <= n; u++){
        printf("deg(%d) = %d", u, degree(&G, u));
        printf("\n");
    }
    return 0;
}
