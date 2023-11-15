#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Graph {
    int vertices;
    struct Node** adjacencyList;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices = vertices;
    graph->adjacencyList = (struct Node**)malloc(vertices * sizeof(struct Node*));

    for (int i = 0; i < vertices; ++i)
        graph->adjacencyList[i] = NULL;

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest, int isDirected) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjacencyList[src];
    graph->adjacencyList[src] = newNode;

    if (!isDirected) {
        newNode = createNode(src);
        newNode->next = graph->adjacencyList[dest];
        graph->adjacencyList[dest] = newNode;
    }
}

void printGraph(struct Graph* graph) {
    for (int i = 0; i < graph->vertices; ++i) {
        struct Node* current = graph->adjacencyList[i];
        printf("Adjacency list of vertex %d\n", i);
        while (current) {
            printf("%d -> ", current->data);
            current = current->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int vertices = 5;
    int isDirected = 1;  // Change to 0 for an undirected graph
    struct Graph* graph = createGraph(vertices);

    addEdge(graph, 0, 1, isDirected);
    addEdge(graph, 0, 4, isDirected);
    addEdge(graph, 1, 2, isDirected);
    addEdge(graph, 1, 3, isDirected);
    addEdge(graph, 1, 4, isDirected);
    addEdge(graph, 2, 3, isDirected);
    addEdge(graph, 3, 4, isDirected);

    printGraph(graph);

    return 0;
}
