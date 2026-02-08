#include <stdio.h>
#include <stdlib.h>

/* doubly linked list ko node */
typedef struct Node
{
    int value;
    struct Node *prev;
    struct Node *next;
} Node;

/* given node pachi new node insert garne */
void addAfter(Node *prevNode, int val)
{
    if (prevNode == NULL)
    {
        printf("NULL node pachi insert garna mildaina.\n");
        return;
    }

    Node *newNode = (Node*)malloc(sizeof(Node));
    if (!newNode)
    {
        printf("Memory allocation fail bhayo!\n");
        exit(1);
    }
    newNode->value = val;

    newNode->next = prevNode->next;
    newNode->prev = prevNode;

    if (prevNode->next != NULL)
        prevNode->next->prev = newNode;

    prevNode->next = newNode;
}

/* data vako node delete garne */
void removeNode(Node **head, int val)
{
    Node *cur = *head;
    while (cur != NULL && cur->value != val)
        cur = cur->next;

    if (cur == NULL) return;

    if (cur->prev != NULL)
        cur->prev->next = cur->next;
    else
        *head = cur->next;

    if (cur->next != NULL)
        cur->next->prev = cur->prev;

    free(cur);
}

/* list print garne */
void printList(Node *head)
{
    Node *cur = head;
    while (cur != NULL)
    {
        printf("%d ", cur->value);
        cur = cur->next;
    }
    printf("\n");
}

int main()
{
    Node *head = (Node*)malloc(sizeof(Node));
    head->value = 10;
    head->prev = NULL;
    head->next = NULL;

    Node *second = (Node*)malloc(sizeof(Node));
    second->value = 20;
    second->prev = head;
    second->next = NULL;
    head->next = second;

    Node *third = (Node*)malloc(sizeof(Node));
    third->value = 30;
    third->prev = second;
    third->next = NULL;
    second->next = third;

    printf("Initial list: ");
    printList(head);

    addAfter(second, 25);
    printf("20 pachi 25 insert garepachi: ");
    printList(head);

    removeNode(&head, 10);
    printf("10 delete garepachi: ");
    printList(head);

    removeNode(&head, 30);
    printf("30 delete garepachi: ");
    printList(head);

    addAfter(head, 15);
    printf("head pachi 15 insert garepachi: ");
    printList(head);

    return 0;
}
