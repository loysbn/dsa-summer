#include <stdio.h>
#include <stdlib.h>
#include "FCFS.h"
#define MAX 10

int main() {
    int n, i;
    float avgWT, avgTT;
    Avg A;
    Process P[MAX];
    Queue q;
    initQueue(&q);

    printf("How many processes: ");
    scanf("%d", &n);
    system("cls");

    printf("Total Processes: %d\n", n);
    printf("-----------------\n");
    for (i = 0; i < n; i++) {
        P[i].id = 'A' + i;
        printf("Process: %c\n", P[i].id);
        printf("BT: ");
        scanf("%d", &P[i].BT);
        printf("AT: ");
        scanf("%d", &P[i].AT);
        printf("-----------------\n");
    }
	
	system("cls");
    sortByAT(P, n);

    // Enqueue all processes based on arrival time
    for (i = 0; i < n; i++) {
        enqueue(&q, P[i]);
    }

    // Perform FCFS scheduling
    getET(P, n);
    getWT(P, n);
    getTT(P, n);
    getAvgWT(P, n, &A);
    getAvgTT(P, n, &A);
    display(P, n, A);

    return 0;
}

