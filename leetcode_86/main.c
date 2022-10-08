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
    ListNode *bigger = NULL;
    ListNode *smaller = NULL;
    ListNode *connect_point = NULL;
    ListNode *ret=NULL;
    ListNode *current = head;
    
    while(current){
        if(current->val<x){
            if(smaller == NULL) {
                smaller = current;
                ret = smaller;
            }
            else {
                smaller->next = current;
                smaller = smaller->next;
            }
        }
        else{
            if(bigger == NULL) {
                connect_point = current;
                bigger = current;
            }
            else {
                bigger->next = current;
                bigger = bigger->next;
            }
        }
        current=current->next;
    }
    
    if(ret==NULL) return connect_point;
    if(connect_point == NULL) return ret;
    else smaller->next = connect_point;
    bigger->next=NULL;
    return ret;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    struct ListNode *headA
        = (struct ListNode *)calloc(2, sizeof(struct ListNode));

    
    struct ListNode **p = &headA;
    (*p)->val = 1;
    (*p)->next = *p+1;
    p=&((*p)->next);

    (*p)->val = 1;
    (*p)->next = NULL;
//    p=&((*p)->next);

//    (*p)->val = 3;
//    (*p)->next = *p+1;
//    p=&((*p)->next);
//
//    (*p)->val = 2;
//    (*p)->next = *p+1;
//    p=&((*p)->next);
//
//    (*p)->val = 5;
//    (*p)->next = *p+1;
//    p=&((*p)->next);
//
//    (*p)->val = 1;
//    (*p)->next = NULL;
    //p=&((*p)->next);
    
    //*p=NULL;
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
    q = partition(headA,2);
    while (q != NULL) {
        printf("%d->", q->val);
        q = q->next;
    }
    printf("N\n");
    return 0;
}
