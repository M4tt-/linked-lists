/***************************************************************************************\
*																					   *
* Title: llutil.c														   			   *
* Author: M. Runyon																	   *
* Last Updated: March 22nd, 2017													   *
* Description: This is an implementation file that provides utility functions for	   * 
*			   Nick Parlante's Linked List Exercises (see linkedListProblems.c).       *
*			   All are written by myself except for insertSort().					   *
*			   There are also functions here that are not in Nick Parlante's list,     *
*              namely deleteNth().													   *
*																					   *				
\***************************************************************************************/
#include <stdlib.h>
#include <stdio.h>
/**************************************************************************\
*								STRUCT: NODE							  *
\**************************************************************************/
struct node{
	int data;
	struct node* next;
};

/**************************************************************************\
*								FUNCTION: LENGTH()						  *
\**************************************************************************/
int length(struct node* head){

	int count = 0;
	struct node* current = head;
	while(current != NULL){
		++count;
		current = current->next;
	}
	return count;
}

/**************************************************************************\
*							FUNCTION: BUILDONETWOTHREE()				  *
\**************************************************************************/
struct node* buildOneTwoThree(void){
	struct node* one = NULL;
	struct node* two = NULL;
	struct node* three = NULL;

	one = malloc(sizeof(struct node));
	two = malloc(sizeof(struct node));
	three = malloc(sizeof(struct node));

	one->data = 1;
	one->next = two;
	two->data = 2;
	two->next = three;
	three->data = 3;
	three->next = NULL;

	return one;
}

/**************************************************************************\
*							FUNCTION: PUSH()				  			  *
\**************************************************************************/
void push(struct node** headRef, int data) {
	struct node* newNode = malloc(sizeof(struct node));
	newNode->data = data;
	newNode->next = *headRef;
	*headRef = newNode;
}

/**************************************************************************\
*							FUNCTION: APPEND()				  			  *
\**************************************************************************/
void append(struct node** headRef, int data) {
	struct node* newNode = malloc(sizeof(struct node));
	struct node* current = *headRef;

	newNode->data = data;
	newNode->next = NULL;

	if (current == NULL) {
		*headRef = newNode;
	}
	else{
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = newNode;
	}
}

/**************************************************************************\
*							FUNCTION: COUNT()				  			  *
\**************************************************************************/
int count(struct node* head, int search) {
	struct node* current = malloc(sizeof(struct node));
	current = head;
	int count = 0;
	while(current != NULL){
		if(current->data==search)
			++count;
		current = current->next;
	}
	free(current);
	return count;
}

/**************************************************************************\
*							FUNCTION: GETNTH()				  			  *
\**************************************************************************/
int getNth(struct node* head, int index) {
	if(index >= length(head) || index < 0){
		printf("Invalid index value. Returning zero.\n");
		return 0;
	}else{
		int i = 0;
		int nth = 0;
		struct node* search = malloc(sizeof(struct node));
		search = head;
		while(i < index){
			search = search->next;
			++i;
		}
		nth = search->data;
		return nth;
	}
}

/**************************************************************************\
*							FUNCTION: DELETELIST()			  			  *
\**************************************************************************/
void deleteList(struct node** headRef) {
	struct node* temp = *headRef;
	struct node* next;
    while(temp != NULL){
        next = temp->next;
        free(temp);
        temp = next;
    }
	*headRef = NULL;
}

/**************************************************************************\
*							FUNCTION: POP()			  					  *
\**************************************************************************/
int pop(struct node** headRef){
	if(*headRef == NULL){
		printf("Warning: attempting to pop() NULL pointer. Returning 0.\n");
		return 0;
	}else{
		int result = 0;
		struct node* ptr = malloc(sizeof(struct node));
		ptr = *headRef;
		result = ptr->data;
		*headRef = ptr->next;
		free(ptr);
		return result;
	}
}

/**************************************************************************\
*							FUNCTION: INSERTNTH()	  					  *
\**************************************************************************/
void insertNth(struct node** headRef, int index, int data){
	if(index >length(*headRef)){
		printf("Warning: attempting to insert at invalid index failed.\n");
	}else{
		if(index == 0){
			push(headRef,data);
		}else if(index == length(*headRef)){
			append(headRef,data);
		}else{
			int i = 0;
			struct node* newNode = malloc(sizeof(struct node));
			struct node* ptrBehind = malloc(sizeof(struct node*));
			struct node* ptrAhead = malloc(sizeof(struct node*));
			ptrBehind = *headRef;
			ptrAhead = *headRef;
			while(i < index-1){
				ptrBehind = (ptrBehind)->next;
				ptrAhead = (ptrAhead)->next;
				++i;
			}
			ptrAhead = (ptrAhead)->next;
			newNode->data = data;
			newNode->next = ptrAhead;
			ptrBehind->next = newNode;
		}
	}
}

/**************************************************************************\
*							FUNCTION: SORTEDINSERT()  					  *
\**************************************************************************/
void sortedInsert(struct node** headRef, struct node* newNode){
	struct node* search = malloc(sizeof(struct node));
	search = *headRef;
	int count = 0;
	while(search != NULL){
		if(search->data > newNode->data)
			break;
		++count;
		search = search->next;
	}
	if(search != NULL)
		insertNth(headRef,count,newNode->data);
	else
		append(headRef,newNode->data);
}

/**************************************************************************\
*							FUNCTION: INSERTSORT()  					  *
\**************************************************************************/
void insertSort(struct node** headRef){
	struct node* result = NULL;
	struct node* current = *headRef;
	struct node* next;
	while (current!=NULL) {
		next = current->next;
		sortedInsert(&result, current);
		current = next;
	}
	*headRef = result;
}

/**************************************************************************\
*							FUNCTION: CAT()  							  *
\**************************************************************************/
void cat(struct node** aRef, struct node** bRef){
	struct node* aIter = *aRef;
	struct node* bIter = *bRef;
	int bLen = length(bIter);
	for(int i = 0; i < bLen; ++i){
		append(aRef, bIter->data);
		bIter = bIter->next;
	}
	deleteList(bRef);
}

/**************************************************************************\
*							FUNCTION: FRONTBACKSPLIT()					  *
\**************************************************************************/
void frontBackSplit(struct node* source, struct node** frontRef, struct node** backRef){
	struct node* ptr1 = source;
	struct node* ptr2 = source;
	int len = length(source);
	if(len < 2){
		printf("Warning: Cannot split a list of length < 2.\n");
	}else{
		if(len%2 != 0)
			len = len+1;
		for(int i = 0; i < len/2-1;++i){
			ptr1 = ptr1->next;
			ptr2 = ptr2->next;
		}
		//printf("\nPrinting value after length/2 iteration: %d\n\n",ptr1->data);
		*backRef = ptr2->next;
		ptr1->next = NULL;
		*frontRef = source;	
	}
}

/**************************************************************************\
*							FUNCTION: DELETENTH()						  *
\**************************************************************************/
void deleteNth(struct node** headRef,int target){
	struct node* current = *headRef;
	struct node* next = (*headRef)->next;
	struct node* prev = *headRef;
	int len = length(*headRef);
	if(target < 0 || target > len - 1){
		printf("Warning: Invalid index called in deleteNth().\n");
	}else if(target == 0){
		*headRef = next;
		free(current);
	}else{
		for(int i = 0; i < target; ++i){
			if(i != 0)
				prev = prev->next;
			current = current->next;
			next = next->next;
		}
		prev->next = next;
		free(current);
	}
}

/**************************************************************************\
*							FUNCTION: REMOVEDUPLICATES()				  *
\**************************************************************************/
void removeDuplicates(struct node** head){
	struct node* currentNode = *head;
	struct node* runningNode = (*head)->next;
	struct node* runningNodePrev = *head;
	int count = -1;
	while(currentNode->next != NULL){
		count++;
		if(count){
			currentNode = currentNode->next;
			runningNodePrev = currentNode;
			runningNode = currentNode->next;
		}
		while(runningNode != NULL){
			if(runningNode->data == currentNode->data){
				runningNodePrev->next = runningNode->next;
				free(runningNode);
				runningNode = runningNodePrev->next;
			}else{
				runningNodePrev = runningNodePrev->next;
				runningNode = runningNode->next;
			}
		}
	}
}
