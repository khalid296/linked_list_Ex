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

struct node *head=NULL;
struct node *tail=NULL;

void insertFirst(int data);
void insertLast(int data);
int findSize(const struct node *ptr);
int searchForItem(const struct node *ptr,int item);
void updateItem(struct node *ptr,int item,int data);
void deleteNode(struct node *ptr,int data);
void printList(struct node *ptr);

int main(){
	insertLast(1);
	insertFirst(2);
	insertLast(3);
	insertLast(4);
	insertFirst(5);
	printList(head);
	printf("\nSize= %d",findSize(head));
	printf("\n%d found at position %d\n", 1, searchForItem(head,1));
	updateItem(head,1,10);
	deleteNode(head,5);
	printList(head);
	return 0;
}

void insertFirst(int data){

	struct node *link = (struct node *)malloc(sizeof(struct node));
	link->data=data;
	link->next=head;
	head=link;
	if(tail==NULL){
		tail=link;
	}

}

void insertLast(int data){
	if(head==NULL){
		insertFirst(data);
	}else{
		struct node *link = (struct node *)malloc(sizeof(struct node));
		link->data=data;
		tail->next=link;
		link->next=NULL;
		tail=link;
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

void deleteNode(struct node *ptr,int data){
	struct node *current=ptr;
	struct node *previous=NULL;
	if(current->data==data){
		head=current->next;
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
