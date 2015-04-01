#pragma once;

struct Stack;

Stack* makeStack();

void deleteStack(Stack *stack);

void mergeSortNames(Stack *&stack);

void addRecord(Stack *stack, std::string const &name, int number);

void printStack(Stack *stack);

