#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "stack.c"

bool isBalanced(char str[])
{   
    Stack stack = new();
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == '{' || str[i] == '[' || str[i] == '(') {
            push(&stack, str[i]);
        } else if (str[i] == '}' || str[i] == ']' || str[i] == ')') {
            if (isEmpty(&stack)) {
                return false;
            }
            char temp = pop(&stack);
            if ((str[i] == '}' && temp != '{') || (str[i] == ']' && temp != '[') || (str[i] == ')' && temp != '(')) {
                return false;
            }
        }
    }
    return isEmpty(&stack);
    free(&stack);
}

int main()
{
    int s = 100;
    char* str = malloc(s * sizeof(char));
    scanf("%s", str);
    if (isBalanced(str)) {
        printf("Баланс соблюден");
    } printf("Баланс не соблюден");
    free(str);
    return 0;
}
