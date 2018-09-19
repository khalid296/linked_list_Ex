/************************************************
 *   File Name: linked_list.c					*
 * Description: source file for linked list		*
 *  Created on: Sep 19, 2018					*
 *      Author: Khalid Tarek					*
 ************************************************/

#include"linked_list.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

void insertFirst(struct node** headPtr, struct node** tailPtr, uint16 data){
	struct node *link = (struct node *)malloc(sizeof(struct node));
	link->data=data;
	link->next=(*headPtr);
	(*headPtr)=link;

	if((*tailPtr)==NULL){
		(*tailPtr)=link;
	}
}

void insertAtPosition(struct node** headPtr, struct node** tailPtr, uint8 pos, uint16 data){
	uint8 position=1;
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

void insertLast(struct node** headPtr, struct node** tailPtr, uint16 data){
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

void middleNode(const struct node* headPtr, uint16* mid){
	uint8 pos=0,step=0;
	const struct node *ptr1=headPtr;
	const struct node *ptr2=headPtr;
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

uint8 listSize(const struct node* headPtr){
	const struct node *ptr=headPtr;
	uint16 size=0;
	while(ptr!=NULL){
		size++;
		ptr=ptr->next;
	}
	return size;
}

uint16 listSum(const struct node* headPtr){
	const struct node *ptr=headPtr;
	int sum=0;
	while(ptr!=NULL){
		sum+=ptr->data;
		ptr=ptr->next;
	}
	return sum;
}

void listMax(const struct node* headPtr, uint16* max){
	const struct node *ptr=headPtr;
	uint16 maxVal=ptr->data,pos=0,position=0;
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

uint8 searchByValue(const struct node* headPtr, uint16 value){
	const struct node *ptr=headPtr;
	uint8 pos;
	while(ptr!=NULL){
		if(ptr->data==value){
			return pos;
		}
		ptr=ptr->next;
		pos++;
	}
	return -1;
}

uint16 searchByPos(const struct node* headPtr, uint8 pos){
	const struct node *ptr=headPtr;
	uint8 position=0;
	while(ptr!=NULL){
		if(position==pos){
			return ptr->data;
		}
		ptr=ptr->next;
		position++;
	}
	return -1;
}

void updateByValue(struct node* headPtr,uint16 value,uint16 data){
	struct node *ptr=headPtr;
	while(ptr!=NULL){
		if(ptr->data==value){
			ptr->data=data;
			return;
		}
		ptr=ptr->next;
	}
}

void deleteNode(struct node** headPtr,uint16 data){
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

void printList(const struct node* headPtr){
	const struct node *ptr=headPtr;
	printf("Head => ");
	while(ptr!=NULL){
		printf("%d => ",ptr->data);
		ptr=ptr->next;
	}
	printf("NULL");
}
