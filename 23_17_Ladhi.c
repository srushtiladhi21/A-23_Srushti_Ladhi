#include <stdio.h>
#define MAX 10

int adj[MAX][MAX], visited[MAX], n;

void dfs(int v) {
    printf("%d ", v);
    visited[v] = 1;
    for (int i = 0; i < n; i++)
        if (adj[v][i] && !visited[i])
            dfs(i);
}

void bfs(int start) {
    int queue[MAX], front = 0, rear = 0;
    for (int i = 0; i < n; i++) visited[i] = 0;
    queue[rear++] = start;
    visited[start] = 1;

    while (front < rear) {
        int v = queue[front++];
        printf("%d ", v);
        for (int i = 0; i < n; i++)
            if (adj[v][i] && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
    }
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    printf("DFS starting from 0: ");
    for (int i = 0; i < n; i++) visited[i] = 0;
    dfs(0);

    printf("\nBFS starting from 0: ");
    bfs(0);
    return 0;
}
