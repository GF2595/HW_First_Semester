#pragma once;

typedef int ElementType;

struct List;

List* makeList();

void addElement(List *list, ElementType value);

int listLength(List *list);

void deleteElement(List *list, int number);

void printList(List *list);

int checkElement(List *list, int number);

void deleteList(List *list);