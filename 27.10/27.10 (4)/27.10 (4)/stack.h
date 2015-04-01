#pragma once

struct Stack;

Stack* makeStack();

void push(Stack *stack, char value);

char pop(Stack *stack);

void deleteStack(Stack *stack);

bool isStackEmpty(Stack *stack);