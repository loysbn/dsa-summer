#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

typedef struct{
    int data[MAX];
    int front;
    int rear;
}circularQ;

void initQueue(circularQ* Q){
    Q->front = -1;
    Q->rear =  -1;
}

bool isFull(circularQ* Q){
    return ((Q->rear+1) % MAX == Q->front) ? true : false;
}

bool isEmpty(circularQ* Q){
    return ((Q->rear+2) % MAX == Q->front) ? true : false;
}

void enqueue(circularQ* Q, int data){
    if(isFull(Q)){
        printf("Queue is full\n");
    } else {
		if(Q->front == -1){
			Q->front = 0;
		}
		Q->rear = (Q->rear+1) % MAX;
		Q->data[Q->rear] = data;
    }
}

void dequeue(circularQ* Q){
    int i;
    
    if(isEmpty(Q)){
    	printf("Queue is empty\n");
	} else {
		int data = Q->data[Q->front];
		if(Q->front == Q->rear){
			Q->front = Q->rear = 1;
		} else {
			Q->front =(Q->front + 1) % MAX;
		}
	}
    
}

void display(circularQ Q){
    int i;
    for(i = Q.front; i != Q.rear; i = (i + 1) % MAX){
        printf("%d ", Q.data[i]);
    }
    printf("\n");
}

int main(){
    circularQ Q;

    initQueue(&Q);
    enqueue(&Q, 1);
    enqueue(&Q, 2);
    enqueue(&Q, 3);
    enqueue(&Q, 4);
    enqueue(&Q, 5);
    enqueue(&Q, 6);
    enqueue(&Q, 7);
    enqueue(&Q, 8);
    enqueue(&Q, 9);
    enqueue(&Q, 10);
    display(Q);
    
    printf("\nFront:%d Rear:%d", Q.front, Q.rear);
    dequeue(&Q);
    printf("\n\nAfter dequeue:\n");
    display(Q);
    printf("\nFront:%d Rear:%d", Q.front, Q.rear);

    printf("\n\nFront value: %d", Q.data[Q.front]);

    return 0;
}
