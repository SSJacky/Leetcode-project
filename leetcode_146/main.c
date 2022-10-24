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

struct node {
   LRUCache *node;
}**hash_table;

LRUCache* lRUCacheCreate(int capacity) {
    LRUCache *head = malloc(sizeof(LRUCache)*capacity);
    return head;
}

int lRUCacheGet(LRUCache* obj, int key) {
    if(hash_table[key]->node!=obj) return 0;
    else return 1;
}

void lRUCachePut(LRUCache* obj, int key, int value) {
    LRUCache **head = &obj;
    LRUCache *current = obj;
    if(*head == NULL) {
        (*head)->val = value;
        hash_table[key] = &(**head);
    }
    head = &(*head)->next;
    hash_table[key]->node = current;
    free(obj);
}

void lRUCacheFree(LRUCache* obj) {
    
}

void print_all() {

}

int main() {
    printf("first test\n");
 

    printf("all tests passed!\n");

    return 0;
}

