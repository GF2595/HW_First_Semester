#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main()
{
	string expression;

	cout << "Insert expression" << endl;
	cin >> expression;

	int opening = 0;
	int closing = 0;
	int i = 0;
	int length = expression.length();

	do
	{
		switch ((expression[i] == '(') ? 1 : ((expression[i] == ')') ? 2 : 0))
		{
		case 1:
		{
			opening += 1;
		}
			break;
		case 2:
		{
			closing += 1;
		}
		}
		i++;
	} while (i <= length && closing <= opening);

	if (opening == closing)
	{
		cout << "Brackets balance is observed" << endl;
	}
	else
	{
		cout << "Brackets balance is broken" << endl;
	}

	return EXIT_SUCCESS;
}