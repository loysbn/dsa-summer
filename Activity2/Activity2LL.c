#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char name[10];
	int idNum;
	int age;
}info;

typedef struct node{
	info data;
	struct node* next;
}node, *LL;

info addInfo(){
	info record;
	printf("Enter name: ");
	scanf("%s", record.name);
	printf("Enter ID number: ");
	scanf("%d", &record.idNum);
	printf("Enter age: ");
	scanf("%d", &record.age);
	
	return record;
}	

void insertFirst(LL* head, info data){
	LL temp;
	
	temp = (LL)malloc(sizeof(struct node));
	if(temp != NULL){
		strcpy(temp->data.name, data.name);
		temp->data.idNum = data.idNum;
		temp->data.age = data.age;
		temp->next = *head;
		*head = temp;
	}
}

void insertLast(LL* head, info data){
	LL *trav, temp;
	
	for(trav = head; *trav != NULL; trav = &(*trav)->next){}
	temp = (LL)malloc(sizeof(struct node));
	if(temp != NULL){
		strcpy(temp->data.name, data.name);
		temp->data.idNum = data.idNum;
		temp->data.age = data.age;
		temp->next = NULL;
		*trav = temp;
	}
}

void insertIndex(LL* head, info data){
	LL *trav, temp;
	int ctr = 0;
	
	for(trav = head; *trav != NULL && ctr != 2 ; trav = &(*trav)->next){
		ctr++;
	}
	temp = (LL)malloc(sizeof(struct node));
	if(temp != NULL){
		strcpy(temp->data.name, data.name);
		temp->data.idNum = data.idNum;
		temp->data.age = data.age;
		temp->next = *trav;
		*trav = temp;
	}
}

void deleteFirst(LL* head){
	LL temp;
	
	temp = (LL)malloc(sizeof(struct node));
	if(temp != NULL){
		temp = *head;
		*head = temp->next;
		free(temp);
	}
}

void deleteLast(LL* head){
	LL *trav, temp;
	
	for(trav = head; (*trav)->next != NULL; trav = &(*trav)->next){}
	temp = (LL)malloc(sizeof(struct node));
	if(temp != NULL){
		temp = *trav;
		*trav = NULL;
		free(temp);
	}
}

void displayLL(LL head){
	LL trav;
	int ndx = 0;
	
	printf("\n\n========= LIST =========\n");
	for(trav = head; trav != NULL; trav = trav->next){
		printf("Index: %d\n", ndx);
		printf("Name: %s\n", trav->data.name);
		printf("ID number: %d\n", trav->data.idNum);
		printf("Age: %d", trav->data.age);
		printf("\n\n");
		ndx++;
	}
}


int main(){
	LL head = NULL;
	
	printf("Insert Last:\n");
	insertLast(&head, addInfo());
	insertLast(&head, addInfo());

	printf("\nInsert First:\n");
	insertFirst(&head, addInfo());
	
	printf("\nInsert Last:\n");
	insertLast(&head, addInfo());
	
	printf("\nInsert Index:\n");
	insertIndex(&head, addInfo());
	
	displayLL(head);
	
	printf("\nAfter Delete First:\n");
	deleteFirst(&head);
	displayLL(head);
	
	printf("\nAfter Delete Last:\n");
	deleteLast(&head);
	displayLL(head);
	
	return 0;
}
