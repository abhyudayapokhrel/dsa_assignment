# Doubly Linked List Operations (C)

## Overview
This program demonstrates basic **doubly linked list operations**:  
- Inserting a new node **after a given node**  
- Deleting a node by value  
- Printing the list  

A doubly linked list allows traversal in both directions using `prev` and `next` pointers.

---

## Output Example
```c
Initial list: 10 20 30
20 pachi 25 insert garepachi: 10 20 25 30
10 delete garepachi: 20 25 30
30 delete garepachi: 20 25
head pachi 15 insert garepachi: 20 15 25
```

## Node Structure
```c
typedef struct Node {
    int value;
    struct Node *prev;
    struct Node *next;
} Node;
```
