#include <stdio.h>
#include <stdlib.h>

void dfs(int node, int** adj, int* visited, int* stack, int* top, int V) {
    visited[node] = 1;

    for (int i = 0; i < V; i++) {
        if (adj[node][i] == 1 && !visited[i]) {
            dfs(i, adj, visited, stack, top, V);
        }
    }

    stack[++(*top)] = node;
}

void topoSort(int V, int** adj) {
    int* visited = (int*)calloc(V, sizeof(int));
    int* stack = (int*)malloc(V * sizeof(int));
    int top = -1;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited, stack, &top, V);
        }
    }

    while (top != -1) {
        printf("%d ", stack[top--]);
    }

    free(visited);
    free(stack);
}

int main() {
    int V = 6;

    int** adj = (int**)malloc(V * sizeof(int*));
    for (int i = 0; i < V; i++) {
        adj[i] = (int*)calloc(V, sizeof(int));
    }

    adj[5][2] = 1;
    adj[5][0] = 1;
    adj[4][0] = 1;
    adj[4][1] = 1;
    adj[2][3] = 1;
    adj[3][1] = 1;

    topoSort(V, adj);

    return 0;
}