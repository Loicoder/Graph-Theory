#include<stdio.h>
#define MAX_M 500

typedef struct{
	int u,v;
}Edge;

typedef struct{
	int n, m;
	Edge edges[MAX_M];
}Graph;

void init_graph(Graph *G, int n){
	G->n = n;
	G->m = 0;
}

void add_edge(Graph *G, int u, int v){
	G->edges[G->m].u = u;
	G->edges[G->m].v = v;
	
	G->m++;
}

int adjacent(Graph *G, int u, int v){
	int e;
	for(e = 1; e < G->m; e++){
		if((G->edges[e].u==u && G->edges[e].v==v)
		|| (G->edges[e].u==v && G->edges[e].v==u))
			return 1;
	}
	return 0;
}

int degree(Graph *G, int u){
	int deg_u = 0;
	int e;
	for(e = 0; e < G->m; e++){
		if(G->edges[e].u == u){
			deg_u++;
		}
		if(G->edges[e].v == u){
			deg_u++;
		}
	}
	return deg_u;
}

int main(){
	Graph G;
	int n, m, u, v, e;
	freopen("dt.txt","r",stdin);
	
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
