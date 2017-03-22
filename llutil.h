/***************************************************************************************\
*																					   *
* Title: llutil.h														   			   *
* Author: M. Runyon																	   *
* Last Updated: March 22nd, 2017													   *
* Description: This is a header file that provides utility functions for	           * 
*			   Nick Parlante's Linked List Exercises (see linkedListProblems.c).       *
*			   There are also functions here that are not in Nick Parlante's list,     *
*              namely deleteNth().													   *
*																					   *				
****************************************************************************************/

int length(struct node*); //Returns the number of nodes in the list
struct node* buildOneTwoThree(void); //Allocates and returns the list {1,2,3}.
void push(struct node**, int); //add a new node at the head of a list with standard 3-step-link-in: create new node, set its .next 2 point to current head, make head point to new node
void append(struct node**, int); //add a new node at the headtail of a list with standard 3-step-link-in: create new node, set its .next 2 point to NULL, make previous last node point to new node
int count(struct node*, int); //Returns the number of time an int occurs in a list
int getNth(struct node*, int); //return the data in the nth node of the list. The nodes are numbered from 0. Assert fails if the index is invalid (outside 0..length-1).
void deleteList(struct node**); // Deallocates all memory in a list and sets its head pointer to NULL.
int pop(struct node**); // The opposite of push(). Takes a non-empty list and removes the front node, and returns the data which was in that node.
void insertNth(struct node**, int, int);// A more general version of push(). Add a new node at position N in the list.
void sortedInsert(struct node**, struct node* ); //given a list that is sorted in increasing order, insert a node into the correct sorted position in the list.
void insertSort(struct node**);// Given a list, change it to be in sorted order
void cat(struct node**, struct node**); //appends second arg to first, sets second arg to null thereafter
void frontBackSplit(struct node*, struct node**, struct node**);//Split list into front & back halves, returns the latter two ref params. front > back if length is odd.
void deleteNth(struct node**,int);//Delete the node at position N
void removeDuplicates(struct node**);//Remove duplicates from a list
