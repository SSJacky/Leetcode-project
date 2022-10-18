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
typedef struct {
    int val;
    int key;
    struct LRUCache *prev;
    struct LRUCache *next;
} LRUCache;

LRUCache* lRUCacheCreate(int capacity) {
    LRUCache *head = malloc(sizeof(LRUCache)*capacity);
    return head;
}

int lRUCacheGet(LRUCache* obj, int key) {
  
}

void lRUCachePut(LRUCache* obj, int key, int value) {
  
}

void lRUCacheFree(LRUCache* obj) {
    
}

void print() {
    struct node_t *p = m_lru.head;
    while (p) {
        printf("(%d, %d) ", p->key, p->value);
        p = p->next;
    }
    printf("\n");
}

int main() {
    printf("first test\n");
    lruCacheInit(2);

    lruCacheSet(2, 1);
    print();
    lruCacheSet(1, 1);
    print();

    lruCacheGet(2);
    print();

    lruCacheSet(4, 1);
    print();

    lruCacheGet(1);
    print();
    lruCacheGet(2);
    print();

    printf("second test\n");
    lruCacheInit(2);

    lruCacheSet(2, 1);
    print();
    lruCacheSet(1, 1);
    print();

    lruCacheSet(2, 3);
    print();

    lruCacheSet(4, 1);
    print();

    lruCacheGet(1);
    print();
    lruCacheGet(2);
    print();

    lruCacheFree();

    printf("third test\n");
    lruCacheInit(3);

    lruCacheSet(1, 1);
    print();
    lruCacheSet(2, 2);
    print();
    lruCacheSet(3, 3);
    print();
    lruCacheSet(4, 4);
    print();

    lruCacheGet(4);
    print();
    lruCacheGet(3);
    print();
    lruCacheGet(2);
    print();
    lruCacheGet(1);
    print();

    lruCacheSet(5, 5);
    print();

    lruCacheGet(1);
    print();
    lruCacheGet(2);
    print();
    lruCacheGet(3);
    print();
    lruCacheGet(4);
    print();
    lruCacheGet(5);
    print();

    lruCacheFree();

    printf("all tests passed!\n");

    return 0;
}

