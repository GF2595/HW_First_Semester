#pragma once;

#include <string>

struct Record{
	int number;
	std::string name;
};

typedef Record ElementType;

struct List;

//Makes list
//Returns new list pointer
List* makeList();

//Deletes list
//Receives list pointer
void deleteList(List *list);

//Adds element to list
//Receives list pointer and element
void addElement(List *list, ElementType value);

//Returns list length
//Receives list pointer
int listLength(List *list);

//Deletes element on specified place
//Receives list pointer and element position
void deleteElement(List *list, int number);

//Prints list
//Receives list pointer
void printList(List *list);

//Checks specified element value
//Receives list pointer and element position
//Returns element value
Record checkElement(List *list, int number);