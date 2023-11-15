#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Queue structure for BFS
struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
};

// Graph structure
struct Graph {
    int numVertices;
    int** adjacencyMatrix;
};

// Function to create a new queue
struct Queue* createQueue(unsigned capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;  // This is important, see the enqueue function
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

// Function to check if the queue is full
int isFull(struct Queue* queue) {
    return (queue->size == queue->capacity);
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return (queue->size == 0);
}

// Function to add an item to the queue
void enqueue(struct Queue* queue, int item) {
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
}

// Function to remove an item from the queue
int dequeue(struct Queue* queue) {
    if (isEmpty(queue))
        return -1;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

// Function to create a new graph with the given number of vertices
struct Graph* createGraph(int numVertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;

    // Allocate memory for the adjacency matrix
    graph->adjacencyMatrix = (int**)malloc(numVertices * sizeof(int*));
    for (int i = 0; i < numVertices; i++) {
        graph->adjacencyMatrix[i] = (int*)malloc(numVertices * sizeof(int));
        for (int j = 0; j < numVertices; j++) {
            graph->adjacencyMatrix[i][j] = 0;
        }
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int start, int end) {
    graph->adjacencyMatrix[start][end] = 1;
    graph->adjacencyMatrix[end][start] = 1; // Assuming an undirected graph
}

// Function to perform Breadth First Search (BFS)
void BFS(struct Graph* graph, int startVertex) {
    // Create a queue for BFS
    struct Queue* queue = createQueue(MAX_VERTICES);

    // Mark all vertices as not visited
    int visited[MAX_VERTICES] = {0};

    // Mark the current node as visited and enqueue it
    visited[startVertex] = 1;
    enqueue(queue, startVertex);

    while (!isEmpty(queue)) {
        // Dequeue a vertex from the queue and print it
        int currentVertex = dequeue(queue);
        printf("%d ", currentVertex);

        // Get all adjacent vertices of the dequeued vertex
        // If an adjacent vertex has not been visited, mark it visited and enqueue it
        for (int i = 0; i < graph->numVertices; i++) {
            if (graph->adjacencyMatrix[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = 1;
                enqueue(queue, i);
            }
        }
    }

    // Free the queue
    free(queue->array);
    free(queue);
}

// Recursive function for Depth First Search (DFS)
void DFSUtil(struct Graph* graph, int vertex, int visited[]) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->adjacencyMatrix[vertex][i] == 1 && !visited[i]) {
            DFSUtil(graph, i, visited);
        }
    }
}

// Function to perform Depth First Search (DFS)
void DFS(struct Graph* graph, int startVertex) {
    // Mark all vertices as not visited
    int visited[MAX_VERTICES] = {0};

    // Call the recursive utility function
    DFSUtil(graph, startVertex, visited);
}

int main() {
    int choice, startVertex;

    // Create a sample graph
    struct Graph* graph = createGraph(5);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);

    printf("Choose traversal algorithm:\n");
    printf("1. Breadth First Search (BFS)\n");
    printf("2. Depth First Search (DFS)\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter the starting vertex: ");
    scanf("%d", &startVertex);

    switch (choice) {
        case 1:
            printf("Breadth First Search starting from vertex %d:\n", startVertex);
            BFS(graph, startVertex);
            break;
        case 2:
            printf("Depth First Search starting from vertex %d:\n", startVertex);
            DFS(graph, startVertex);
            break;
        default:
            printf("Invalid choice\n");
    }

    // Free the graph
    for (int i = 0; i < graph->numVertices; i++) {
        free(graph->adjacencyMatrix[i]);
    }
    free(graph->adjacencyMatrix);
    free(graph);

    return 0;
}
