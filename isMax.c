#include "isMax.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

void runAllTests();

int convertToNumber(bool* Arr, int len)
{
    int res = 0;
    for (int i = 0; i < len; i++) {
        if (Arr[len - 1 - i]) {
            res += (1 << i);
        }
    }
    return res;
}

void isMax(int first, int second)
{
    if (first > second) {
        printf("Первое число больше");
    } else {
        printf("Второе число больше");
    }
}

int theMain()
{
    bool first[8] = { true, false, false, true, true, true, false, false };
    bool second[8] = { true, false, false, false, false, true, false, true };
    int num1 = convertToNumber(first, 8);
    int num2 = convertToNumber(second, 8);
    isMax(num1, num2);

    return 0;
}

int main(int arg, char* argv[])
{
    if (arg == 2 && strcmp(argv[1], "--tests") == 0) {
        runAllTests();
        return 0;
    }
    theMain();
    return 0;
}
