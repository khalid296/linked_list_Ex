/************************************************
 *	 File Name: Example.c						*
 * Description: source file for linked list		*
 *  Created on: Sep 19, 2018					*
 *      Author: Khalid Tarek					*
 ************************************************/

#include"linked_list.h"

int main(){
	uint16 mid[2],max[2];
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
	printf("\n%d found at position %d\n", 1, searchByValue(head,1));
	updateByValue(head,1,10);
	deleteNode(&head,5);
	printList(head);
	middleNode(head,mid);
	printf("\nMiddle found at position %d and its data %d\n",mid[0],mid[1]);
	printf("%d found at position %d\n",searchByPos(head,5),5);
	printf("Sum= %d\n",listSum(head));
	listMax(head,max);
	printf("Max found at position %d and its data %d\n",max[0],max[1]);
	return 0;
}
