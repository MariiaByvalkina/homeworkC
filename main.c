#include <stdio.h>
#include "sort.h"

int main() {
    int dataArr[100];
    int count = 0;
    while (count < 100 && scanf("%d", &dataArr[count]) == 1) {
        count++;
        if (getchar() == '\n') {
            break;
        }
    }

    int res = bubbleSort(dataArr, count);
    printf("%d ", res);
    return 0;
}

