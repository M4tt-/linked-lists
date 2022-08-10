# linked-lists

A library consisting of utility functions for linked lists.

## Getting Started

Pull the master branch of this repository and ensure you `# include llutil.h` in your code.

## Utilities

- `length()`: Return the number of nodes in the linked list
- `buildOneTwoThree()`: Allocates and returns the linked list {1,2,3}.
- `push()`: Add a new node at the head of a linked list w/ standard 3-step-link-in
- `append()`: Add a new node at the tail of a linked list with standard 3-step-link-in
- `count()`: Return the number of times an int occurs in a linked list
- `getNth()`: Return the data in the nth node of the linked list
- `deleteList()`: Deallocates all memory in a linked list and sets its head pointer to `NULL`.
- `pop()`: The opposite of `push()`. Takes a non-empty llinked ist and removes the front node, and returns the data which was in that node.
- `insertNth()`: A more general version of `push()` - add a new node at position N in the linked list.
- `sortedInsert()`: Insert a node into the correct sorted position in the linked list.
- `insertSort()`: Given a linked list, change it to be in sorted order
- `cat()`: Concatenate two linked lists
- `frontBackSplit()`: Split linked list into front & back halves
- `deleteNth()`: Delete the node at position N
- `removeDuplicates()`: Remove duplicates from a linked list

## About Linked Lists

Linked lists are a data structure that can serve as traditional arrays, except with some major differences:

- Linked lists are not contiguous in memory. Each element contain a reference (pointer) to the next element's location,
- Linked lists need not have a fixed size. Memory can be dynamically allocated at runtime,
- Linked lists are generally slower to traverse than traditional arrays, but faster with respect to insertion/deletion

## Author

- Matt Runyon (all functions except insertSort())
- Nick Parlante (for the actual problem set and some templating code -- see here: http://cslibrary.stanford.edu/105/LinkedListProblems.pdf)
