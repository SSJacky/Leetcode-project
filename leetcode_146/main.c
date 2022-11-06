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
typedef struct node_t{
    int val;
    int valid;
    int key;
    struct node_t *next;
    struct node_t *prev;
    struct node_t *hash_next;
    struct node_t *hash_prev;
    
} LRUCache;

struct lru_t {
    int size;
    int capacity;
    LRUCache *head;
    LRUCache *tail;
    LRUCache *end;
    LRUCache **hash_table;
} m_lru;

int hash_index(int key)
{
    int index = key % m_lru.capacity;
    return index;
}

LRUCache* lRUCacheCreate(int capacity) {
    uint32_t index = 1;
    uint32_t size = capacity+2;
    LRUCache *head = (LRUCache *)malloc(sizeof(LRUCache)*(capacity+2));
    m_lru.hash_table = (LRUCache **)calloc(capacity,sizeof(LRUCache *));
    LRUCache **current = &head;
    m_lru.head = head;
    m_lru.capacity = capacity;
    
    (*current)->prev = NULL;
    (*current)->hash_next = NULL;
    (*current)->hash_prev = NULL;
    
    while(index < size){
        (*current)->val = 0;
        (*current)->key = 0;
        (*current)->valid = 0;
        (*current)->next = *current+1;
        (*current+1)->prev = *current;
        current = &((*current)->next);
        (*current)->hash_next = NULL;
        (*current)->hash_prev = NULL;
        index++;
    }
    
    (*current)->hash_next = NULL;
    (*current)->hash_prev = NULL;
    (*current)->val = 0;
    (*current)->key = 0;
    (*current)->valid = 0;
    (*current)->next = NULL;
    m_lru.tail = *current;
    m_lru.end = *current;
    m_lru.size = 0;
    
    return head;
}

int lRUCacheGet(LRUCache* obj, int key) {
    
    int index = hash_index(key);
    int key_match_flg = 0;
    LRUCache* q = m_lru.hash_table[index];
    
    while(q){
        if(q->key!=key){
            q = q->hash_next;
        }
        else{
            key_match_flg = 1;
            break;
        }
    }
    
    if(m_lru.hash_table[index]==NULL || key_match_flg == 0) {
        return -1;
    }
    else if(q->next == m_lru.tail){
        return q->val;
    }
    else{
        /*remove get node*/
        LRUCache **indir = &obj;
        LRUCache *current = (q->prev);
        while(*indir != q){
            indir=&((*indir)->next);
        }
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
    LRUCache **tmp;
    int index = hash_index(key);
    
    indir = &(*indir)->next;
    
    if(lRUCacheGet(obj,key)>=0){
        
        LRUCache* q = m_lru.hash_table[index];
        
        while(q){
            if(q->key!=key){
                q = q->hash_next;
            }
            else break;
        }
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

        if(current->valid == 0)goto UPDATE;
        
        tmp = &m_lru.hash_table[hash_index(current->key)];
        while((*tmp)->key!=current->key){
                tmp = &((*tmp)->hash_next);
        }
        *tmp = (*tmp)->hash_next;
        
    UPDATE:
        current->val = value;
        current->key = key;
        current->valid = 1;
        tmp = &m_lru.hash_table[index];
        while(*tmp){
            tmp = &((*tmp)->hash_next);
        }
        *tmp = current;
        
        return;
        
    }

    while((*indir)->valid == 1){
        indir = &(*indir)->next;
    }
    (*indir)->val=value;
    (*indir)->valid=1;
    (*indir)->key=key;
    m_lru.tail = (*indir)->next;
    tmp = &m_lru.hash_table[index];
    while(*tmp){
        tmp = &((*tmp)->hash_next);
    }
    *tmp = (*indir);
    
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
    
    LRUCache* head_cache=lRUCacheCreate(3);
    
    lRUCachePut(head_cache,1,1);
    print_all(head_cache);
    lRUCachePut(head_cache,2,2);
    print_all(head_cache);
    lRUCachePut(head_cache,3,3);
    print_all(head_cache);
    lRUCachePut(head_cache,4,4);
    print_all(head_cache);
    ret = lRUCacheGet(head_cache,4);
    printf("\nret = %d\n\n",ret);
    print_all(head_cache);
    ret = lRUCacheGet(head_cache,3);
    printf("\nret = %d\n\n",ret);
    print_all(head_cache);
    ret = lRUCacheGet(head_cache,2);
    printf("\nret = %d\n\n",ret);
    print_all(head_cache);
    ret = lRUCacheGet(head_cache,1);
    printf("\nret = %d\n\n",ret);
    print_all(head_cache);
    lRUCachePut(head_cache,5,5);
    print_all(head_cache);

    ret = lRUCacheGet(head_cache,1);
    printf("\nret = %d\n\n",ret);
    print_all(head_cache);
    ret = lRUCacheGet(head_cache,2);
    printf("\nret = %d\n\n",ret);
    print_all(head_cache);
    ret = lRUCacheGet(head_cache,3);
    printf("\nret = %d\n\n",ret);
    print_all(head_cache);
    ret = lRUCacheGet(head_cache,4);
    printf("\nret = %d\n\n",ret);
    print_all(head_cache);
    ret = lRUCacheGet(head_cache,5);
    printf("\nret = %d\n\n",ret);
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

