/*
 * linkedd_list.c
 *
 *  Created on: Sep 19, 2018
 *      Author: khali
 */

#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

void insertFirst(struct node **headPtr,struct node **tailPtr,int data);
void insertAtPosition(struct node *headPtr,struct node *tailPtr,int pos,int data);

void insertLast(struct node **headPtr,struct node **tailPtr,int data);
int findSize(const struct node *ptr);
int searchForItem(const struct node *ptr,int item);
void updateItem(struct node *ptr,int item,int data);
void deleteNode(struct node **ptr,int data);
void printList(struct node *ptr);

int main(){
	struct node *head=NULL;
	struct node *tail=NULL;

	insertLast(&head,&tail,1);
	insertFirst(&head,&tail,2);
	insertLast(&head,&tail,3);
	insertLast(&head,&tail,4);
	insertFirst(&head,&tail,5);
	printList(head);
	printf("\nSize= %d",findSize(head));
	printf("\n%d found at position %d\n", 1, searchForItem(head,1));
	updateItem(head,1,10);
	deleteNode(&head,5);
	printList(head);
	return 0;
}

void insertFirst(struct node **headPtr,struct node **tailPtr,int data){
	struct node *link = (struct node *)malloc(sizeof(struct node));
	link->data=data;
	link->next=(*headPtr);
	(*headPtr)=link;
	//printf("DATA, %d",headPtr->data);
	if((*tailPtr)==NULL){
		(*tailPtr)=link;
	}
}

void insertLast(struct node **headPtr,struct node **tailPtr,int data){
	if(*headPtr==NULL){
		insertFirst(headPtr,tailPtr,data);
	}else{
		struct node *link = (struct node *)malloc(sizeof(struct node));
		link->data=data;
		(*tailPtr)->next=link;
		link->next=NULL;
		(*tailPtr)=link;
	}
}

int findSize(const struct node *ptr){
	int size=0;
	while(ptr!=NULL){
		size++;
		ptr=ptr->next;
	}
	return size;
}

int searchForItem(const struct node *ptr,int item){
	int pos;
	while(ptr!=NULL){
		if(ptr->data==item){
			return pos;
		}
		ptr=ptr->next;
		pos++;
	}
	return -1;
}

void updateItem(struct node *ptr,int item,int data){
	while(ptr!=NULL){
		if(ptr->data==item){
			ptr->data=data;
			return;
		}
		ptr=ptr->next;
	}
}

void deleteNode(struct node **headPtr,int data){
	struct node *current=(*headPtr);
	struct node *previous=NULL;
	if(current->data==data){
		(*headPtr)=current->next;
		free(current);
		return;
	}
	while(current!=NULL){
		if(current->data==data){
			previous->next=current->next;
			free(current);
			return;
		}
		previous=current;
		current=current->next;
	}
}

void printList(struct node *ptr){
	printf("Head => ");
	while(ptr!=NULL){
		printf("%d => ",ptr->data);
		ptr=ptr->next;
	}
	printf("NULL");
}
