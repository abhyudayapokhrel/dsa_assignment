#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Stackko structure
typedef struct {
    char arr[MAX_SIZE];
    int top;} Stack;

// Initializing
void initialize_stack(Stack *s) {
    s->top = -1;
}

// Check if stack is empty
bool isEmpty(Stack *s) {
    return s->top == -1;
}

// Check if stack is full
bool isFull(Stack *s) {
    return s->top == MAX_SIZE - 1;
}

// Push element into stack
void push(Stack *s, char ch) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        return;
    }
    s->arr[++s->top] = ch;
}

// Pop element from stack
char pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return '\0';
    }
    return s->arr[s->top--];
}

// Check opening bracket
bool isOpening(char ch) {
    return (ch == '(' || ch == '[' || ch == '{');
}

// Check closing bracket
bool isClosing(char ch) {
    return (ch == ')' || ch == ']' || ch == '}');
}

// Match opening and closing brackets
bool isMatching(char open, char close) {
    if (open == '(' && close == ')') return true;
    if (open == '[' && close == ']') return true;
    if (open == '{' && close == '}') return true;
    return false;
}

// Function to check balanced parentheses
bool areParenthesesBalanced(const char *exp) {
    Stack s;
    initialize_stack(&s);

    for (int i = 0; i < strlen(exp); i++) {
        char ch = exp[i];

        if (isOpening(ch)) {
            push(&s, ch);
        }
        else if (isClosing(ch)) {
            if (isEmpty(&s)) {
                return false; // no opening bracket
            }

            char last = pop(&s);
            if (!isMatching(last, ch)) {
                return false; // wrong order
            }
        }
    }

    // if stack empty, everything matched
    return isEmpty(&s);
}

// Display result
void checkExpression(const char *exp) {
    printf("\nExpression: %s\n", exp);

    if (areParenthesesBalanced(exp)) {
        printf("Result: Balanced parentheses\n");
    } else {
        printf("Result: Unbalanced parentheses\n");
    }
}

int main() {
    checkExpression("a + (b - c) * (d");
    checkExpression("m + [a - b * (c + d * {m)]");
    checkExpression("a + (b - c)");

    return 0;
}