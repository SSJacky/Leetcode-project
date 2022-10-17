//
//  main.c
//  leetcode_21
//
//  Created by 夏蜃詰 on 2022/9/13.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
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
bool hasCycle(struct ListNode *head) {
    
    if(head == NULL)return;
    bool ret = 0;
    ListNode *slow = head;
    ListNode *fast = head;                                                                          
    for(;fast && fast->next;)
    {   
        slow = slow->next;
        fast=fast->next->next;
        if(slow == fast)
        {   
            ret = 1;
            break;
        }
    }
    return ret;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    struct ListNode *headA
    = (struct ListNode *)calloc(6, sizeof(struct ListNode));
    bool ret = 0;
    
    struct ListNode **p = &headA;
    (*p)->val = 3;
    (*p)->next = *p+1;
    p=&((*p)->next);
    
    (*p)->val = 2;
    (*p)->next = *p+1;
    p=&((*p)->next);
    
    (*p)->val = 0;
    (*p)->next = *p+1;
    p=&((*p)->next);
    
    (*p)->val = -4;
    (*p)->next = *p-2;
    //p=&((*p)->next);
    
//    (*p)->val = 5;
//    (*p)->next = *p+1;
//    p=&((*p)->next);
//
//    (*p)->val = 2;
//    (*p)->next = headA;
 
//    int i;
//    for (i = 1; i <= 5; i++) {
//        (*p)->val = i;
//        (*p)->next = *p + 1;
//        p = &(*p)->next;
//    }
    
    printf("List A: \n");
    struct ListNode *q = headA;
    for (int i =0;i<4;i++) {
        printf("node %d address=%p\n",i,q);
        printf("val %d = %d\n", i,q->val);
        printf("next node %d= %p\n",i+1, q->next);
        q = q->next;
    }
    
    
    printf("List part: ");
    ret = hasCycle(headA);

    printf("ret = %d\n",ret);
    return 0;
}
