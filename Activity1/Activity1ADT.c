#include <stdio.h>
#include <stdlib.h>

typedef struct{
	char fName[20];
	char lName[20];
}studName;

typedef struct{
	int month;
	int year;
}bday;

typedef struct{
	studName name;
	bday birthdate;
	int age;
	int idNum;
}StudentInfo;

typedef struct{
	StudentInfo studList[20];
	int studCount;
}classRecord;

void initList(classRecord* record){
	record->studCount = 0;
}

void insertFirst(classRecord* record){
	int i;
	classRecord temp;
	initList(&temp);
	
	if(record->studCount < 20){
		printf("\nEnter first name: ");
		scanf("%s", temp.studList[temp.studCount].name.fName);
		printf("Enter last name: ");
		scanf("%s", temp.studList[temp.studCount].name.lName);
		printf("Enter birth month: ");
		scanf("%d", &temp.studList[temp.studCount].birthdate.month);
		printf("Enter birth year: ");
		scanf("%d", &temp.studList[temp.studCount].birthdate.year);
		printf("Enter age: ");
		scanf("%d", &temp.studList[temp.studCount].age);
		printf("Enter ID number: ");
		scanf("%d", &temp.studList[temp.studCount].idNum);
		
		for(i = record->studCount; i > 0; i--){
			record->studList[i] = record->studList[i-1];
		}
		record->studList[i] = temp.studList[temp.studCount];		
		record->studCount++;
	}
}

void insertLast(classRecord* record){
	if(record->studCount < 20){
		printf("\nEnter first name: ");
		scanf("%s", record->studList[record->studCount].name.fName);
		printf("Enter last name: ");
		scanf("%s", record->studList[record->studCount].name.lName);
		printf("Enter birth month: ");
		scanf("%d", &record->studList[record->studCount].birthdate.month);
		printf("Enter birth year: ");
		scanf("%d", &record->studList[record->studCount].birthdate.year);
		printf("Enter age: ");
		scanf("%d", &record->studList[record->studCount].age);
		printf("Enter ID number: ");
		scanf("%d", &record->studList[record->studCount].idNum);
		
		record->studCount++;	
	}
}

void insertIndex(classRecord* record){
	int ndx, i;
	classRecord temp;
	initList(&temp);
	
	if(record->studCount < 20){
		printf("\nInsert at what index? ");
		scanf("%d", &ndx);
		printf("Enter first name: ");
		scanf("%s", temp.studList[temp.studCount].name.fName);
		printf("Enter last name: ");
		scanf("%s", temp.studList[temp.studCount].name.lName);
		printf("Enter birth month: ");
		scanf("%d", &temp.studList[temp.studCount].birthdate.month);
		printf("Enter birth year: ");
		scanf("%d", &temp.studList[temp.studCount].birthdate.year);
		printf("Enter age: ");
		scanf("%d", &temp.studList[temp.studCount].age);
		printf("Enter ID number: ");
		scanf("%d", &temp.studList[temp.studCount].idNum);
		
		for(i = record->studCount; i != ndx; i--){
			record->studList[i] = record->studList[i-1];
		}
		record->studList[i] = temp.studList[temp.studCount];		
		record->studCount++;
	}
}

void insertSorted(classRecord* record){
	int i, age;
	classRecord temp;
	initList(&temp);
	
	if(record->studCount < 20){
		if(record->studCount < 20){
			printf("\nEnter first name: ");
			scanf("%s", temp.studList[temp.studCount].name.fName);
			printf("Enter last name: ");
			scanf("%s", temp.studList[temp.studCount].name.lName);
			printf("Enter birth month: ");
			scanf("%d", &temp.studList[temp.studCount].birthdate.month);
			printf("Enter birth year: ");
			scanf("%d", &temp.studList[temp.studCount].birthdate.year);
			printf("Enter age: ");
			scanf("%d", &temp.studList[temp.studCount].age);
			printf("Enter ID number: ");
			scanf("%d", &temp.studList[temp.studCount].idNum);
				
			age = temp.studList[temp.studCount].age;
			for(i = record->studCount-1; i >= 0 && age <= record->studList[i].age; i--){
				record->studList[i+1] = record->studList[i];
			}
			
			record->studList[i+1] = temp.studList[temp.studCount];	
			record->studCount++;	
		}
	}
}

void deleteFirst(classRecord* record){
	int i;
	StudentInfo temp;
	
	if(record->studCount > 0){
		temp = record->studList[0];
		for(i = 0; i < record->studCount; i++){
			record->studList[i] = record->studList[i+1];
		}
		record->studCount--;
	}
}

void deleteLast(classRecord* record){
	if(record->studCount > 0){
		record->studCount--;
	}
}

void deleteIndex(classRecord* record){
	int ndx, i;
	StudentInfo temp;
	
	printf("What index do you want to delete?");
	scanf("%d", &ndx);
	
	if(record->studCount > 0){
		for(i = ndx; i < record->studCount; i++){
			record->studList[i] = record->studList[i+1];
		}
		record->studCount--;
	}
}

void display(classRecord record){
	int i;
	printf("\n=========== CLASS RECORD ===========\n");
	
	printf("Number of record: %d\n\n", record.studCount);
	for(i = 0; i < record.studCount; i++){
		printf("First Name: %s", record.studList[i].name.fName);
		printf("\nLast Name: %s", record.studList[i].name.lName);
		printf("\nBirthdate: %d %d", record.studList[i].birthdate.month, record.studList->birthdate.year);
		printf("\nAge: %d", record.studList[i].age);
		printf("\nID Number: %d", record.studList[i].idNum);	
		printf("\n\n");
	}	
}

int main(){
	classRecord record;
	
	initList(&record);
	
	insertLast(&record);
	insertLast(&record);
	insertFirst(&record);
//	insertIndex(&record);
//	insertSorted(&record);
//	system("cls");
	display(record);
//	deleteLast(&record);
//	deleteFirst(&record);
//	deleteFirst(&record);
	deleteIndex(&record);
	display(record);
	
	return 0;
}
