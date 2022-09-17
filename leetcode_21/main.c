//
//  main.c
//  leetcode_21
//
//  Created by 夏蜃詰 on 2022/9/13.
//
#include <stdio.h>
#include <stdlib.h>
//Definition for singly-linked list.
struct ListNode {
      int val;
      struct ListNode *next;
 };
 

typedef struct ListNode ListNode;

void insert_node(ListNode **head_node, int value)
{
    ListNode *tmp = NULL;
    ListNode *current = *head_node;
    ListNode *previous = NULL;

    if (*head_node == NULL)
    {
        tmp = (ListNode *)malloc(sizeof(ListNode));
        tmp->next = NULL;
        tmp->val = value;
        *head_node = tmp;
        return;
    }

    while (current->next != NULL)
    {
        if (value > current->val)
        {
            previous = current;
            current = current->next;
        }
        else
        {
            if (current == *head_node)
            {
                tmp = (ListNode *)malloc(sizeof(ListNode));
                tmp->val = value;
                tmp->next = current;
                *head_node = tmp;
                return;
            }
            else
            {
                tmp = (ListNode *)malloc(sizeof(ListNode));
                tmp->val = value;
                tmp->next = current;
                previous->next = tmp;
                return;
            }

        }

    }

    if (current->next == NULL)
    {
        if (value >= current->val)
        {
            tmp = (ListNode *)malloc(sizeof(ListNode));
            tmp->val = value;
            tmp->next = NULL;
            current->next = tmp;
        }
        else
        {
            if (current == *head_node)
            {
                tmp = (ListNode *)malloc(sizeof(ListNode));
                tmp->val = value;
                tmp->next = current;
                *head_node = tmp;
                return;
            }
            else
            {
                tmp = (ListNode *)malloc(sizeof(ListNode));
                tmp->val = value;
                tmp->next = current;
                previous->next = tmp;
                return;
            }
        }
    }
}

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
    ListNode *head = NULL;
    if (l1 == NULL && l2 == NULL) return head;
    else if (l1 == NULL) return l2;
    else if (l2 == NULL) return l1;

    head = l1;

    insert_node(&head, l2->val);

    while (l2->next != NULL)
    {
        l2 = l2->next;
        insert_node(&head, l2->val);
    }


    return head;
}
#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    struct ListNode *headA
        = (struct ListNode *)calloc(5, sizeof(struct ListNode));
    struct ListNode *headB
        = (struct ListNode *)calloc(3, sizeof(struct ListNode));

    struct ListNode **p = &headA;
    int i;
    for (i = 1; i <= 5; i++) {
        (*p)->val = i;
        (*p)->next = *p + 1;
        p = &(*p)->next;
    }
    *p = NULL;

    p = &headB;
    for (i = 3; i <= 7; i += 2) {
        (*p)->val = i;
        (*p)->next = *p + 1;
        p = &(*p)->next;
    }
    *p = NULL;

    printf("List A: ");
    struct ListNode *q = headA;
    while (q != NULL) {
        printf("%d->", q->val);
        q = q->next;
    }
    printf("N\n");

    printf("List B: ");
    q = headB;
    while (q) {
        printf("%d->", q->val);
        q = q->next;
    }
    printf("N\n");

    struct ListNode *ret = mergeTwoLists(headA, headB);

    printf("Merged: ");
    q = ret;
    while (q) {
        printf("%d->", q->val);
        q = q->next;
    }
    printf("N\n");

    return 0;
}
