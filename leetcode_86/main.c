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

struct ListNode* partition(struct ListNode* head,int x){

  ListNode **indir = &head;
  ListNode *current = head;


  


}

int main(int argc, const char * argv[]) {
    // insert code here...
    struct ListNode *headA
        = (struct ListNode *)calloc(6, sizeof(struct ListNode));

    
    struct ListNode **p = &headA;
    (*p)->val = 1;
    (*p)->next = *p+1;
    p=&((*p)->next);

    (*p)->val = 4;
    (*p)->next = *p+1;
    p=&((*p)->next);

    (*p)->val = 3;
    (*p)->next = *p+1;
    p=&((*p)->next);

    (*p)->val = 2;
    (*p)->next = *p+1;
    p=&((*p)->next);
    
    (*p)->val = 5;
    (*p)->next = *p+1;
    p=&((*p)->next);
    
    (*p)->val = 2;
    (*p)->next = *p+1;
    p=&((*p)->next);
    
    *p=NULL;
//    int i;
//    for (i = 1; i <= 5; i++) {
//        (*p)->val = i;
//        (*p)->next = *p + 1;
//        p = &(*p)->next;
//    }

    printf("List A: ");
    struct ListNode *q = headA;
    while (q != NULL) {
        printf("%d->", q->val);
        q = q->next;
    }
    printf("N\n");

    return 0;
}
