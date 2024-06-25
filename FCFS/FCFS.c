#include <stdio.h>
#include <stdlib.h>
#include "FCFS.h"
#define MAX 10

void initQueue(Queue* q){
	q->front = 0;
	q->rear = -1;
	q->count = 0;
}

void enqueue(Queue *q, Process p){
    if (q->count == MAX) {
        printf("Queue is full, cannot enqueue.\n");
        exit(1);
    }
    q->rear = (q->rear + 1) % MAX;
    q->items[q->rear] = p;
    q->count++;
}

Process dequeue(Queue *q){
    if (q->count == 0){
        printf("Queue is empty, cannot dequeue.\n");
        exit(1);
    }
    Process item = q->items[q->front];
    q->front = (q->front + 1) % MAX;
    q->count--;
    return item;
}

void sortByAT(Process P[], int N){
    int i, j;
    Process temp;

    for (i = 0; i < N; i++){
        for (j = i + 1; j < N; j++){
            if (P[i].AT > P[j].AT){
                temp = P[i];
                P[i] = P[j];
                P[j] = temp;
            }
        }
    }
}

void getET(Process P[], int N){
    int et = 0, i;

    for (i = 0; i < N; i++){
        et += P[i].BT;
        P[i].ET = et;
    }
}

void getWT(Process P[], int N){
    int i;

    for (i = 0; i < N; i++){
        P[i].WT = P[i].ET - P[i].AT - P[i].BT;
    }
}

void getTT(Process P[], int N){
    int i;

    for (i = 0; i < N; i++){
        P[i].TT = P[i].ET - P[i].AT;
    }
}

void getAvgWT(Process P[], int N, Avg* A){
	A->wtTotal = 0;
	int i;
	
	for(i = 0; i < N; i++){
		A->wtTotal += P[i].WT;
	}
	
	A->avgWT = (float)A->wtTotal / N;
}

void getAvgTT(Process P[], int N, Avg* A){
	A->ttTotal = 0;
	int i;
	
	for(i = 0; i < N; i++){
		A->ttTotal += P[i].TT;
	}
	
	A->avgTT = (float)A->ttTotal / N;
}

void display(Process P[], int N, Avg A){
    int i;

    printf("Process\t|\t BT\t AT\t ET\t WT\t TT\t|\n");
    printf("---------------------------------------------------------\n");
    
    for (i = 0; i < N; i++){
        printf("    %c   |\t %d\t %d\t %d\t %d\t %d\t|\t\n", P[i].id, P[i].BT, P[i].AT, P[i].ET, P[i].WT, P[i].TT);
    }
    printf("---------------------------------------------------------\n");
    
    printf("\n-----------------\n");
    printf("Total WT: %d\n", A.wtTotal);
    printf("Average WT: %.2f\n", A.avgWT);
    printf("\nTotal TT: %d\n", A.ttTotal);
    printf("Average TT: %.2f\n", A.avgTT);
    printf("-----------------\n");
    

    printf("\n\n ---------------\n");
    printf(" | GANTT CHART |\n");
    printf(" ---------------\n\n");
    printf(" |");
    
    
    for (i = 0; i < N; i++){
        printf(" %c |", P[i].id);
    }
    printf("\n ");
    
    printf("0   ");
    for (i = 0; i < N; i++){
        if (P[i].ET < 10){
            printf("%d   ", P[i].ET);
        } else {
            printf("%d  ", P[i].ET);
        }
    }
}
