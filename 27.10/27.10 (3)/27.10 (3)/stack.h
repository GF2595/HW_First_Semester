#pragma once

struct StackElement{
	char value;
	StackElement *next;
};

struct Stack{
	StackElement *head = nullptr;
};

void push(Stack *stack, char value);

char pop(Stack *stack);

void deleteStack(Stack *stack);