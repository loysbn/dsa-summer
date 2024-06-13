#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "StackArray.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	StackArrayList s;
	
	initStack(&s);
	createStack();
	
	stack_push(&s, 1);
	stack_push(&s, 2);
	stack_push(&s, 3);
	stack_push(&s, 4);
	stack_push(&s, 5);
	stack_push(&s, 6);
	display(s);
	stack_push(&s, 7);
	
	stack_pop(&s);
	printf("\nAfter pop: ");
	display(s);
	
	int peek = stack_peek(s);
	printf("Peek: %d\n", peek);
	
//	display(s);
//	visualize(StackArrayList s);
	
	return 0;
}
