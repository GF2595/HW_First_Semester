#pragma once;

struct List;

//List constructor
//Returns new list pointer
List* makeList();

//Adds element to list
//Receives list pointer and value of added element
void addElement(List *list, int value);

int josephusPermutation(int n, int m);