#pragma once;

#include <string>

struct ListValue {
	std::string word;
	unsigned timesFound;
};

typedef ListValue ElementType;

struct List;

//Makes list
//Returns new list
List* makeList();

//Adds new element to list
//Receives list pointer and element
void addElement(List *list, ElementType value);

//Checks list length
//Receives list pointer
//Returns list length
int listLength(List *list);

//Deletes specified element from list
//Receives list pointer and element, that should be deleted
void deleteElement(List *list, ElementType element);

//Prints list
//Receives list pointer
void printList(List *list);

//Checks element on specified position
//Receives list pointer and position number
//Returns element
ElementType checkElement(List *list, int number);

//Deletes list
//Receives list pointer
void deleteList(List *list);

//Special function for hashtables
//Increases number of times, function has been called for this element, or adds this element to list, if function is called for first time
//Receives list pointer and string
void addTimesFound(List *&list, std::string element);