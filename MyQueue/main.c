#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct node{
	int data;
	struct node* next;
}Node, *NodePtr;

typedef struct{
	NodePtr front;
	NodePtr rear;
}Queue;

void initQueue(Queue* q){
	q->front = NULL;
	q->rear = NULL;
}

bool isEmpty(Queue* q){
	return (q->front == NULL) ? true : false;
}

void enqueue(Queue* q, int data){
	NodePtr temp;
	
	temp = (NodePtr)malloc(sizeof(struct node));
	if(temp != NULL){
		temp->data = data;
		temp->next = NULL;
		
		if(q->rear == NULL){
			q->front = q->rear = temp;
		}
		
		q->rear->next = temp;
		q->rear = temp;
	}
}

void dequeue(Queue* q){
	NodePtr temp;
	
	if(isEmpty(q)){
		printf("Queue is empty!\n");
	} else {
		temp = q->front;
		q->front = q->front->next;
		if(q->front == NULL){
			q->rear = NULL;
		}
		
//		temp = q->front;
//		if(q->front == q->rear){
//			q->rear = temp->next;
//		}
//		q->front = temp->next;

		free(temp);
	}
}

void displayQueue(Queue q){
	NodePtr trav;
	
	for(trav = q.front; trav != NULL; trav = trav->next){
		printf("%d ", trav->data);
	}
	printf("\n");
}

int main(int argc, char *argv[]) {
	Queue q;
	
	initQueue(&q);
	
	enqueue(&q, 1);
	enqueue(&q, 2);
	enqueue(&q, 3);
	enqueue(&q, 4);
	enqueue(&q, 5);
	displayQueue(q);
	
	dequeue(&q);
	printf("\nAfter dequeue: ");
	displayQueue(q);
	
	dequeue(&q);
	printf("\nAfter dequeue: ");
	displayQueue(q);
	
	return 0;
}
