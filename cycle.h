#pragma once

#include <stdbool.h>

typedef struct ListNode
{
    int value;
    struct ListNode* next;
} ListNode;

typedef struct List
{
    ListNode* head;
} List;

List createList();
void newCreate(List* list, int value);
bool deleteNode(List* list, int index);
void printList(List* list);
