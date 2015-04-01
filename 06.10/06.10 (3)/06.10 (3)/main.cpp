#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");

	ifstream file("../text.txt", ios::in);
	if (!file.is_open())
	{
		cout << "Файл не найден" << endl;

		return EXIT_FAILURE;
	}

	const int n = 50;
	int numberOfStrings = 0;
	bool isStringEmpty = true;

	while (!file.eof())
	{
		char s[n] = { "" };

		file.getline(s, n);

		for (int i = 0; s[i] != '\0'; i++)
		{
			if ((s[i] != ' ') && (s[i] != '\t'))
			{
				isStringEmpty = false;
			}
		}

		if (!isStringEmpty)
		{
			numberOfStrings++;
			isStringEmpty = true;
		}
	}

	file.close();

	cout << "В файле обнаружено " << numberOfStrings << " непустых строк" << endl;

	return EXIT_SUCCESS;
}


/*Общий случай:
Содержимое входного файла:
пзпзп
ппп


ппп
ппп
п
п

п  п


Вывод консоли:
В файле обнаружено 7 непустых строк
*/