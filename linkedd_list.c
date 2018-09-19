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
void insertAtPosition(struct node **headPtr,struct node **tailPtr,int pos,int data);
void middleNode(const struct node *ptr,int*mid);
void insertLast(struct node **headPtr,struct node **tailPtr,int data);
int listSize(const struct node *ptr);
int listSum(const struct node *ptr);
void listMax(const struct node *ptr,int*max);
int searchForItem(const struct node *ptr,int item);
int searchForPos(const struct node *ptr,int pos);
void updateItem(struct node *ptr,int item,int data);
void deleteNode(struct node **ptr,int data);
void printList(struct node *ptr);

int main(){
	int mid[2],max[2];
	struct node *head=NULL;
	struct node *tail=NULL;

	insertLast(&head,&tail,1);
	insertFirst(&head,&tail,2);
	insertLast(&head,&tail,3);
	insertLast(&head,&tail,4);
	insertFirst(&head,&tail,5);
	insertAtPosition(&head,&tail,0,15);
	insertAtPosition(&head,&tail,4,8);
	insertAtPosition(&head,&tail,7,20);

	printList(head);
	printf("\nSize= %d",listSize(head));
	printf("\n%d found at position %d\n", 1, searchForItem(head,1));
	updateItem(head,1,10);
	deleteNode(&head,5);
	printList(head);
	middleNode(head,mid);
	printf("\nmiddle found at position %d and its data %d\n",mid[0],mid[1]);
	printf("\n%d found at position %d\n",searchForPos(head,5),5);
	printf("\nSum= %d",listSum(head));
	listMax(head,max);
	printf("\nMax found at position %d and its data %d\n",max[0],max[1]);
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

void insertAtPosition(struct node **headPtr,struct node **tailPtr,int pos,int data){
	int position=1;
	struct node *current=(*headPtr);
	struct node *previous=NULL;
	if(pos==0){
		insertFirst(headPtr,tailPtr,data);
		return;
	}
	while(current!=NULL){
		if(position==pos){
			if(current->next==NULL){
				insertLast(headPtr,tailPtr,data);
			}else{
				struct node *link = (struct node *)malloc(sizeof(struct node));
				link->data=data;
				previous->next=link;
				link->next=current;
			}
			return;
		}
		previous=current;
		current=current->next;
		position++;
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

int listSize(const struct node *ptr){
	int size=0;
	while(ptr!=NULL){
		size++;
		ptr=ptr->next;
	}
	return size;
}

int listSum(const struct node *ptr){
	int sum=0;
	while(ptr!=NULL){
		sum+=ptr->data;
		ptr=ptr->next;
	}
	return sum;
}

void listMax(const struct node *ptr,int*max){
	int maxVal=ptr->data,pos=0,position=0;
	while(ptr!=NULL){
		if(ptr->data>maxVal){
			maxVal=ptr->data;
			pos=position;
		}
		ptr=ptr->next;
		position++;
	}
	*(max+0)=pos;
	*(max+1)=maxVal;
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

int searchForPos(const struct node *ptr,int pos){
	int position=0;
	while(ptr!=NULL){
		if(position==pos){
			return ptr->data;
		}
		ptr=ptr->next;
		position++;
	}
	return -1;
}

void middleNode(const struct node *ptr,int*mid){
	char pos=0,step=0;
	const struct node *ptr1=ptr;
	const struct node *ptr2=ptr;
	while(ptr1->next!=NULL){
		ptr1=ptr1->next;
		step++;
		if(step==2){
			ptr2=ptr2->next;
			step=0;
			pos++;
		}
	}
	*(mid+1)=ptr2->data;
	*(mid+0)=pos;
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
