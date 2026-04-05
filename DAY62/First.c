#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct Graph {
    int numVertices;
    struct Node** adjLists;
};

struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->adjLists = (struct Node**)malloc(vertices * sizeof(struct Node*));

    for (int i = 0; i < vertices; i++)
        graph->adjLists[i] = NULL;

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

void printGraph(struct Graph* graph) {
    for (int v = 0; v < graph->numVertices; v++) {
        struct Node* temp = graph->adjLists[v];
        printf("Vertex %d: ", v);
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

void dfsIterative(struct Graph* graph, int start) {
    int* visited = (int*)calloc(graph->numVertices, sizeof(int));
    int* stack = (int*)malloc(graph->numVertices * sizeof(int));
    int top = -1;

    stack[++top] = start;

    while (top != -1) {
        int current = stack[top--];

        if (!visited[current]) {
            printf("%d ", current);
            visited[current] = 1;

            struct Node* temp = graph->adjLists[current];
            while (temp) {
                if (!visited[temp->vertex]) {
                    stack[++top] = temp->vertex;
                }
                temp = temp->next;
            }
        }
    }

    free(visited);
    free(stack);
}

int main() {
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);

    struct Graph* graph = createGraph(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    printGraph(graph);
    dfsIterative(graph, 0);

    return 0;
}