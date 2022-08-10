# linked-lists

A library consisting of utility functions for linked lists.

## Getting Started

Pull the master branch of this repository and ensure you `# include llutil.h` in your code.

## About Linked Lists

Linked lists are a data structure that can serve as traditional arrays, except with some major differences:

- Linked lists are not contiguous in memory. Each element contain a reference (pointer) to the next element's location,
- Linked lists need not have a fixed size. Memory can be dynamically allocated at runtime,
- Linked lists are generally slower to traverse than traditional arrays, but faster with respect to insertion/deletion

## Author

- Matt Runyon (all functions except insertSort())
- Nick Parlante (for the actual problem set and some templating code -- see here: http://cslibrary.stanford.edu/105/LinkedListProblems.pdf)
