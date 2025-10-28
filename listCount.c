#include <stdio.h>
#include "cycle.h"


void cicleCount(List* list, int n, int m)
{
    while(n != 1) {
        for(int i = 0; i < n; i = i + m - 1) {
            deleteNode(list,i);
             n--;
        }
    }
}

int main()
{
    int m = 0;
    scanf("%d ",&m);
    int n = 0;
    scanf("%d",&n);
    List list = createList();
    for (int i = 1; i < n + 1; i++) {
        newCreate(&list,i);
    }
    cicleCount(&list, n, m);
    printList(&list);
}
