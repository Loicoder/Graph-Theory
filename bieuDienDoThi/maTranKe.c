#include <stdio.h> 

#define MAX_N 100
typedef struct {
    int n, m;
    int A[MAX_N][MAX_N];
} Graph;

void init_graph(Graph *pG, int n) {
    pG->n = n;
    for (int u = 1; u <= n; u++)
        for (int v = 1; v <= n; v++)
            pG->A[u][v] = 0;
}

void add_edge(Graph *pG, int u, int v) {
    pG->A[u][v] += 1;
    if (u != v)
        pG->A[v][u] += 1;
}

int degree(Graph *pG, int u) {
	int deg_u = 0;

	for (int v = 1; v <= pG->n; v++)
		deg_u += pG->A[u][v];

	return deg_u + pG->A[u][u];
}

int main() {
	Graph G;
	int n, m, e, u, v;
	
	freopen("dt.txt","r",stdin);
	
	scanf("%d%d", &n, &m);
	init_graph(&G, n);

	for (e = 0; e < m; e++) {
		scanf("%d%d", &u, &v);
		add_edge(&G, u, v);
	}
	
    printf("Ma tran ke:\n");
    for (int u = 1; u <= n; u++) {
        for (int v = 1; v <= n; v++)
            printf("%d ", G.A[u][v]);
        printf("\n");
    }
	
	for (int u = 1; u <= n; u++) {
	    printf("neighbours(%d) = ", u);
	    for (int v = 1; v <= n; v++)
	        if (G.A[u][v])
	            printf("%d ", v);
	   printf("\n");
	}
	
	for (int u = 1; u <= n; u++) {
        printf("deg(%d) = %d\n", u, degree(&G, u));
    }
    
	return 0;
}


