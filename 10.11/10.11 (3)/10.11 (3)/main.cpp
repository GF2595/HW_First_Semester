#include <iostream>
#include <fstream>
#include "tree.h"
#include <string>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	ifstream file("../expression.txt", ios::in);
	if (!file.is_open())
	{
		cout << "File not found!" << endl;
		return EXIT_FAILURE;
	}

	string expression;

	getline(file, expression);

	file.close();

	TreeElement *tree = nullptr;

	int counter = 0;

	fillTree(tree, expression, counter);
	
	printTree(tree);

	cout << endl << "��������� ���������� ���������: " << expressionResult(tree) << endl;

	return EXIT_SUCCESS;
}


/*����� ������ 1:
���������� �������� �����:
( * ( + 1 1 ) 2 )

����� �������:
( ( 1 + 1 ) * 2 )
��������� ���������� ���������: 4

����� ������ 2:
���������� �������� �����:
(+ (* (+ 1 7) (+ 3 4)) 1)

����� �������:
( ( ( 1 + 7 ) * ( 3 + 4 ) ) + 1 )
��������� ���������� ���������: 57
*/