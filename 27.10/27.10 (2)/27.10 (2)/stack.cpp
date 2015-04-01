#include <cstdlib>
#include <iostream>
#include "stack.h"

using namespace std;

struct StackElement {
	int value;
	StackElement *next;
};

struct Stack {
	StackElement *head;
};

Stack* makeStack()
{
	Stack *newStack = new Stack;
	newStack->head = nullptr;

	return newStack;
}

void push(Stack *stack, int value)
{
	StackElement *newElement = new StackElement;
	newElement->value = value;
	newElement->next = stack->head;
	stack->head = newElement;
}

int pop(Stack *stack)
{
	if (stack->head == nullptr)
	{
		return -1;
	}

	int value = stack->head->value;
	StackElement *temp = stack->head->next;
	delete stack->head;
	stack->head = temp;
	return value;
}

void deleteStack(Stack *stack)
{
	while (stack->head != nullptr)
	{
		StackElement *temp = stack->head;
		stack->head = stack->head->next;
		delete temp;
	}

	delete stack;
}