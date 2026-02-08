#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>

#define SIZE 100

typedef struct
{
    char stack[SIZE];
    int top;
} CharStack;

typedef struct
{
    int stack[SIZE];
    int top;
} IntStack;

/* char stack initialize */
void initChar(CharStack *s)
{
    s->top = -1;
}

/* empty cha ki nai check */
bool isCharEmpty(CharStack *s)
{
    return s->top == -1;
}

void pushChar(CharStack *s, char c)
{
    if (s->top < SIZE - 1)
        s->stack[++s->top] = c;
}

char popChar(CharStack *s)
{
    if (!isCharEmpty(s))
        return s->stack[s->top--];
    return '\0';
}

char peekChar(CharStack *s)
{
    if (!isCharEmpty(s))
        return s->stack[s->top];
    return '\0';
}

/* int stack ko lagi */
void initInt(IntStack *s)
{
    s->top = -1;
}

bool isIntEmpty(IntStack *s)
{
    return s->top == -1;
}

void pushInt(IntStack *s, int x)
{
    if (s->top < SIZE - 1)
        s->stack[++s->top] = x;
}

int popInt(IntStack *s)
{
    if (!isIntEmpty(s))
        return s->stack[s->top--];
    return 0;
}

/* operator ho ki haina */
bool isOp(char c)
{
    return (c == '+' || c == '-' || c == '*' ||
            c == '/' || c == '%' || c == '^');
}

int precedence(char op)
{
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/' || op == '%') return 2;
    if (op == '^') return 3;
    return 0;
}

/* power operator right associative huncha */
bool isRightAssoc(char op)
{
    return op == '^';
}

void infixToPostfix(const char *infix, char *postfix)
{
    CharStack s;
    initChar(&s);
    int k = 0;

    for (int i = 0; infix[i] != '\0'; i++)
    {
        char ch = infix[i];

        if (isspace(ch))
            continue;

        if (isalnum(ch))
        {
            postfix[k++] = ch;
        }
        else if (ch == '(')
        {
            pushChar(&s, ch);
        }
        else if (ch == ')')
        {
            while (!isCharEmpty(&s) && peekChar(&s) != '(')
                postfix[k++] = popChar(&s);

            popChar(&s); // '(' hatauna
        }
        else if (isOp(ch))
        {
            while (!isCharEmpty(&s) && peekChar(&s) != '(' &&
                  (precedence(peekChar(&s)) > precedence(ch) ||
                  (precedence(peekChar(&s)) == precedence(ch) &&
                   !isRightAssoc(ch))))
            {
                postfix[k++] = popChar(&s);
            }
            pushChar(&s, ch);
        }
    }

    while (!isCharEmpty(&s))
        postfix[k++] = popChar(&s);

    postfix[k] = '\0';
}

int applyOp(int a, int b, char op)
{
    switch (op)
    {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return (b != 0) ? a / b : 0;
        case '%': return a % b;
        case '^': return (int)pow(a, b);
        default: return 0;
    }
}

int evalPostfix(const char *postfix)
{
    IntStack s;
    initInt(&s);

    for (int i = 0; postfix[i] != '\0'; i++)
    {
        char ch = postfix[i];

        if (isdigit(ch))
        {
            pushInt(&s, ch - '0');
        }
        else if (isOp(ch))
        {
            int b = popInt(&s);
            int a = popInt(&s);
            pushInt(&s, applyOp(a, b, ch));
        }
    }
    return popInt(&s);
}

int main()
{
    const char *expList[] =
    {
        "5+4*2",
        "(3+1)*2",
        "1^3^2",
        "5+((1+2)*4)-3",
        "a+b*c-d"
    };

    for (int i = 0; i < 5; i++)
    {
        char postfix[SIZE];

        printf("\nInfix   : %s\n", expList[i]);
        infixToPostfix(expList[i], postfix);
        printf("Postfix : %s\n", postfix);

        bool evaluate = true;
        for (int j = 0; expList[i][j] != '\0'; j++)
        {
            if (isalpha(expList[i][j]))
            {
                evaluate = false;
                break;
            }
        }

        if (evaluate)
            printf("Result  : %d\n", evalPostfix(postfix));
        else
            printf("Result  : Variables vayera evaluate garna mildaina\n");
    }

    return 0;
}
