#ifndef Graph
#define Graph

struct Node{
    char vertex;
    struct Node* next;
};

struct Graph{
    int numVertices;
    struct Node* adjList[MAX_VERTICES];
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
};

int findVertexIndex(char vertex){
    return vertex - 'A';
}

struct Node* createNode(char v){
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void addVertex(struct Graph* graph, char vertex);
void addEdge(struct Graph* graph, char src, char dest);
void removeEdge(struct Graph* graph, char src, char dest);
void removeVertex(struct Graph* graph, char vertex);
void printAdjMatrix(struct Graph* graph);
void printAdjList(struct Graph* graph);

#endif
