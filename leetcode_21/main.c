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

void print_all_ptr(ListNode *list){
    printf("List : ");
    struct ListNode *q = list;
    while (q != NULL) {
        printf("%d->", q->val);
        q = q->next;
    }
    printf("N\n");
}

struct ListNode *mergeTwoLists(struct ListNode *l1,struct ListNode *l2) {
    struct ListNode *head;
    struct ListNode **ptr = &head;
    for(;l1&&l2;ptr=&(*ptr)->next)
    {
       if(l1->val<l2->val){
           *ptr=l1;
           l1 = l1->next;
       }
       else{
           *ptr=l2;
           l2 = l2->next;
       }
        //print_all_ptr(head);
    }
    *ptr = (ListNode *)((uintptr_t)l1 | (uintptr_t)l2);
    return head;
}


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
