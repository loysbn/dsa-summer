#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_VERTICES 5
#include "Graph.h"

void addVertex(struct Graph* graph, char vertex){
    if (graph->numVertices < MAX_VERTICES) {
        int index = findVertexIndex(vertex);
        graph->adjList[index] = NULL;
        graph->numVertices++;
    } 
}

void addEdge(struct Graph* graph, char src, char dest){
    int srcIndex = findVertexIndex(src);
    int destIndex = findVertexIndex(dest);

    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjList[srcIndex];
    graph->adjList[srcIndex] = newNode;

    graph->adjMatrix[srcIndex][destIndex] = 1;
    graph->adjMatrix[destIndex][srcIndex] = 1;
}

void removeEdge(struct Graph* graph, char src, char dest){
    int srcIndex = findVertexIndex(src);
    int destIndex = findVertexIndex(dest);

    struct Node* curr = graph->adjList[srcIndex];
    struct Node* prev = NULL;

    while (curr != NULL && curr->vertex != dest) {
        prev = curr;
        curr = curr->next;
    }

    if (curr != NULL) {
        if (prev == NULL) {
            graph->adjList[srcIndex] = curr->next;
        } else {
            prev->next = curr->next;
        }
        free(curr);
    } else {
        printf("Edge %c-%c not found.\n", src, dest);
    }

    graph->adjMatrix[srcIndex][destIndex] = 0;
    graph->adjMatrix[destIndex][srcIndex] = 0;
}

void removeVertex(struct Graph* graph, char vertex){
    int index = findVertexIndex(vertex);
    int i;

    struct Node* curr = graph->adjList[index];
    struct Node* prev = NULL;

    while (curr != NULL) {
        prev = curr;
        curr = curr->next;
        free(prev);
    }

    graph->adjList[index] = NULL;

    for (i = 0; i < graph->numVertices; ++i) {
        if (i != index) {
            curr = graph->adjList[i];
            prev = NULL;

            while (curr != NULL && curr->vertex != vertex) {
                prev = curr;
                curr = curr->next;
            }

            if (curr != NULL) {
                if (prev == NULL) {
                    graph->adjList[i] = curr->next;
                } else {
                    prev->next = curr->next;
                }
                free(curr);
            }
        }
    }

    for (i = 0; i < graph->numVertices; ++i) {
        graph->adjMatrix[i][index] = 0;
        graph->adjMatrix[index][i] = 0;
    }

    graph->numVertices--;
}

void printAdjMatrix(struct Graph* graph){
	int i, j;
    printf("Adjacency matrix of the graph:\n");
    printf("  A B C D E\n");
    for (i = 0; i < graph->numVertices; ++i) {
        printf("%c ", 'A' + i);
        for (j = 0; j < graph->numVertices; ++j) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

void printAdjList(struct Graph* graph){
	int i;
    printf("\nAdjacency list of the graph:\n");
    for (i = 0; i < graph->numVertices; ++i) {
        struct Node* temp = graph->adjList[i];
        printf("Vertex %c: ", 'A' + i);
        while (temp) {
            printf("%c  ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}
