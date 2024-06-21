#ifndef Set_UI
#define Set_UI
#define MAX 5

typedef struct{
    char data[MAX];
    int count;
}SET;

void initSet(SET* C);
SET populateSet(int C[]);
SET unionSet(SET A, SET B);
SET intersection(SET A, SET B);
void displaySet(SET C);


#endif
