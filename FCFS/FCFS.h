#ifndef FCFS
#define FCFS
#define MAX 10

typedef struct {
    int id;
    int BT;
    int AT;
    int ET;
    int WT;
    int TT;
} Process;

typedef struct {
    Process items[MAX];
    int front, rear;
    int count;
} Queue;

typedef struct {
	int wtTotal;
	int ttTotal;
	float avgWT;
	float avgTT;
}Avg;

void initQueue(Queue* q);
void enqueue(Queue *q, Process p);
Process dequeue(Queue *q);
void sortByAT(Process P[], int N);
void getET(Process P[], int N);
void getWT(Process P[], int N);
void getTT(Process P[], int N);
void getAvgWT(Process P[], int N, Avg* A);
void getAvgTT(Process P[], int N, Avg* A);
void display(Process P[], int N, Avg A);

#endif
