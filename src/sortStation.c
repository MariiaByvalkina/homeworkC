#include <stdio.h>
#include "stack.h"
#include <string.h>
#include <ctype.h>

int predence(char op)
{
    if (op == '+' || op == '-') {
        return 1;
    }
    if (op == '*' || op == '/') {
        return 2;
    }
    return 0;
}
void sortStation(char infixStr[], char postfixStr[])
{
    Stack stack = newCreate();
    int i = 0;
    int j = 0;
    while (infixStr[i] != '\0') {
        char token = infixStr[i];
        if (isspace(token)) {
            i++;
            continue;
        }
        if (isdigit(token)) {
            postfixStr[j++] = token;
            postfixStr[j++] = ' ';
        }
        else if (token == '+' || token == '-' || token == '*' || token == '/') {
            while (!isEmpty(&stack) && predence(peek(&stack)) >= predence(token)) {
                postfixStr[j++] = pop(&stack);
                postfixStr[j++] = ' ';
            }
            push(&stack, token);
        }
        if (token == '(') {
            push(&stack, token);
        } else if (token == ')') {
            while (peek(&stack) != '(') {
                postfixStr[j++] = pop(&stack);
                postfixStr[j++] = ' ';
            }
            pop(&stack);
        }
        i++;
    }
    while (!isEmpty(&stack)) {
        postfixStr[j++] = pop(&stack);
        postfixStr[j++] = ' ';
    }
    postfixStr[j] = '\0';
}

int main() 
{   
    char infixStr[20] = "3 + 4 * 2";
    char postfixStr[20];
    sortStation(infixStr, postfixStr);
    printf("%s", postfixStr);
    return 0;
}
