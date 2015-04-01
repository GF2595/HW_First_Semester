#include <iostream>

using namespace std;

struct ListElement {
	int value;
	ListElement *next;
};

struct List {
	ListElement *head;
};

//List constructor
//Returns new list pointer
List* makeList()
{
	List *newList = new List;
	newList->head = nullptr;

	return newList;
}

//Adds element to list
//Receives list pointer and value of added element
void addElement(List *list, int value)
{
	ListElement *temp = list->head;
	ListElement *newElement = new ListElement;
	newElement->value = value;

	if (temp != nullptr)
	{
		while (temp->next != list->head)
		{
			temp = temp->next;
		}

		temp->next = newElement;
		newElement->next = list->head;
	}
	else
	{
		list->head = newElement;
		newElement->next = newElement;
	}
}

//Deletes specified element
//Receives list pointer, pointer of element, that should be deleted, and pointer of previous element
void deleteElement(List *list, ListElement *previous, ListElement *current)
{
	if (current == list->head)
	{
		list->head = current->next;
	}

	previous->next = current->next;
	delete current;
}

int josephusPermutation(int n, int m)
{	
	List *list = makeList();

	for (int i = 0; i < n; i++)
	{
		addElement(list, i);
	}

	ListElement *previous = list->head;
	ListElement *current = list->head->next;

	while (list->head->next != list->head)
	{
		for (int i = 1; i < m; i++)
		{
			current = previous->next->next;
			previous = previous->next;
		}

		deleteElement(list, previous, current);
	}

	if (list->head->value != 0)
	{	
		int temp = list->head->value;

		delete list->head;
		delete list;

		return temp;
	}
	else
	{	
		delete list->head;
		delete list;

		return n;
	}
}