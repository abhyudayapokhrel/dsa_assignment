# Problem:
To check if any given mathematical expression has balanced number of parenthesis or not

## Overview
This program checks whether a given mathematical expression has **balanced parentheses**.  
It uses a **stack data structure** implemented with an array to match opening and closing brackets.

Supported brackets:
- `()`
- `[]`
- `{}`

---

## Stack Implementation
A stack is implemented using a character array and a `top` pointer.

```c
typedef struct {
    char arr[MAX_SIZE];
    int top;
} Stack;
