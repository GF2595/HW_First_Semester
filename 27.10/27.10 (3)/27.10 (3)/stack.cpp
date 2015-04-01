#include <cstdlib>
#include <iostream>
#include "stack.h"

using namespace std;

void push(Stack *stack, char value)
{
	StackElement *newElement = new StackElement;
	newElement->value = value;
	newElement->next = stack->head;
	stack->head = newElement;
}

char pop(Stack *stack)
{
	if (stack->head == nullptr)
	{
		return -1;
	}

	char value = stack->head->value;
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
}