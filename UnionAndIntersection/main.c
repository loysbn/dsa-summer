#include <stdio.h>
#include <stdlib.h>
#define MAX 10
#include "set_ui.h"

int main(){
    int X[] = {1,2,3,5,6};
    int Y[] = {2,3,4,5,8};
    SET A, B, C;

    initSet(&A);
    initSet(&B);
    initSet(&C);

    A = populateSet(X);
    B = populateSet(Y);

    printf("Set A: ");
    displaySet(A);
    printf("\nSet B: ");
    displaySet(B);

    C = unionSet(A, B);
    printf("\nUnion of A and B: ");
    displaySet(C);

	C = intersection(A, B);
	printf("\nIntersection of A and B: ");
	displaySet(C);

    return 0;
}
