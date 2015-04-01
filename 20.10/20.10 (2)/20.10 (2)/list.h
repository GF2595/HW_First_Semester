#pragma once

typedef int ElementType;

struct List;

//Makes list
//Returns new list pointer
List* makeList();

//Inserts element on specified position in list
//Receives list pointer, position on which element should be placed and element
void insertElement(List *list, int position, ElementType element);

//Seeks for position after which all element in list are bigger than specified element
//Receives list pointer, represented in vector, and element
//Returns position or -1, if all elements in list are bigger than received element
int search(List *list, ElementType element);

//Prints list
//Reveives list pointer, represented in vector
void printList(List *list);

//Deletes specified element
//Receives list pointer and element
void deleteElement(List *list, ElementType element);

//Returns list size
//Receives list pointer
unsigned size(List *list);

void deleteList(List *list);