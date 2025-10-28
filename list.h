#pragma once

#include <stddef.h>

typedef struct ListNode{
    int value;
    struct ListNode* next;
} ListNode;

typedef struct List
{
    ListNode* head;
} List;

List newCreate();
void SortInsert(List* list, int value);
void deleteTo(List* list, int value);
void printList(List* list);
