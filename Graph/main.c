#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_VERTICES 5
#include "Graph.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->numVertices = 0;
    int i, j;

    addVertex(graph, 'A'); 
    addVertex(graph, 'B'); 
    addVertex(graph, 'C'); 
    addVertex(graph, 'D'); 
    addVertex(graph, 'E'); 

    for (i = 0; i < MAX_VERTICES; ++i) {
        for (j = 0; j < MAX_VERTICES; ++j) {
            graph->adjMatrix[i][j] = 0;
        }
    }

    addEdge(graph, 'A', 'C'); 
    addEdge(graph, 'A', 'B'); 
    addEdge(graph, 'A', 'D'); 
    addEdge(graph, 'D', 'A'); 
    addEdge(graph, 'D', 'C');
    addEdge(graph, 'D', 'B');
    addEdge(graph, 'D', 'E');
    addEdge(graph, 'C', 'A'); 
    addEdge(graph, 'C', 'D');
    addEdge(graph, 'C', 'B'); 
    addEdge(graph, 'B', 'A'); 
    addEdge(graph, 'B', 'C'); 
    addEdge(graph, 'B', 'D'); 
    addEdge(graph, 'B', 'E');
    addEdge(graph, 'E', 'D'); 
    addEdge(graph, 'E', 'B'); 

    printAdjMatrix(graph);
    printAdjList(graph);
    
    removeVertex(graph, 'A');
    printf("\nVertex A is removed.\n");
    removeEdge(graph, 'D', 'E');
    printf("\nEdge D-E is removed.\n");
    
    printf("\nAfter removals:\n");
    printAdjMatrix(graph);
    printAdjList(graph);

    return 0;
}
