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
#define HASH_SIZE 10001
typedef struct node_t{
    int val;
    int valid;
    int key;
    struct node_t *next;
    struct node_t *prev;
    
} LRUCache;

struct lru_t {
    int size;
    int capacity;
    LRUCache *head;
    LRUCache *tail;
    LRUCache *end;
    LRUCache **hash_table;
} m_lru;

LRUCache* lRUCacheCreate(int capacity) {
    uint32_t index = 1;
    uint32_t size = capacity+2;
    LRUCache *head = (LRUCache *)malloc(sizeof(LRUCache)*(capacity+2));
    m_lru.hash_table = (LRUCache **)calloc(HASH_SIZE,sizeof(LRUCache *));
    LRUCache **current = &head;
    m_lru.head = head;
    m_lru.capacity = capacity;
    
    (*current)->prev = NULL;
    
    
    while(index < size){
        (*current)->val = 0;
        (*current)->key = 0;
        (*current)->valid = 0;
        (*current)->next = *current+1;
        (*current+1)->prev = *current;
        current = &((*current)->next);
        index++;
    }
    m_lru.tail = m_lru.head->next;
    (*current)->val = 0;
    (*current)->key = 0;
    (*current)->valid = 0;
    (*current)->next = NULL;
    
    m_lru.end = *current;
    m_lru.size = 0;
    
    return head;
}

int lRUCacheGet(LRUCache* obj, int key) {
    
    LRUCache* q = m_lru.hash_table[key];
    
    if(q==NULL) {
        return -1;
    }
    else if(q->next == m_lru.tail){
        return q->val;
    }
    else{
        /*remove get node*/
        LRUCache **indir = &obj;
        LRUCache *current = (q->prev);
        
        indir=&(m_lru.hash_table[key]->prev->next);
        
        indir=&((*indir)->next);
        LRUCache *next = q->next;
        current->next = next;
        current->next->prev = current;
        
        indir = &q;
        
        (*indir)->next = m_lru.tail;
        (*indir)->prev = m_lru.tail->prev;
        (*indir)->prev->next = (*indir);
        m_lru.tail->prev = (*indir);
        /*insert node to tail*/
        
        return q->val;
    }
}

void lRUCachePut(LRUCache* obj, int key, int value) {
    LRUCache **indir = &obj;
    LRUCache *current = obj;
    
    indir = &(*indir)->next;
    
    if(lRUCacheGet(obj,key)>=0){
        LRUCache* q = m_lru.hash_table[key];
        if(q->val!=value) q->val = value;
        return;
    }
    
    if(m_lru.end->prev->valid==1){
        
        current = *indir;
        *indir = ((*indir)->next);
        
        (*indir)->prev = m_lru.head;
        
        current->prev = m_lru.tail->prev;
        current->prev->next = current;
        m_lru.tail->prev = current;
        current->next = m_lru.tail;
        m_lru.hash_table[current->key] = NULL;
        
        current->val = value;
        current->key = key;
        current->valid = 1;
        m_lru.hash_table[key] = current;
        
        return;
        
    }

    
    indir = &(m_lru.tail->prev->next);
    
    (*indir)->val=value;
    (*indir)->valid=1;
    (*indir)->key=key;
    m_lru.tail = (*indir)->next;
    m_lru.hash_table[key] = (*indir);
    
}

void lRUCacheFree(LRUCache* obj) {
    free(obj);
    free(m_lru.hash_table);
}

void print_all(LRUCache* list) {
    printf("List : \n");
    LRUCache *q = list;
    if(q==NULL)return;
    printf("head = %p\n", q);
    printf("next = %p\n",q->next);
    printf("prev = %p\n",q->prev);
    printf("val = %d\n",q->val);
    printf("valid = %d\n",q->valid);
    printf("key = %d\n",q->key);
    q = q->next;
    
    while (q != NULL) {
        printf("node = %p\n", q);
        printf("next = %p\n",q->next);
        printf("prev = %p\n",q->prev);
        printf("val = %d\n",q->val);
        printf("valid = %d\n",q->valid);
        printf("key = %d\n",q->key);
        q = q->next;
    }
    
    printf("N\n");
}

void print_hash(LRUCache** list,int capacity) {
    printf("hash : \n");
    for(int i = 0;i<capacity;i++){
        if(list[i]==NULL){
            printf(" N \n");
        }
        else {
            LRUCache *q = list[i];
            printf("head = %p\n", q);
            printf("next = %p\n",q->next);
            printf("prev = %p\n",q->prev);
            printf("val = %d\n",q->val);
            printf("valid = %d\n",q->valid);
        }
    }
    
}

int main() {
    printf("first test\n");
    int ret = 0;
    
    LRUCache* head_cache=lRUCacheCreate(1);
    

    ret = lRUCacheGet(head_cache,6);
    printf("\nret = %d\n\n",ret);
    print_all(head_cache);
    
    ret = lRUCacheGet(head_cache,8);
    printf("\nret = %d\n\n",ret);
    print_all(head_cache);
    
    lRUCachePut(head_cache,12,1);
    print_all(head_cache);
    
    ret = lRUCacheGet(head_cache,2);
    printf("\nret = %d\n\n",ret);
    print_all(head_cache);
    
    lRUCachePut(head_cache,15,11);
    print_all(head_cache);
    
    lRUCachePut(head_cache,5,2);
    print_all(head_cache);
    
    lRUCachePut(head_cache,1,15);
    print_all(head_cache);
    
    lRUCachePut(head_cache,4,2);
    print_all(head_cache);
    
    ret = lRUCacheGet(head_cache,5);
    printf("\nret = %d\n\n",ret);
    print_all(head_cache);
    
    lRUCachePut(head_cache,15,15);
    print_all(head_cache);
//
//    lRUCachePut(head_cache,3,3);
//    print_all(head_cache);
//
//    ret = lRUCacheGet(head_cache,2);
//    printf("ret = %d\n\n",ret);
//    print_all(head_cache);
//
//    lRUCachePut(head_cache,4,4);
//    print_all(head_cache);
//
//    ret = lRUCacheGet(head_cache,1);
//    printf("ret = %d\n\n",ret);
//    print_all(head_cache);
//
//    ret = lRUCacheGet(head_cache,3);
//    printf("ret = %d\n\n",ret);
//    print_all(head_cache);
//
//    ret = lRUCacheGet(head_cache,4);
//    printf("ret = %d\n\n",ret);
//    print_all(head_cache);
//    //lRUCacheGet(head_cache,3);
//    printf("all tests passed!\n\n");
    //    print_all(head_cache);
    //print_all(m_lru.hash_table[3]);
    
    return 0;
}

