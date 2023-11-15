#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
int numVertices = 0;

void initializeGraph() {
    int i, j;

    for (i = 0; i < MAX_VERTICES; i++) {
        for (j = 0; j < MAX_VERTICES; j++) {
            adjacencyMatrix[i][j] = 0;
        }
    }
}

void addDirectedEdge(int from, int to) {
    if (from >= 0 && from < MAX_VERTICES && to >= 0 && to < MAX_VERTICES) {
        adjacencyMatrix[from][to] = 1;
    } else {
        printf("Invalid vertices\n");
    }
}

void addUndirectedEdge(int v1, int v2) {
    if (v1 >= 0 && v1 < MAX_VERTICES && v2 >= 0 && v2 < MAX_VERTICES) {
        adjacencyMatrix[v1][v2] = 1;
        adjacencyMatrix[v2][v1] = 1;
    } else {
        printf("Invalid vertices\n");
    }
}

void displayGraph() {
    int i, j;

    printf("Adjacency Matrix:\n");

    for (i = 0; i < numVertices; i++) {
        for (j = 0; j < numVertices; j++) {
            printf("%d ", adjacencyMatrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    initializeGraph();

    addDirectedEdge(0, 1);
    addDirectedEdge(1, 2);
    addDirectedEdge(2, 0);
    addDirectedEdge(2, 3);

    addUndirectedEdge(3, 4);
    addUndirectedEdge(4, 5);

    numVertices = 6;

    displayGraph();

    return 0;
}
