#include <stdio.h>
#include <stdlib.h>
#include "BST.h"

void initTree(NodePtr* Tree){
	*Tree = NULL;
}

void insert(NodePtr* Tree, Product b){ // non-recursive
	NodePtr* trav;	

	for(trav = Tree; *trav != NULL && strcmp(b.prodName, (*trav)->item.prodName) != 0;){
		trav = (strcmp((*trav)->item.prodName, b.prodName) < 0) ? &(*trav)->right : &(*trav)->left;
		 
	}
	
	if(*trav == NULL){
		*trav = (NodePtr)calloc(1, sizeof(struct node));
		if(*trav != NULL){
			(*trav)->item = b;
		}
	}
}

void Delete(NodePtr* Tree, Product b){ // non-recursive
	NodePtr *trav, *trav2, temp;
	
	for(trav = Tree; *trav != NULL && strcmp(b.prodName, (*trav)->item.prodName) != 0;){
		trav = (strcmp((*trav)->item.prodName, b.prodName) < 0) ? &(*trav)->right : &(*trav)->left;
	}
	
	if(*trav != NULL){
		if((*trav)->left == NULL){
			temp = *trav;
			*trav = temp->right;
			free(temp);
		}else if((*trav)->right == NULL){
			temp = *trav;
			*trav = temp->left;
			free(temp);
		}else{
			for(trav2 = &(*trav)->right; (*trav2)->left != NULL; trav2 = &(*trav2)->left){}
			temp = *trav2;
			*trav2 = temp->right;
			(*trav)->item = temp->item;
			free(temp);
		}
	}
}

void preOrder(NodePtr Tree){ // recursive
	if(Tree != NULL){
		printf("%s ", Tree->item.prodName);
		preOrder(Tree->left);
		preOrder(Tree->right);
	}
}

void inOrder(NodePtr Tree){ // recursive
	if(Tree != NULL){
		inOrder(Tree->left);
		printf("%s ", Tree->item.prodName);
		inOrder(Tree->right);
	}
}

void postOrder(NodePtr Tree){ // recursive
	if(Tree != NULL){
		postOrder(Tree->left);
		postOrder(Tree->right);
		printf("%s ", Tree->item.prodName);
	}
}
