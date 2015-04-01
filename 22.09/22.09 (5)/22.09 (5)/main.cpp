#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void main()
{
	srand(time(nullptr));
	int const size = 3;
	int valuesArray[size];

	for (int i = 0; i < size; i++)
	{
		valuesArray[i] = rand() % 20 - 10;
		cout << valuesArray[i] << " ";
	}

	cout << endl << endl << " ";


	for (int i = size - 1; i > 1; i--)
	{
		if (valuesArray[size - i - 1])
		{
			cout << " ";

			if (valuesArray[size - i - 1] != 1 && valuesArray[size - i - 1] != -1)
			{
				int number = valuesArray[size - i - 1] > 0 ? valuesArray[size - i - 1] : -valuesArray[size - i - 1];
				int length = 0;

				while (number > 0)
				{
					number /= 10;
					length++;
				}

				for (int j = 0; j < length; j++)
				{
					cout << " ";
				}
			}

				cout << "  " << i;
		}
	}

	cout << endl;
	
	bool firstPrinted = false;

	for (int i = 0; i < size-1; i++)
	{
		if (valuesArray[i])
		{
			if (firstPrinted)
			{
				if (valuesArray[i] != 1 && valuesArray[i] != -1)
				{
					if (valuesArray[i] > 0)
					{
						cout << "+ " << valuesArray[i] << "x ";
					}
					else
					{
						cout << "- " << -valuesArray[i] << "x ";
					}
				}
				else
				{
					if (valuesArray[i] > 0)
					{
						cout << "+ x ";
					}
					else
					{
						cout << "- x ";
					}
				}
			}
			else
			{
				firstPrinted = true;

				if (valuesArray[i] != 1 && valuesArray[i] != -1)
				{
					if (valuesArray[i] > 0)
					{
						cout << "  " << valuesArray[i] << "x ";
					}
					else
					{
						cout << "- " << -valuesArray[i] << "x ";
					}
				}
				else
				{
					if (valuesArray[i] > 0)
					{
						cout << "  x ";
					}
					else
					{
						cout << "- x ";
					}
				}
			}
		}
	}

	if (valuesArray[size - 1])
	{
		if (firstPrinted)
		{
			if (valuesArray[size - 1] > 0)
			{
				cout << "+ " << valuesArray[size - 1];
			}
			else
			{
				cout << "- " << -valuesArray[size - 1];
			}
		}
		else
		{
			firstPrinted = true;

			if (valuesArray[size - 1] > 0)
			{
				cout << "  " << valuesArray[size - 1];
			}
			else
			{
				cout << "- " << -valuesArray[size - 1];
			}
		}
	}
	cout << endl;
}


/*Общий случай:
-7 -4 6

     2
- 7x - 4x + 6
*/