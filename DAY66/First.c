#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool dfs(int node, int V, int** adj, int* visited, int* recStack) {
    visited[node] = 1;
    recStack[node] = 1;

    for (int i = 0; i < V; i++) {
        if (adj[node][i]) {
            if (!visited[i]) {
                if (dfs(i, V, adj, visited, recStack))
                    return true;
            } else if (recStack[i]) {
                return true;
            }
        }
    }

    recStack[node] = 0;
    return false;
}

int isCycle(int V, int** adj) {
    int* visited = (int*)calloc(V, sizeof(int));
    int* recStack = (int*)calloc(V, sizeof(int));

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, V, adj, visited, recStack)) {
                free(visited);
                free(recStack);
                return 1;
            }
        }
    }

    free(visited);
    free(recStack);
    return 0;
}

int main() {
    int V = 4;

    int** adj = (int**)malloc(V * sizeof(int*));
    for (int i = 0; i < V; i++)
        adj[i] = (int*)calloc(V, sizeof(int));

    adj[0][1] = 1;
    adj[1][2] = 1;
    adj[2][3] = 1;
    adj[3][1] = 1;

    if (isCycle(V, adj))
        printf("YES\n");
    else
        printf("NO\n");

    for (int i = 0; i < V; i++)
        free(adj[i]);
    free(adj);

    return 0;
}