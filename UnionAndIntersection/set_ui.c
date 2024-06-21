#include <stdio.h>
#include <stdlib.h>
#define MAX 10
#include "set_ui.h"

void initSet(SET* C){
    C->count = 0;
}

SET populateSet(int C[]){
    int i;
    SET S;
    initSet(&S);

    for(i = 0; i < 5; i++){
        S.data[S.count] =  C[i];
        S.count++;
    }

    return S;
}

SET unionSet(SET A, SET B){
    int i, j;
    SET C;
    initSet(&C);

    for(i = 0; i < A.count; i++){ // copy all elements from A to C
        C.data[C.count++] = A.data[i];
    }

    for(i = 0; i < B.count; i++){ // copy all unique elements from B to C
        for(j = 0; j < C.count; j++){
            if(B.data[i] == C.data[j]){
                break;
            }
        }
        if(j == C.count){
            C.data[C.count++] = B.data[i];
        }
    }

    return C;
}

SET intersection(SET A, SET B){
	int i, j;
	SET C;
	initSet(&C);	

	for(i = 0; i < A.count; i++){
		for(j = 0; j < B.count; j++){
			if(A.data[i] == B.data[j]){
				C.data[C.count++] = A.data[i];
			}
		}
	}
	
	return C;
}

void displaySet(SET C){
    int i;

    for(i = 0; i < C.count; i++){
        printf("%d ", C.data[i]);
    }
    printf("\n");
}
