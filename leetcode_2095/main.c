//
//  main.c
//  leetcode_21
//
//  Created by 夏蜃詰 on 2022/9/13.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
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
struct ListNode* deleteMiddle(struct ListNode* head){
    
    ListNode *current = head;
    int size=1;
    
    while(current->next) {
        size++;
        current=current->next;
    }
    if(size==1)return NULL;
    current = head;
    size=size>>1;
    while(size>1){
        current = current->next;
        size--;
    }
    current->next=current->next->next;
    
    return head;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    struct ListNode *headA
    = (struct ListNode *)calloc(6, sizeof(struct ListNode));
    
    struct ListNode *q = headA;
    
    struct ListNode **p = &headA;
    int i;
    for (i = 1; i <= 6; i++) {
        (*p)->val = i;
        (*p)->next = *p + 1;
        p = &(*p)->next;
    }
    printf("List A ");
    print_all_ptr(q);
  
    
    struct ListNode *ret = deleteMiddle(headA);
    
    printf("Merged: ");
    q = ret;
    print_all_ptr(q);
    
    return 0;
}
