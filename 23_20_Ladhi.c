#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int graph[MAX][MAX], visited[MAX], n;
int stack[MAX], top = -1;

void push(int v) { stack[++top] = v; }

void dfs(int v) {
    visited[v] = 1;
    for (int i = 0; i < n; i++)
        if (graph[v][i] && !visited[i])
            dfs(i);
    push(v);
}

void topologicalSort() {
    for (int i = 0; i < n; i++)
        if (!visited[i])
            dfs(i);

    printf("Topological Order: ");
    while (top != -1)
        printf("%d ", stack[top--]);
    printf("\n");
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    topologicalSort();
    return 0;
}
