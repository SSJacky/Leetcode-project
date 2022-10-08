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



struct ListNode* partition(struct ListNode* head,int x){
    
    if(head == NULL) return NULL;
    ListNode *connect_point = NULL;
    ListNode *ret=NULL;
    ListNode **bigger = &connect_point;
    ListNode **smaller = &ret;
    
    while(head){
        if(head->val<x){
            *smaller = head;
            smaller = &(*smaller)->next;
        }
        else{
            *bigger = head;
            bigger = &(*bigger)->next;
        }
        head=head->next;
    }
    
    (*smaller) = connect_point;
    (*bigger) = NULL;
    return ret;
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
    (*p)->next = NULL;
 
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
    
    printf("List part: ");
    q = partition(headA,3);
    while (q != NULL) {
        printf("%d->", q->val);
        q = q->next;
    }
    printf("N\n");
    return 0;
}
