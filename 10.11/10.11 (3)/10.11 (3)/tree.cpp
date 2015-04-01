#include <iostream>
#include <string>

using namespace std;

struct TreeElement {
	char value;
	TreeElement *left;
	TreeElement *right;
	int result;
};

TreeElement* makeTree(char value)
{
	TreeElement *newTree = new TreeElement;
	newTree->value = value;
	newTree->right = nullptr;
	newTree->left = nullptr;
	newTree->result = 0;

	return newTree;
}

//Checks, if specified symbol is an operation
//Receives symbol
//Returns 'true' if symbol is an operation, false otherwise
bool isOperation(char symbol)
{
	return symbol == '+' || symbol == '-' || symbol == '/' || symbol == '*';
}

//Checks, if specified symbol is a border ('(', ')' or ' ')
//Receives cymbol
//Returns true if symbol is a border, false otherwise
bool isBorder(char symbol)
{
	return symbol == '(' || symbol == ')' || symbol == ' ';
}

void fillTree(TreeElement *&tree, std::string const &expression, int &i)
{
	if (isBorder(expression[i]))
	{
		i++;
		
		fillTree(tree, expression, i);
	}
	else if (expression[i] != '/n')
	{
		if (isOperation(expression[i]))
		{
			tree = makeTree(expression[i]);

			i++;

			fillTree(tree->left, expression, i);
			fillTree(tree->right, expression, i);
		}

		else
		{
			tree = makeTree(expression[i]);
			tree->result = expression[i] - '0';

			i++;
		}
	}
	else
	{
		return;
	}
}

//Calculates result of operation in node of parsing tree, both sons of which are numbers
//Receives node pointer
void calculateNode(TreeElement *&tree)
{
	int result = 0;

	switch (tree->value)
	{
	case '+':
	{
		result = tree->left->result + tree->right->result;
	}
	break;
	case '-':
	{
		result = tree->left->result - tree->right->result;
	}
	break;
	case '*':
	{
		result = tree->left->result * tree->right->result;
	}
	break;
	case '/':
	{
		result = tree->left->result / tree->right->result;
	}
	break;
	}

	delete tree->left;
	delete tree->right;
	tree->left = nullptr;
	tree->right = nullptr;
	tree->value = '0';

	tree->result = result;
}

//Calculates result of operation in node of parsing tree
//Receives tree pointer
void calculateTree(TreeElement *&tree)
{
	if (isOperation(tree->value))
	{
		if (!isOperation(tree->right->value) && !isOperation(tree->left->value))
		{
			calculateNode(tree);
		}
		else
		{
			if (isOperation(tree->left->value))
			{
				calculateTree(tree->left);
			}

			if (isOperation(tree->right->value))
			{
				calculateTree(tree->right);
			}

			calculateTree(tree);
		}
	}
}

void printTree(TreeElement *tree)
{
	if (tree->left != nullptr)
	{
		cout << "( ";

		printTree(tree->left);
	}

	cout << tree->value << " ";

	if (tree->right != nullptr)
	{
		printTree(tree->right);

		cout << ") ";
	}
}

int expressionResult(TreeElement *tree)
{
	calculateTree(tree);

	return tree->result;
}

void deleteTree(TreeElement *tree)
{
	if (tree != nullptr)
	{
		if (tree->left != nullptr)
		{
			deleteTree(tree->left);
		}

		if (tree->right != nullptr)
		{
			deleteTree(tree->right);
		}

		delete tree;
	}
}