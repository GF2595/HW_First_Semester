#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include "list.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	Stack *stack = makeStack();

	ifstream file("../base.txt", ios::in);
	if (!file.is_open())
	{
		cout << "File not found!" << endl;
		return EXIT_FAILURE;
	}

	while (!file.eof()) {
		string buffer;
		int i = 0;

		getline(file, buffer);

		while (i < buffer.size() && buffer.substr(i, 3) != " - ")
		{
			i++;
		}

		string name = buffer.substr(0, i);
		int number = atoi(buffer.substr(i + 4, buffer.size() - i - 4).c_str());

		addRecord(stack, name, number);
	}

	mergeSortNames(stack);

	printStack(stack);

	file.close();

	return EXIT_SUCCESS;
}