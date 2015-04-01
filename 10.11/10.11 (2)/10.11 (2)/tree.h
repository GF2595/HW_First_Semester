#pragma once

typedef int ElementType;

struct Tree;

//Makes tree
//Returns new tree
Tree* plantTree();

//Adds new element into tree
//Receives tree pointer and value that should be added
void addElement(Tree *tree, ElementType addedValue);

//Prints tree
//Receives tree pointer and order code (1 for ascending order, 2 for descending order)
void printTree(Tree *tree, int code);

//Deletes whole tree
//Receives tree
void deleteTree(Tree *tree);

//Deletes specified element from tree
//Receives tree pointer and element, that should be deleted
void eraseElement(Tree *tree, ElementType element);

//Checks, if element is element in tree or not
bool findElement(Tree *tree, ElementType element);