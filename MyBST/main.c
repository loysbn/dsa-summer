#include <stdio.h>
#include <stdlib.h>
#include "BST.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	Product b1 = {"Oreo", 20.00, 25, {8, 11, 2024}};
	Product b2 = {"Bingo", 10.00, 20, {4, 24, 2025}};
	Product b3 = {"Hansel", 7.00, 35, {1, 18, 2025}};
	Product b4 = {"ChocoMocho", 15.00, 15, {11, 4, 2024}};
	
	NodePtr Tree;
	
	initTree(&Tree);
	
	insert(&Tree, b1);
	insert(&Tree, b2);
	insert(&Tree, b3);
	insert(&Tree, b4);
	
	printf("Pre-Order: \n");
	preOrder(Tree);
	printf("\n\n");
	
	printf("In-Order: \n");
	inOrder(Tree);
	printf("\n\n");
	
	printf("Post-Order: \n");
	postOrder(Tree);
	printf("\n\n");
	
	printf("Breadth-First Search : \n");
    BFS(Tree);
    printf("\n\n");
	
	Delete(&Tree, b3);
	printf("===After delete===\n");
	
	printf("Pre-Order: \n");
	preOrder(Tree);
	printf("\n\n");
	
	printf("In-Order: \n");
	inOrder(Tree);
	printf("\n\n");
	
	printf("Post-Order: \n");
	postOrder(Tree);
	printf("\n\n");
	
	printf("Breadth-First Search : \n");
    BFS(Tree);
    printf("\n\n");
	
	return 0;
}
