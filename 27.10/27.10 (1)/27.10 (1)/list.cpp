#include <string>
#include <iostream>

using namespace std;

struct Record {
	int number;
	string name;
};

struct StackElement {
	Record value;
	StackElement *next;
};

struct Stack {
	StackElement *head;
};

Stack* makeStack()
{
	Stack *newStack = new Stack;
	newStack->head;

	return newStack;
}

void push(Stack *stack, Record value)
{
	StackElement *newElement = new StackElement;
	newElement->value = value;
	newElement->next = nullptr;
	stack->head = newElement;
}

Record pop(Stack *stack)
{
	if (stack->head == nullptr)
	{
		Record error;
		error.name = "Error";
		error.number = 0;
		return error;
	}

	Record value = stack->head->value;
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

//Divides stack on two half-stacks
//Receives old stack and both half-stacks pointers
void stackDivision(Stack *oldStack, Stack *firstNewStack, Stack *secondNewStack)
{
	int i = 1;
	StackElement *temp = oldStack->head;
	while (temp->next != nullptr)
	{
		i++;
		temp = temp->next;
	}

	for (int j = 0; j < (i / 2); j++);
	{
		push(firstNewStack, pop(oldStack));
	}

	while (oldStack->head != nullptr)
	{
		push(secondNewStack, pop(oldStack));
	}
}

//Adds one stack to another
//Receives resulting stack pointer and stack which has to be added
void residueAdding(Stack *stack, Stack *residue)
{
	while (residue->head != nullptr)
	{
		push(stack, pop(residue));
	}
}

//Sorts stack using merge sort
//Receives stack
//Returns sorted stack
void mergeSortNames(Stack *&stack)
{
	if (stack->head == nullptr)
	{
		return;
	}
	if (stack->head->next == nullptr)
	{
		return;
	}

	Stack *firstHalfStack = makeStack();
	Stack *secondHalfStack = makeStack();

	stackDivision(stack, firstHalfStack, secondHalfStack);

	deleteStack(stack);

	if (firstHalfStack->head->next != nullptr)
	{
		mergeSortNames(firstHalfStack);
	}

	if (secondHalfStack->head->next != nullptr)
	{
		mergeSortNames(secondHalfStack);
	}

	bool secondIsLonger = false;

	do
	{
		Record tempFirst = pop(firstHalfStack);
		Record tempSecond = pop(secondHalfStack);

		if (tempFirst.name < tempSecond.name)
		{
			push(stack, tempSecond);
			push(firstHalfStack, tempFirst);
		}
		else
		{
			push(stack, tempFirst);
			push(secondHalfStack, tempSecond);
		}
	} while (firstHalfStack->head != nullptr && secondHalfStack->head != nullptr);

	if (firstHalfStack->head != nullptr)
	{
		residueAdding(stack, firstHalfStack);
		return;
	}

	if (secondHalfStack->head != nullptr)
	{
		residueAdding(stack, secondHalfStack);
	}
}

void addRecord(Stack *stack, string const &name, int number)
{
	Record temp;
	temp.name = name;
	temp.number = number;

	push(stack, temp);
}

void printStack(Stack *stack)
{
	while (stack->head != nullptr)
	{
		Record temp = pop(stack);

		cout << temp.name << " " << temp.number << endl;
	}
}