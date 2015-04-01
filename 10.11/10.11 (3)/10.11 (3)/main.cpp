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

	cout << endl << "Результат вычисления выражения: " << expressionResult(tree) << endl;

	return EXIT_SUCCESS;
}


/*Общий случай 1:
Содержимое входного файла:
( * ( + 1 1 ) 2 )

Вывод консоли:
( ( 1 + 1 ) * 2 )
Результат вычисления выражения: 4

Общий случай 2:
Содержимое входного файла:
(+ (* (+ 1 7) (+ 3 4)) 1)

Вывод консоли:
( ( ( 1 + 7 ) * ( 3 + 4 ) ) + 1 )
Результат вычисления выражения: 57
*/