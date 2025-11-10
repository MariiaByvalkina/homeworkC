#pragma once
#include <stdbool.h>

typedef struct StackNode StackNode;
typedef struct Stack Stack;

struct StackNode {
    int value;
    struct StackNode* next;
};

struct Stack {
    struct StackNode* head;
};

Stack newCreate(void);
void push(struct Stack* stack, int value);
int pop(Stack* stack);
bool isEmpty(Stack* stack);
int peek(Stack* stack);
void deleteStack(Stack* stack);
