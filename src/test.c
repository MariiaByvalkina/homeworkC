#include <stdio.h>
#include <stdbool.h>
#include "list.h"
#include <string.h>

bool checkList(List* list, int values[], int count)
{
    ListNode* node = list->head;
    for (int i = 0; i < count; i++) {
        if (node == NULL || node->value != values[i])
            return false;
        node = node->next;
    }
    return node == NULL;
}


void testSortInsert()
{
    List list = newCreate();

    SortInsert(&list, 3);
    SortInsert(&list, 1);
    SortInsert(&list, 2);

    int current[] = {1, 2, 3};
    if (checkList(&list, current, 3)) {
        printf("pass\n");
    } else {
        printf("fail\n");
    }

}

void testDeleteTo() {
    List list = newCreate();


    SortInsert(&list, 1);
    SortInsert(&list, 2);
    SortInsert(&list, 3);

    deleteTo(&list, 2);

    int current[] = {1, 3};
    if (checkList(&list, current, 2)) {
        printf("pass\n");
    } else {
        printf("fail\n");
    }
}

void testDeleteHead()
{
    List list = newCreate();

    SortInsert(&list, 1);
    SortInsert(&list, 2);
    SortInsert(&list, 3);

    deleteTo(&list, 1);

    int current[] = {2, 3};
    if (checkList(&list, current, 2)) {
        printf("pass\n");
    } else {
        printf("fail\n");
    }
}
void testSortInsertDuple()
{
    List list = newCreate();

    SortInsert(&list, 2);
    SortInsert(&list, 2);
    SortInsert(&list, 1);

    int current[] = {1, 2, 2};
    if (checkList(&list, current, 3)) {
        printf("pass\n");
    } else {
        printf("fail\n");
    }
}

void testSortInsertSameValues()
{

    List list = newCreate();
    SortInsert(&list, 5);
    SortInsert(&list, 5);
    SortInsert(&list, 5);

    int current[] = {5, 5, 5};
    if (checkList(&list, current, 3)) { printf("pass\n");
    } else {
        printf("fail\n");
    }
}

void runAllTests()
{
    testSortInsert();
    testDeleteTo();
    testDeleteHead();
    testSortInsertDuple();
    testSortInsertSameValues();
}

