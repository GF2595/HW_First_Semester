#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

//Computes hash function value for specified string
//Receives string
//Returns hash function value
unsigned long long hashFunction(string const &insert)
{
	unsigned long long result = 0;

	for (int i = 0; i < insert.size(); i++)
	{
		result += insert[i] * pow(101, insert.size() - 1 - i);
	}

	return result;
}

int main()
{
	setlocale(LC_ALL, "rus");

	ifstream file("../file.txt", ios::in);
	if (!file.is_open())
	{
		cout << "Файл не найден" << endl;
		return EXIT_FAILURE;
	}

	vector<char> data;

	while (!file.eof()) {
		string buffer;
		file >> buffer;
		for (int i = 0; i < buffer.size(); i++)
		{
			data.push_back(buffer[i]);
		}
		data.push_back(' ');
	}

	string sample;
	string currentString;

	cout << "Введите образец" << endl;
	cin >> sample;

	unsigned long long sampleHash = hashFunction(sample);

	if (sample.size() <= data.size())
	{
		int i = 0;

		for (i; i < sample.size(); i++)
		{
			currentString += (data[i]);
		}

		unsigned long long currentStringHash = hashFunction(currentString);
		bool stringIsFound = false;
		unsigned long long biggestMultiplicant = pow(101, sample.size() - 1);
		
		while (!stringIsFound && i < data.size())
		{
			if (currentStringHash == sampleHash)
			{
				if (sample.compare(currentString) == 0)
				{
					stringIsFound = true;
				}
			}

			if (!stringIsFound)
			{
				currentStringHash = (currentStringHash - currentString[0] * biggestMultiplicant) * 101 + data[i];

				currentString.erase(0, 1);
				currentString += data[i];
			}

			i++;
		}

		if (i == data.size() && currentStringHash == sampleHash)
		{
			if (sample.compare(currentString) == 0)
			{
				stringIsFound = true;
			}
		}

		if (stringIsFound)
		{
			cout << "Образец обнаружен на " << i - sample.size() << " позиции" << endl;
		}
		else
		{
			cout << "Образец не обнаружен" << endl;
		}
	}
	else
	{
		cout << "Образец не обнаружен" << endl;
	}

	file.close();

	return EXIT_SUCCESS;
}


/*Общий случай:
Содержимое входного файла:
Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.
Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure
dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non
proident, sunt in culpa qui officia deserunt mollit anim id est laborum.

Вывод консоли:
Введите образец
dolore
Образец обнаружен на 104 позиции
*/