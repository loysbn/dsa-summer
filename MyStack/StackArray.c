#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "StackArray.h"

void initStack(StackArrayList* s){
	s->top = -1;
}

StackArrayList createStack(){
	int i;
	StackArrayList s;
	for(i = 0; i < MAX; i++){
		s.data[i] = 0;
	}
}

bool isEmpty(StackArrayList *s){
	return (s->top == -1) ? true : false;
}

bool isFull(StackArrayList *s){
	return (s->top == MAX-1) ? true : false;
}

bool stack_push(StackArrayList *s, int elem){
	if(isFull(s)){
		printf("Stack is full.\n");
		return false;
	} else {
		s->top++;
		s->data[s->top] = elem;
		return true;
	}
}

bool stack_pop(StackArrayList *s){
	if(isEmpty(s)){
		printf("Stack is empty.\n");
		return false;
	} else {
		s->top--;
		return true;
	}
}

int stack_peek(StackArrayList s){
	if(isEmpty(&s)){
		printf("Stack is empty.\n");
		return false;
	} else {
		return s.data[s.top];
	}
}

void display(StackArrayList s){
	StackArrayList temp;
	
	for(temp.top = -1; s.top != -1; s.top--){
        stack_push(&temp, s.data[s.top]);
    }

    while(temp.top != -1){
        printf("%d ", temp.data[temp.top]);
        stack_pop(&temp);
    }
    printf("\n");
}

void visualize(StackArrayList s){
	StackArrayList temp;
	
	for(temp.top = -1; s.top != -1; s.top--){
        stack_push(&temp, s.data[s.top]);
    }
	
	printf("Data:");
    while(temp.top != -1){
        printf("%d\n", temp.data[temp.top]);
        stack_pop(&temp);
    }
}
