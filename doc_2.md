# Infix to Postfix Conversion and Evaluation

## Overview
This program converts an **infix expression** into a **postfix expression** using stacks.  
If the expression contains only numbers, it also **evaluates the postfix result**.

Two stacks are used:
- **Character Stack** → for operators and parentheses
- **Integer Stack** → for evaluating postfix expressions

---

## Data Structures Used

### Character Stack
Used during infix to postfix conversion.

```c
typedef struct {
    char stack[SIZE];
    int top;
} CharStack;
