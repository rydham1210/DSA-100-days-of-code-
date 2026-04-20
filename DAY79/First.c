#include <stdio.h>
#include <limits.h>

#define MAX 100

int n, m;
int graph[MAX][MAX];
int dist[MAX], visited[MAX];

int minDistance() {
    int min = INT_MAX, min_index = -1;
    int i;
    for (i = 1; i <= n; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

void dijkstra(int src) {
    int i, count, v;

    for (i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[src] = 0;

    for (count = 1; count <= n; count++) {
        int u = minDistance();
        visited[u] = 1;

        for (v = 1; v <= n; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
}

int main() {
    int i, u, v, w, source;

    scanf("%d %d", &n, &m);

    for (i = 1; i <= n; i++) {
        for (v = 1; v <= n; v++) {
            graph[i][v] = 0;
        }
    }

    for (i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }

    scanf("%d", &source);

    dijkstra(source);

    for (i = 1; i <= n; i++) {
        printf("%d ", dist[i]);
    }

    return 0;
}