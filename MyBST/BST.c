#include <stdio.h>
#include <stdlib.h>
#include "BST.h"

void initTree(NodePtr* Tree){
	*Tree = NULL;
}

void insert(NodePtr* Tree, Product b){ // non-recursive
	NodePtr* trav;	

	for(trav = Tree; *trav != NULL && strcmp(b.prodName, (*trav)->item.prodName) != 0;){
		trav = (strcmp((*trav)->item.prodName, b.prodName) < 0) ? &(*trav)->right : &(*trav)->left;
		 
	}
	
	if(*trav == NULL){
		*trav = (NodePtr)calloc(1, sizeof(struct node));
		if(*trav != NULL){
			(*trav)->item = b;
		}
	}
}

void Delete(NodePtr* Tree, Product b){ // non-recursive
	NodePtr *trav, *trav2, temp;
	
	for(trav = Tree; *trav != NULL && strcmp(b.prodName, (*trav)->item.prodName) != 0;){
		trav = (strcmp((*trav)->item.prodName, b.prodName) < 0) ? &(*trav)->right : &(*trav)->left;
	}
	
	if(*trav != NULL){
		if((*trav)->left == NULL){
			temp = *trav;
			*trav = temp->right;
			free(temp);
		}else if((*trav)->right == NULL){
			temp = *trav;
			*trav = temp->left;
			free(temp);
		}else{
			for(trav2 = &(*trav)->right; (*trav2)->left != NULL; trav2 = &(*trav2)->left){}
			temp = *trav2;
			*trav2 = temp->right;
			(*trav)->item = temp->item;
			free(temp);
		}
	}
}

void preOrder(NodePtr Tree){ // recursive
	if(Tree != NULL){
		printf("%s ", Tree->item.prodName);
		preOrder(Tree->left);
		preOrder(Tree->right);
	}
}

void inOrder(NodePtr Tree){ // recursive
	if(Tree != NULL){
		inOrder(Tree->left);
		printf("%s ", Tree->item.prodName);
		inOrder(Tree->right);
	}
}

void postOrder(NodePtr Tree){ // recursive
	if(Tree != NULL){
		postOrder(Tree->left);
		postOrder(Tree->right);
		printf("%s ", Tree->item.prodName);
	}
}

void BFS(NodePtr T) {
    Queue q;
    q.front = q.rear = NULL;

    if (T != NULL) {
        enqueue(&q, T);
    }

    while (!isQueueEmpty(&q)) {
        NodePtr current = dequeue(&q);
        printf("%s ", current->item.prodName);

        if (current->left != NULL) {
            enqueue(&q, current->left);
        }
        if (current->right != NULL) {
            enqueue(&q, current->right);
        }
    }
}

void enqueue(Queue *q, NodePtr treeNode) {
    QueueNode *newNode = (QueueNode *)malloc(sizeof(QueueNode));
    if (newNode == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    newNode->treeNode = treeNode;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

NodePtr dequeue(Queue *q) {
    if (isQueueEmpty(q)) {
        fprintf(stderr, "Queue is empty\n");
        exit(EXIT_FAILURE);
    }

    QueueNode *temp = q->front;
    NodePtr treeNode = temp->treeNode;

    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    return treeNode;
}

int isQueueEmpty(Queue *q) {
    return (q->front == NULL);
}
