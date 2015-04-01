#include "tree.h"
#include <iostream>

using namespace std;

struct TreeElement
{
	ElementType value;
	TreeElement *left;
	TreeElement *right;
};

struct Tree
{
	TreeElement *head;
};

Tree* plantTree()
{
	Tree *newTree = new Tree;
	newTree->head = nullptr;
	return newTree;
}

void addElement(Tree *tree, ElementType addedValue)
{
	TreeElement *newElement = new TreeElement;
	newElement->value = addedValue;
	newElement->left = nullptr;
	newElement->right = nullptr;

	TreeElement *cursor = tree->head;
	if (cursor == nullptr)
	{
		tree->head = newElement;
	}
	else while (addedValue != cursor->value)
	{
		if (addedValue < cursor->value)
		{
			if (cursor->left == nullptr)
			{
				cursor->left = newElement;
				break;
			}
			cursor = cursor->left;
		}
		else if (addedValue > cursor->value)
		{
			if (cursor->right == nullptr)
			{
				cursor->right = newElement;
				break;
			}
			cursor = cursor->right;
		}
	}
}

//Prints tree elements in ascending order
//Receives tree pointer
void printTreeElementAscending(TreeElement *treeElement)
{
	if (treeElement->left != nullptr)
	{
		printTreeElementAscending(treeElement->left);
	}

	cout << treeElement->value << " ";

	if (treeElement->right != nullptr)
	{
		printTreeElementAscending(treeElement->right);
	}
}

//Prints tree elements in descending order
//Receives tree pointer
void printTreeElementDescending(TreeElement *treeElement)
{
	if (treeElement->right != nullptr)
	{
		printTreeElementDescending(treeElement->right);
	}

	cout << treeElement->value << " ";

	if (treeElement->left != nullptr)
	{
		printTreeElementDescending(treeElement->left);
	}
}

//Prints tree using printTreeElementDescending and printTreeElementAscending
//Receives tree and code, that shows in which way tree shouldbe printed
void printTree(Tree *tree, int code)
{
	if (tree->head == nullptr)
	{
		cout << "ololo" << endl;
	}
	else
	{
		if (code == 1)
		{
			printTreeElementAscending(tree->head);
		}
		else
		{
			printTreeElementDescending(tree->head);
		}
	}
}

//Deletes one branch or leaf of a tree
//Receives tree node pointer
void deleteTreePart(TreeElement *treeElement)
{
	if (treeElement->left != nullptr)
	{
		deleteTreePart(treeElement->left);
	}

	if (treeElement->right != nullptr)
	{
		deleteTreePart(treeElement->right);
	}

	delete treeElement;
}

void deleteTree(Tree *tree)
{
	if (tree->head != nullptr)
	{
		deleteTreePart(tree->head);
	}

	delete tree;
}

void deleteElement(TreeElement *&tree, ElementType element)
{
	if (tree != nullptr)
	{
		if (tree->value > element)
		{
			deleteElement(tree->left, element);
		}
		else if (tree->value < element)
		{
			deleteElement(tree->right, element);
		}
		else
		{
			if (tree->left == nullptr && tree->right == nullptr)
			{
				delete tree;
				tree = nullptr;
			}
			else if (tree->left == nullptr || tree->right == nullptr)
			{
				TreeElement *temp = tree;

				if (tree->left == nullptr)
				{
					tree = tree->right;
				}
				else
				{
					tree = tree->left;
				}

				delete temp;
			}
			else
			{
				if (tree->right->left == nullptr)
				{
					TreeElement *temp = tree;

					tree->right->left = tree->left;
					tree = tree->right;

					delete temp;
				}
				else
				{
					TreeElement *temp = tree->right;
					TreeElement *tempPrevious = tree;

					while (temp->left != nullptr)
					{
						tempPrevious = temp;
						temp = temp->left;
					}

					TreeElement *newHead = temp;
					TreeElement *oldHead = tree;
					newHead->left = tree->left;
					newHead->right = tree->right;
					tree = newHead;
					delete oldHead;

					deleteElement (temp, temp->value);
					tempPrevious->left = temp;
				}
			}
		}
	}
}

void eraseElement(Tree *tree, ElementType element)
{
	deleteElement(tree->head, element);
}

//Checks, if specified element is in branch of tree
//Receives tree node pointer and element that should be found
//Returnes "true" if element is found and "false" otherwise
bool isElementInSet(TreeElement *tree, ElementType element)
{
	if (element < tree->value)
	{
		if (tree->left != nullptr)
		{
			return isElementInSet(tree->left, element);
		}
		else
		{
			return false;
		}
	}
	else if (element > tree->value)
	{
		if (tree->right != nullptr)
		{
			return isElementInSet(tree->right, element);
		}
		else
		{
			return false;
		}
	}
	else
	{
		return true;
	}
}

//Used to launch isElementInSet from main program
//Receives tree pointer and specified element
//Returns isElementInSet value
bool findElement(Tree *tree, ElementType element)
{
	return isElementInSet(tree->head, element);
}