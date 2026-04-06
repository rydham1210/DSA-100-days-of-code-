#include <stdio.h>
#include <stdlib.h>

int hasCycle = 0;

void dfs(int node, int parent, int** adj, int* visited, int n) {
    visited[node] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[node][i] == 1) {
            if (!visited[i]) {
                dfs(i, node, adj, visited, n);
            } 
            else if (i != parent) {
                hasCycle = 1;
                return;
            }
        }
    }
}

int detectCycle(int** adj, int n) {
    int* visited = (int*)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, -1, adj, visited, n);
        }
    }

    free(visited);
    return hasCycle;
}

int main() {
    int n;
    scanf("%d", &n);

    int** adj = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        adj[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    if (detectCycle(adj, n))
        printf("YES\n");
    else
        printf("NO\n");

    for (int i = 0; i < n; i++)
        free(adj[i]);
    free(adj);

    return 0;
}