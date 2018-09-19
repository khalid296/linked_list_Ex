/************************************************
 *   File Name: linked_list.h					*
 * Description: Header file for linked list		*
 *  Created on: Sep 19, 2018					*
 *      Author: Khalid Tarek					*
 ************************************************/

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include<stdio.h>
#include<stdlib.h>
#include"std_types.h"

/*******************************************************************************
 *                   	  Linked list Node declaration	                       *
 *******************************************************************************/

struct node{
	uint16 data;
	struct node *next;
};

/*******************************************************************************
 *                     		 Functions Prototypes  	                           *
 *******************************************************************************/

/*Function to insert a node at the first of the list
 *inputs: pointer to head pointer, pointer to tail pointer, node data
 */
void insertFirst(struct node** headPtr, struct node** tailPtr, uint16 data);

/*Function to insert a node at given position in the list
 *inputs: pointer to head pointer, pointer to tail pointer, position, node data
 */
void insertAtPosition(struct node** headPtr, struct node** tailPtr, uint8 pos, uint16 data);

/*Function to insert a node at the end of the list
 *inputs: pointer to head pointer, pointer to tail pointer, node data
 */
void insertLast(struct node** headPtr, struct node** tailPtr, uint16 data);

/*Function to get the middle value of the list
 *inputs: head pointer, 2 element array for (return by address) data [value, position]
 */
void middleNode(const struct node* headPtr, uint16* mid);

/*Function to get List size
 *inputs: head pointer
 *return:  list size
 */
uint8 listSize(const struct node* headPtr);

/*Function to get Summation of list nodes
 *inputs: head pointer
 *return:  list Summation
 */
uint16 listSum(const struct node* headPtr);

/*Function to get List Maximum node
 *inputs: head pointer, 2 element array for (return by address) data [value, position]
 */
void listMax(const struct node* headPtr, uint16* max);

/*Function to Search for node using its value
 *inputs: head pointer
 *return:  node Position
 */
uint8 searchByValue(const struct node* headPtr, uint16 value);

/*Function to Search for node using its Position
 *inputs: head pointer
 *return:  node Value
 */
uint16 searchByPos(const struct node* headPtr, uint8 pos);

/*Function to update node using its value
 *inputs: head pointer, node new Value
 */
void updateByValue(struct node* headPtr,uint16 value,uint16 data);

/*Function to delete node using its value
 *inputs: head pointer, node Value
 */
void deleteNode(struct node** headPtr,uint16 data);

/*Function to Print list nodes
 *inputs: head pointer
 */
void printList(const struct node* headPtr);

#endif /* LINKED_LIST_H_ */
