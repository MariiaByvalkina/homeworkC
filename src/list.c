#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode{
    int value;
    struct ListNode* next;
} ListNode;

typedef struct List
{
    ListNode* head;
} List;

List newCreate()
{
    List list = {.head = NULL};
    return list;
}

void SortInsert(List* list, int value)
{
    ListNode* node = malloc(sizeof(ListNode));
    node->value = value;
    node->next = NULL;

    if (!list->head || value < list->head->value) {
        node->next = list->head;
        list->head = node;
        return;
    }

    ListNode* current = list->head;
    while (current->next && current->next->value < value)
        current = current->next;

    node->next = current->next;
    current->next = node;

}

void deleteTo(List* list, int value)
{

    if (list->head == NULL) {
        return;
    }
    if (list->head->value == value) {
        ListNode* current = list->head;
        list->head = list->head->next;
        free(current);
    }

    ListNode* current = list->head;
    while (current->next != NULL && current->next->value != value) {
        current = current->next;
    }

    if (current->next != NULL) {
        ListNode* temp = current->next;
        current->next = current->next->next;
        free(temp);
    }
}


void printList(List* list)
{
    ListNode* current = list->head;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}
