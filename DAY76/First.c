#include <stdio.h>
#include <stdlib.h>

void dfs(int node, int* visited, int** adj, int* size) {
    visited[node] = 1;

    for (int i = 0; i < size[node]; i++) {
        int nei = adj[node][i];
        if (!visited[nei]) {
            dfs(nei, visited, adj, size);
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int** adj = (int**)malloc((n + 1) * sizeof(int*));
    int* size = (int*)calloc((n + 1), sizeof(int));

    for (int i = 1; i <= n; i++) {
        adj[i] = (int*)malloc(n * sizeof(int));
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        adj[u][size[u]++] = v;
        adj[v][size[v]++] = u;
    }

    int* visited = (int*)calloc((n + 1), sizeof(int));
    int count = 0;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i, visited, adj, size);
            count++;
        }
    }

    printf("%d", count);

    return 0;
}