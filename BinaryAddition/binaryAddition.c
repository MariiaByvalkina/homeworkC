#include "binaryAddition.h"
#include <stdio.h>
#include <string.h>

void printBinary(int n)
{
    unsigned int num = *(unsigned int*)&n;
    for (int i = 32 - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
}

void addInColumn(int a, int b)
{
    printf("\nСложение в столбик:\n");

    printf("  ");
    printBinary(a);
    printf("  (%d)\n", a);
    printf("  ");
    printBinary(b);
    printf("  (%d)\n", b);

    printf("  -------- +\n");

    printf("  ");
    printBinary(a + b);
    printf("  (%d)\n", a + b);
}

int binaryToDecimalSigned(char* binary)
{
    unsigned int num = 0;

    for (int i = 0; i < 32; i++) {
        num = num * 2 + (binary[i] - '0');
    }

    return (int)num;
}

int mainBinary()
{
    int a, b;

    scanf("%d %d", &a, &b);
    printf("\n%d в двоичном виде: ", a);
    printBinary(a);
    printf("\n%d в двоичном виде: ", b);
    printBinary(b);
    printf("\n");

    addInColumn(a, b);

    int sum = a + b;
    printf("\nСумма в двоичном виде: ");
    printBinary(sum);
    printf("\nСумма в десятичном виде: %d\n", sum);

    return 0;
}

int main(int arg, char* argv[])
{
    if (arg == 2 && strcmp(argv[1], "--tests") == 0) {
        runBinaryTests();
        return 0;
    }
    mainBinary();
    return 0;
}
