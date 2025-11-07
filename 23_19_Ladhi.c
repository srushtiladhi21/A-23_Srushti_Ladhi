#include <stdio.h>
#include <stdlib.h>

#define MAX 10
int n, timeCounter, visited[MAX], disc[MAX], low[MAX], parent[MAX], ap;

void dfs(int u, int graph[MAX][MAX]) {
    int children = 0;
    visited[u] = 1;
    disc[u] = low[u] = ++timeCounter;

    for (int v = 0; v < n; v++) {
        if (graph[u][v]) {
            if (!visited[v]) {
                children++;
                parent[v] = u;
                dfs(v, graph);
                low[u] = (low[u] < low[v]) ? low[u] : low[v];
                if ((parent[u] == -1 && children > 1) || 
                    (parent[u] != -1 && low[v] >= disc[u]))
                    ap = 1;
            } else if (v != parent[u])
                low[u] = (low[u] < disc[v]) ? low[u] : disc[v];
        }
    }
}

int main() {
    int graph[MAX][MAX];
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    for (int i = 0; i < n; i++) {
        visited[i] = 0; parent[i] = -1;
    }
    timeCounter = 0; ap = 0;

    dfs(0, graph);

    if (ap == 0)
        printf("Graph is Biconnected\n");
    else
        printf("Graph is NOT Biconnected\n");

    return 0;
}
