#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct StackNode{
    int value;
    struct StackNode* next;
} StackNode;

typedef struct Stack{
    StackNode* head;
} Stack;

Stack newCreate(void) {
    Stack stack = {
        .head = NULL
    };
    return stack;
}

void push(Stack* stack, int value)
{
    StackNode* node = malloc(sizeof(StackNode));
    node->value = value;
    node->next = stack->head;
    stack->head = node;
}
int pop(Stack* stack)
{
    StackNode* oldNode = stack->head;
    int res = oldNode->value;
    stack->head = oldNode->next;
    free(oldNode);
    return res;
}

bool isEmpty(Stack* stack)
{
    if (stack->head != NULL) {
        return false;
    } return true;
}

int peek(Stack* stack)
{
    StackNode* node = stack->head;
    int res = node->value;
    return res;
}

void deleteStack(Stack* stack)
{
    while (!isEmpty(stack)){
        pop(stack);
    }
    free(stack);
}
