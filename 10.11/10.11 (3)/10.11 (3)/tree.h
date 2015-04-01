#pragma once

#include <string>

struct TreeElement;

TreeElement* makeTree(char value);

//Makes expression parsing tree
//Receives tree pointer, string, which represents the expression and counter
void fillTree(TreeElement *&tree, std::string const &expression, int &i);

//Prints tree
//Receives tree pointer
void printTree(TreeElement *tree);

//Calculates expression in parsing tree
//Receives tree pointer
//Returns expression result
int expressionResult(TreeElement *tree);

//Deletes tree
//Receives tree pointer
void deleteTree(TreeElement *tree);