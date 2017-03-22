/***************************************************************************************\
*																					   *
* Title: testSuite_ll.c														   		   *
* Author: M. Runyon																	   *
* Last Updated: March 22nd, 2017													   *
* Description: This is a test suite that verifies functionality of some linked list    *
*              functions for Nick Parlante's Linked List Problems (and others).	       *
*																					   *				
****************************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include "llutil.h"

struct node{
	int data;
	struct node* next;
};

int main(void){

	struct node* test = buildOneTwoThree();
	printf("Testing buildOneTwoThree...\n");
	printf("Case 1: Calling buildOneTwoThree()\n");
	printf("Expected result: { 1 2 3 }\n");
	printf("Actual result:   { ");
	while(test != NULL){printf("%d ", test->data);test = test->next;}
	printf("}\n\n");
	free(test);

	test = buildOneTwoThree();
	int n = length(test);
	printf("Testing length()...\n");
	printf("Case 1: Calling length(buildOneTwoThree())\n");
	printf("Expected result: 3\n");
	printf("Actual result:   %d\n\n", n);
	free(test);

	test = buildOneTwoThree();
	push(&test,0);
	struct node* ptr = test;
	struct node* nullTest = NULL;
	printf("Testing push()...\n");
	printf("Case 1: Calling push(&buildOneTwoThree(),0)\n");
	printf("Expected result: { 0 1 2 3 }\n");
	printf("Actual result:   { ");
	while(ptr != NULL){printf("%d ", ptr->data);ptr = ptr->next;}
	printf("}\n");
	printf("Case 2: Calling push(test,0)\n");
	printf("Expected result: { 0 0 1 2 3 }\n");
	printf("Actual result:   { ");
	push(&test,0);
	ptr = test;
	while(ptr != NULL){printf("%d ", ptr->data);ptr = ptr->next;}
	printf("}\n");
	printf("Case 3: Calling push(test,7)\n");
	printf("Expected result: { 7 0 0 1 2 3 }\n");
	printf("Actual result:   { ");
	push(&test,7);
	ptr = test;
	while(ptr != NULL){printf("%d ", ptr->data);ptr = ptr->next;}
	printf("}\n\n");
	printf("Case 4: Calling push(NULL,7)\n");
	printf("Expected result: { 7 }\n");
	printf("Actual result:   { ");
	push(&nullTest,7);
	ptr = nullTest;
	while(ptr != NULL){printf("%d ", ptr->data);ptr = ptr->next;}
	printf("}\n\n");
	free(test);

	test = buildOneTwoThree();
	append(&test,4);
	ptr = test;
	printf("Testing append()...\n");
	printf("Case 1: Calling append(&buildOneTwoThree(),4)\n");
	printf("Expected result: { 1 2 3 4 }\n");
	printf("Actual result:   { ");
	while(ptr != NULL){printf("%d ", ptr->data);ptr = ptr->next;}
	printf("}\n");
	printf("Case 2: Calling append(test,5)\n");
	printf("Expected result: { 1 2 3 4 5 }\n");
	printf("Actual result:   { ");
	append(&test,5);
	ptr = test;
	while(ptr != NULL){printf("%d ", ptr->data);ptr = ptr->next;}
	printf("}\n");
	printf("Case 3: Calling append(test,6)\n");
	printf("Expected result: { 1 2 3 4 5 6 }\n");
	printf("Actual result:   { ");
	append(&test,6);
	ptr = test;
	while(ptr != NULL){printf("%d ", ptr->data);ptr = ptr->next;}
	printf("}\n");
	printf("Case 4: Calling append(NULL,6)\n");
	printf("Expected result: { 6 }\n");
	printf("Actual result:   { ");
	free(test);
	test = NULL;
	append(&test,6);
	ptr = test;
	while(ptr != NULL){printf("%d ", ptr->data);ptr = ptr->next;}
	printf("}\n\n");
	free(test);

	struct node* t1 = malloc(sizeof(struct node));
	struct node* t2 = malloc(sizeof(struct node));
	struct node* t3 = malloc(sizeof(struct node));
	struct node* t4 = malloc(sizeof(struct node));
	struct node* t5 = malloc(sizeof(struct node));

	t1->data = 1;
	t1->next = t2;
	t2->data = 12;
	t2->next = t3;
	t3->data = 12;
	t3->next = t4;
	t4->data = 12;
	t4->next = t5;
	t5->data = 1;
	t5->next = NULL;

	n = count(t1, 1);
	printf("Testing count()...\n");
	printf("Case 1: Calling count(t1, 1).\n");
	printf("Expected result: 2\n");
	printf("Actual result:   %d\n\n", n);
	n = count(t1,12);
	printf("Case 2: Calling count(t1, 12).\n");
	printf("Expected result: 3\n");
	printf("Actual result:   %d\n\n", n);
	n = count(t1,0);
	printf("Case 3: Calling count(t1, 0).\n");
	printf("Expected result: 0\n");
	printf("Actual result:   %d\n\n", n);

	t2->data = 3;
	t3->data = 5;
	t4->data = 7;
	t5->data = 9;
	n = getNth(t1,0);
	printf("Testing getNth()...\n");
	printf("Case 1: Calling getNth(t1, 0).\n");
	printf("Expected result: 1\n");
	printf("Actual result:   %d\n\n", n);
	n = getNth(t1,1);
	printf("Testing getNth()...\n");
	printf("Case 2: Calling getNth(t1, 1).\n");
	printf("Expected result: 3\n");
	printf("Actual result:   %d\n\n", n);
	n = getNth(t1,2);
	printf("Testing getNth()...\n");
	printf("Case 3: Calling getNth(t1, 2).\n");
	printf("Expected result: 5\n");
	printf("Actual result:   %d\n\n", n);
	n = getNth(t1,3);
	printf("Testing getNth()...\n");
	printf("Case 4: Calling getNth(t1, 3).\n");
	printf("Expected result: 7\n");
	printf("Actual result:   %d\n\n", n);
	n = getNth(t1,4);
	printf("Testing getNth()...\n");
	printf("Case 5: Calling getNth(t1, 4).\n");
	printf("Expected result: 9\n");
	printf("Actual result:   %d\n\n", n);

	test = buildOneTwoThree();
	printf("Testing deleteList()...\n");
	printf("Case 1: Delete 'test'.\n");
	printf("Expected result: NULL check successful.\n");
	printf("Actual result:   ");
	deleteList(&test);
	if(test == NULL){
		printf("NULL check successful.\n\n");
	}else{
		printf("NULL check unsuccessful.\n\n");
	}

	printf("Testing insertNth()...\n");
	printf("Case 1: Calling insertNth(t1, 0, 0).\n");
	printf("Expected result: { 0 1 3 5 7 9 }\n");
	printf("Actual result:   { ");
	insertNth(&t1, 0, 0);
	ptr = t1;
	while(ptr != NULL){printf("%d ", ptr->data);ptr = ptr->next;}
	printf("}\n");
	//printf("Testing intermediate insertions ...\n");
	//insertNth(&t1, 2, 2);
	
	printf("Case 2: Calling insertNth(t1, 2, 2).\n");
	printf("Expected result: { 0 1 2 3 5 7 9 }\n");
	printf("Actual result:   { ");
	insertNth(&t1, 2, 2);
	ptr = t1;
	while(ptr != NULL){printf("%d ", ptr->data);ptr = ptr->next;}
	printf("}\n");
	printf("Case 3: Calling insertNth(t1, 4, 4).\n");
	printf("Expected result: { 0 1 2 3 4 5 7 9 }\n");
	printf("Actual result:   { ");
	insertNth(&t1, 4, 4);
	ptr = t1;
	while(ptr != NULL){printf("%d ", ptr->data);ptr = ptr->next;}
	printf("}\n");
	printf("Case 4: Calling insertNth(t1, 6, 6).\n");
	printf("Expected result: { 0 1 2 3 4 5 6 7 9 }\n");
	printf("Actual result:   { ");
	insertNth(&t1, 6, 6);
	ptr = t1;
	while(ptr != NULL){printf("%d ", ptr->data);ptr = ptr->next;}
	printf("}\n");
	printf("Case 5: Calling insertNth(t1, 8, 8).\n");
	printf("Expected result: { 0 1 2 3 4 5 6 7 8 9 }\n");
	printf("Actual result:   { ");
	insertNth(&t1, 8, 8);
	ptr = t1;
	while(ptr != NULL){printf("%d ", ptr->data);ptr = ptr->next;}
	printf("}\n");
	printf("Case 6: Calling insertNth(t1, 10, 10).\n");
	printf("Expected result: { 0 1 2 3 4 5 6 7 8 9 10 }\n");
	printf("Actual result:   { ");
	insertNth(&t1, 10, 10);
	ptr = t1;
	while(ptr != NULL){printf("%d ", ptr->data);ptr = ptr->next;}
	printf("}\n\n");
	ptr = t1;
	
	deleteList(&t1);
	t1 = NULL;
	push(&t1,9);
	push(&t1,7);
	push(&t1,5);
	push(&t1,3);
	push(&t1,1);
	n = pop(&t1);
	printf("Testing pop()...\n");
	printf("Case 1: Calling pop(t1).\n");
	printf("Expected result: data: 1 length: 4\n");
	printf("Actual result:   data: %d length: %d\n",n, length(t1));
	n = pop(&t1);
	printf("Case 2: Calling pop(t1) (again).\n");
	printf("Expected result: data: 3 length: 3\n");
	printf("Actual result:   data: %d length: %d\n",n, length(t1));
	n = pop(&t1);
	printf("Case 3: Calling pop(t1) (again).\n");
	printf("Expected result: data: 5 length: 2\n");
	printf("Actual result:   data: %d length: %d\n",n, length(t1));
	n = pop(&t1);
	printf("Case 4: Calling pop(t1) (again).\n");
	printf("Expected result: data: 7 length: 1\n");
	printf("Actual result:   data: %d length: %d\n",n, length(t1));
	n = pop(&t1);
	printf("Case 5: Calling pop(t1) (again).\n");
	printf("Expected result: data: 9 length: 0\n");
	printf("Actual result:   data: %d length: %d\n",n, length(t1));
	printf("Case 6: Calling pop(t1) (again).\n");
	printf("Expected result: data: 0 length: 0.\n");
	n = pop(&t1);
	printf("Actual result:   data: %d length: %d\n\n",n, length(t1));

	push(&t1,9);
	push(&t1,7);
	push(&t1,5);
	push(&t1,3);
	push(&t1,1);
	nullTest = NULL;
	printf("Testing sortedInsert()...\n");
	printf("Case 1: Calling sortedInsert(t1,2).\n");
	printf("Expected result: { 1 2 3 5 7 9 }\n");
	printf("Actual result:   { ");
	push(&nullTest,2);
	sortedInsert(&t1, nullTest);
	ptr = t1;
	while(ptr != NULL){printf("%d ", ptr->data);ptr = ptr->next;}
	printf("}\n");
	printf("Case 2: Calling sortedInsert(t1,4).\n");
	printf("Expected result: { 1 2 3 4 5 7 9 }\n");
	printf("Actual result:   { ");
	nullTest = NULL;
	push(&nullTest,4);
	sortedInsert(&t1, nullTest);
	ptr = t1;
	while(ptr != NULL){printf("%d ", ptr->data);ptr = ptr->next;}
	printf("}\n");
	printf("Case 3: Calling sortedInsert(t1,6).\n");
	printf("Expected result: { 1 2 3 4 5 6 7 9 }\n");
	printf("Actual result:   { ");
	nullTest = NULL;
	push(&nullTest,6);
	sortedInsert(&t1, nullTest);
	ptr = t1;
	while(ptr != NULL){printf("%d ", ptr->data);ptr = ptr->next;}
	printf("}\n");
	printf("Case 4: Calling sortedInsert(t1,8).\n");
	printf("Expected result: { 1 2 3 4 5 6 7 8 9 }\n");
	printf("Actual result:   { ");
	nullTest = NULL;
	push(&nullTest,8);
	sortedInsert(&t1, nullTest);
	ptr = t1;
	while(ptr != NULL){printf("%d ", ptr->data);ptr = ptr->next;}
	printf("}\n");
	printf("Case 5: Calling sortedInsert(t1,10).\n");
	printf("Expected result: { 1 2 3 4 5 6 7 8 9 10 }\n");
	printf("Actual result:   { ");
	nullTest = NULL;
	push(&nullTest,10);
	sortedInsert(&t1,nullTest);
	ptr = t1;
	while(ptr != NULL){printf("%d ", ptr->data);ptr = ptr->next;}
	printf("}\n");
	printf("Case 5: Calling sortedInsert(t1,0).\n");
	printf("Expected result: { 0 1 2 3 4 5 6 7 8 9 10 }\n");
	printf("Actual result:   { ");
	nullTest = NULL;
	push(&nullTest,0);
	sortedInsert(&t1, nullTest);
	ptr = t1;
	while(ptr != NULL){printf("%d ", ptr->data);ptr = ptr->next;}
	printf("}\n\n");

	deleteList(&t1);

	push(&t1,-3);
	push(&t1,7);
	push(&t1,2);
	push(&t1,-1);
	push(&t1,100);
	push(&t1,-1);
	push(&t1,101);
	nullTest = NULL;
	printf("Testing insertSort()...\n");
	printf("Case 1: Calling insertSort(t1).\n");
	printf("Expected result: { -3 -1 -1 2 7 100 101 }\n");
	printf("Actual result:   { ");
	insertSort(&t1);
	ptr = t1;
	while(ptr != NULL){printf("%d ", ptr->data);ptr = ptr->next;}
	printf("}\n");
	
	deleteList(&t1);

	push(&t1,-1);
	push(&t1,-1);
	push(&t1,-1);
	push(&t1,-1);
	push(&t1,-1);
	push(&t1,-1);
	push(&t1,-1);
	printf("Case 2: Calling insertSort(t1).\n");
	printf("Expected result: { -1 -1 -1 -1 -1 -1 -1 }\n");
	printf("Actual result:   { ");
	insertSort(&t1);
	ptr = t1;
	while(ptr != NULL){printf("%d ", ptr->data);ptr = ptr->next;}
	printf("}\n\n");
	
	deleteList(&t1);
	t1 = NULL;
	t2 = NULL;
	push(&t1,3);
	push(&t1,8);
	push(&t1,1);
	push(&t2,1);
	push(&t2,2);
	push(&t2,3);
	printf("Testing cat()...\n");
	printf("Case 1: Calling cat(t1,t2).\n");
	printf("Expected result: { 1 8 3 3 2 1 }\n");
	printf("Actual result:   { ");
	cat(&t1,&t2);
	ptr = t1;
	while(ptr != NULL){printf("%d ", ptr->data);ptr = ptr->next;}
	printf("}\n");
	deleteList(&t1);
	t1 = NULL;
	push(&t2,1);
	push(&t2,2);
	push(&t2,3);
	printf("Case 2: Calling cat(t1,t2).\n");
	printf("Expected result: { 3 2 1 }\n");
	printf("Actual result:   { ");
	cat(&t1,&t2);
	ptr = t1;
	while(ptr != NULL){printf("%d ", ptr->data);ptr = ptr->next;}
	printf("}\n");
	deleteList(&t2);
	printf("Case 3: Calling cat(t1,t2).\n");
	printf("Expected result: { 3 2 1 }\n");
	printf("Actual result:   { ");
	cat(&t1,&t2);
	ptr = t1;
	while(ptr != NULL){printf("%d ", ptr->data);ptr = ptr->next;}
	printf("}\n\n");
	free(t1);
	free(t2);
	free(t3);
	free(t4);

	t1 = NULL;
	t2 = NULL;
	t3 = NULL;
	t4 = NULL;
	struct node* dummy1;
	struct node* dummy2;
	push(&t1,1);
	push(&t2,2);
	push(&t2,1);
	push(&t3,3);
	push(&t3,2);
	push(&t3,1);
	push(&t4,6);
	push(&t4,5);
	push(&t4,4);
	push(&t4,3);
	push(&t4,2);
	push(&t4,1);
	printf("Testing frontBackSplit()...\n");
	printf("Case 1: Calling frontBackSplit({1},&dummy1,&dummy2).\n");
	printf("Expected result: { Warning: Cannot split a list of length < 2.\n}\n");
	printf("Actual result:   { ");
	frontBackSplit(t1,&dummy1,&dummy2);
	printf("}\n");
	printf("Case 2: Calling frontBackSplit({1 2},&dummy1,&dummy2).\n");
	printf("Expected result: { f: 1 b: 2 }\n");
	printf("Actual result:   { f: ");
	frontBackSplit(t2,&dummy1,&dummy2);
	ptr = dummy1;
	while(ptr != NULL){printf("%d ", ptr->data);ptr = ptr->next;}
	ptr = dummy2;
	printf("b: ");
	while(ptr != NULL){printf("%d ", ptr->data);ptr = ptr->next;}
	printf("}\n");
	printf("Case 3: Calling frontBackSplit({1 2 3},&dummy1,&dummy2).\n");
	printf("Expected result: { f: 1 2 b: 3 }\n");
	printf("Actual result:   { f: ");
	frontBackSplit(t3,&dummy1,&dummy2);
	ptr = dummy1;
	while(ptr != NULL){printf("%d ", ptr->data);ptr = ptr->next;}
	ptr = dummy2;
	printf("b: ");
	while(ptr != NULL){printf("%d ", ptr->data);ptr = ptr->next;}
	printf("}\n");
	printf("Case 4: Calling frontBackSplit({1 2 3 4 5 6},&dummy1,&dummy2).\n");
	printf("Expected result: { f: 1 2 3 b: 4 5 6 }\n");
	printf("Actual result:   { f: ");
	frontBackSplit(t4,&dummy1,&dummy2);
	ptr = dummy1;
	while(ptr != NULL){printf("%d ", ptr->data);ptr = ptr->next;}
	ptr = dummy2;
	printf("b: ");
	while(ptr != NULL){printf("%d ", ptr->data);ptr = ptr->next;}
	printf("}\n\n");
	
	deleteList(&t1);
	t1 = NULL;
	push(&t1,10);
	push(&t1,9);
	push(&t1,8);
	push(&t1,7);
	push(&t1,6);
	push(&t1,5);
	push(&t1,4);
	push(&t1,3);
	push(&t1,2);
	push(&t1,1);
	printf("Testing deleteNth()...\n");
	printf("Case 1: Calling deleteNth({1,2,3,4,5,6,7,8,9,10},9).\n");
	printf("Expected result: { 1 2 3 4 5 6 7 8 9 }\n");
	printf("Actual result:   { ");
	deleteNth(&t1,9);
	ptr = t1;
	while(ptr != NULL){printf("%d ", ptr->data);ptr = ptr->next;}
	printf("}\n");
	printf("Case 2: Calling deleteNth({1,2,3,4,5,6,7,8,9},0).\n");
	printf("Expected result: { 2 3 4 5 6 7 8 9 }\n");
	printf("Actual result:   { ");
	deleteNth(&t1,0);
	ptr = t1;
	while(ptr != NULL){printf("%d ", ptr->data);ptr = ptr->next;}
	printf("}\n");
	printf("Case 3: Calling deleteNth({2,3,4,5,6,7,8,9},4).\n");
	printf("Expected result: { 2 3 4 5 7 8 9 }\n");
	printf("Actual result:   { ");
	deleteNth(&t1,4);
	ptr = t1;
	while(ptr != NULL){printf("%d ", ptr->data);ptr = ptr->next;}
	printf("}\n");
	printf("Case 4: Calling deleteNth({2,3,4,5,7,8,9},1).\n");
	printf("Expected result: { 2 4 5 7 8 9 }\n");
	printf("Actual result:   { ");
	deleteNth(&t1,1);
	ptr = t1;
	while(ptr != NULL){printf("%d ", ptr->data);ptr = ptr->next;}
	printf("}\n");
	printf("Case 5: Calling deleteNth({2,4,5,7,8,9},6).\n");
	printf("Expected result: Warning: Invalid index called in deleteNth().\n{2 4 5 7 8 9}\n");
	printf("Actual result:   { ");
	deleteNth(&t1,6);
	ptr = t1;
	while(ptr != NULL){printf("%d ", ptr->data);ptr = ptr->next;}
	printf("}\n\n");
	
	deleteList(&t1);
	deleteList(&t2);
	deleteList(&t3);
	deleteList(&t4);
	t1 = NULL;
	t2 = NULL;
	t3 = NULL;
	t4 = NULL;
	t5 = NULL;
	push(&t1,1);
	push(&t1,1);
	push(&t1,1);
	push(&t1,1);
	push(&t2,6);
	push(&t2,1);
	push(&t2,2);
	push(&t2,3);
	push(&t2,4);
	push(&t2,5);
	push(&t2,6);
	push(&t3,1);
	push(&t3,1);
	push(&t3,1);
	push(&t3,4);
	push(&t3,5);
	push(&t3,6);
	push(&t3,6);
	push(&t4,4);
	push(&t4,2);
	push(&t4,3);
	push(&t4,2);
	push(&t4,1);
	push(&t5,0);
	push(&t5,0);
	push(&t5,1);
	printf("Testing removeDuplicates()...\n");
	printf("Case 1: Calling removeDuplicates({1,0,0}).\n");
	printf("Expected result: { 1 0 }\n");
	printf("Actual result:   { ");
	removeDuplicates(&t5);
	ptr = t5;
	while(ptr != NULL){printf("%d ", ptr->data);ptr = ptr->next;}
	printf("}\n");
	printf("Case 2: Calling removeDuplicates({1,2,3,2,4}).\n");
	printf("Expected result: { 1 2 3 4 }\n");
	printf("Actual result:   { ");
	removeDuplicates(&t4);
	ptr = t4;
	while(ptr != NULL){printf("%d ", ptr->data);ptr = ptr->next;}
	printf("}\n");
	printf("Case 3: Calling removeDuplicates({6,5,4,3,2,1,6}).\n");
	printf("Expected result: { 6 5 4 3 2 1 }\n");
	printf("Actual result:   { ");
	removeDuplicates(&t2);
	ptr = t2;
	while(ptr != NULL){printf("%d ", ptr->data);ptr = ptr->next;}
	printf("}\n");
	printf("Case 4: Calling removeDuplicates({1,1,1,1}).\n");
	printf("Expected result: { 1 }\n");
	printf("Actual result:   { ");
	removeDuplicates(&t1);
	ptr = t1;
	while(ptr != NULL){printf("%d ", ptr->data);ptr = ptr->next;}
	printf("}\n");
	printf("Case 5: Calling removeDuplicates({6,6,5,4,1,1,1}).\n");
	printf("Expected result: { 6 5 4 1 }\n");
	printf("Actual result:   { ");
	removeDuplicates(&t3);
	ptr = t3;
	while(ptr != NULL){printf("%d ", ptr->data);ptr = ptr->next;}
	printf("}\n\n");
	free(t1);
	free(t2);
	free(t3);
	free(t4);
	free(t5);

	return 0;
}
