#include <stdio.h>
#include <stdlib.h>
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

List createList()
{
    List list = {.head = NULL};
    return list;
}

void newCreate(List* list, int value)
{
    ListNode* node = malloc(sizeof(ListNode));
    node->value = value;

    if (list->head == NULL) {
        list->head = node;
        node->next = node;
        return;
    }

    ListNode* current = list->head;
    while(current->next != list->head){
        current = current->next;
    }
    current->next = node;
    node->next = list->head;
}

bool deleteNode(List* list, int index)
{
    if (list->head == NULL) {
        return false;
    }

    if (index == 0) {
        ListNode* deleteTo = list->head;

        if (deleteTo->next == list->head) {
            list->head = NULL;
        } else {
            ListNode* last = list->head;
            while (last->next != list->head) {
                last = last->next;
            }
            list->head = deleteTo->next;
            last->next = list->head;
        }
        free(deleteTo);
        return true;
    }

    ListNode* current = list->head;
    ListNode* previous = NULL;
    int currentIndex = 0;

    while(currentIndex < index) {
        previous = current;
        current = current->next;
        currentIndex++;

        if (current == list->head) {
            return false;
        }
    }

    previous->next = current->next;
    free(current);
    return true;
}

void printList(List* list)
{
    if (list->head == NULL) {
        printf("Список пуст\n");
        return;
    }

    ListNode* current = list->head;
    do {
        printf("%d ", current->value);
        current = current->next;
    } while (current != list->head);
    printf("\n");
}
