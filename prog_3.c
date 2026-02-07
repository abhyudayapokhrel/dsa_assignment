#include <stdio.h>
#include <stdlib.h>

/* linked list ko node */
struct ListNode
{
    int value;
    struct ListNode* next;
};

/* recursion use garera ulto print */
void printReverse(struct ListNode* start)
{
    if (start == NULL)
        return;

    printReverse(start->next);
    printf("%d ", start->value);
}

int main()
{
    struct ListNode* first = NULL;
    struct ListNode* second = NULL;
    struct ListNode* third = NULL;

    first = (struct ListNode*)malloc(sizeof(struct ListNode));
    second = (struct ListNode*)malloc(sizeof(struct ListNode));
    third = (struct ListNode*)malloc(sizeof(struct ListNode));

    first->value = 10;
    first->next = second;

    second->value = 20;
    second->next = third;

    third->value = 30;
    third->next = NULL;

    printf("Reverse Traversal: ");
    printReverse(first);  // output: 30 20 10

    return 0;
}