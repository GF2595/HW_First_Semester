#pragma once

struct Stack;

Stack* makeStack();

void push(Stack *stack, int value);

int pop(Stack *stack);

void deleteStack(Stack *stack);