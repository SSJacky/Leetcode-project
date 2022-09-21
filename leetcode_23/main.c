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

//struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
//  
//  if(listsSize == 0) return NULL;
//  int size = listsSize/2;
//  int bound = listsSize;
//  int j = 0;
//  int odd;
//
//  while(size != 0){
//    for(j = 0;j<size;j++)
//    {
//      lists[j]=mergeTwoLists(lists[j],lists[bound-j-1]);
//    }
//      odd = bound%2;
//      if(odd) bound = bound/2 +1;
//      else bound /= 2;
//      size = bound/2;
//  }
//
//  return lists[0];
//}
    
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){

  /*merge sort*/
  if(listsSize==0)return NULL;
  if(listsSize<=1)return *lists;
  int mid = listsSize >>1;
  ListNode *left=mergeKLists(lists,mid);
  ListNode *right=mergeKLists(lists+mid,listsSize-mid);

  return mergeTwoLists(left,right);

}
struct ListNode* generateList(int *nums, int size) {
    if (nums == NULL || size == 0) return NULL;

    struct ListNode *list
        = (struct ListNode *)malloc(size * sizeof(struct ListNode));
    struct ListNode **p = &list;

    int i;
    for (i = 0; i < size; i++) {
        (*p)->val = nums[i];
        (*p)->next = *p + 1;
        p = &((*p)->next);
    }
    *p = NULL;

    return list;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int k = 7;
    struct ListNode **lists
        = (struct ListNode **)calloc(k, sizeof(struct ListNode*));

    int n0[] = {-10,-9,-9,-3,-1,-1,0};
    int n1[] = {-5};
    int n2[] = {4};
    int n3[] = {-8};
    int n4[] = {};
    int n5[] = {-9,-6,-5,-4,-2,2,3};
    int n6[] = {-3,-3,-2,-1,0};

    lists[0] = generateList(n0, sizeof(n0) / sizeof(int));
    lists[1] = generateList(n1, sizeof(n1) / sizeof(int));
    lists[2] = generateList(n2, sizeof(n2) / sizeof(int));
    lists[3] = generateList(n3, sizeof(n3) / sizeof(int));
    lists[4] = generateList(n4, sizeof(n4) / sizeof(int));
    lists[5] = generateList(n5, sizeof(n5) / sizeof(int));
    lists[6] = generateList(n6, sizeof(n6) / sizeof(int));

    struct ListNode *p;
    int i;

    printf("Lists: \n");
    for (i = 0; i < k; i++) {
        p = lists[i];
        while (p) {
            printf("%d ", p->val);
            p = p->next;
        }
        printf("NIL\n");
    }

    p = mergeKLists(lists, k);

    printf("Merged: \n");
    while (p) {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("NIL\n");

    free(lists);

    return 0;
}
