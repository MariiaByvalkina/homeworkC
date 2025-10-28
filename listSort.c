#include <stdio.h>
#include <stdbool.h>
#include "list.h"

void menu()
{

    printf("---Меню---\n");
    printf("1.Добавить элемент\n");
    printf("2.Удалить элемент\n");
    printf("3.Показать список\n");
    printf("0.Выйти\n");
    printf("Выберите команду для выполнения\n");
}
void runDialog() {
    menu();
    List list = newCreate();

    int command = 0;
    int value = 0;
    while (true) {
        scanf("%d", &command);
        if (command == 1) {
            printf("Введите значение\n");
            scanf("%d", &value);
            SortInsert(&list, value);
            printf("Выберите команду\n");

        }
        else if (command == 2) {
            printf("Введите значение\n");
            scanf("%d", &value);
            deleteTo(&list, value);
            printf("Выберите команду\n");
        }
        else if (command == 3) {
            printList(&list);
            printf("Выберите команду\n");
        } else {
            break;
        }
    }
}


int main()
{
    runDialog();
    return 0;
}
