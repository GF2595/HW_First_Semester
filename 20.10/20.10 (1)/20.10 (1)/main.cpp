#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Record{
	string name = "";
	int number = 0;
};

void saveBase(Record base[100], int recordsNumber)
{
	ofstream outputFile("../base.txt", ios::out, ios::trunc);

	for (int i = 0; i < recordsNumber; i++)
	{
		if (i != 0)
		{
			outputFile << endl;
		}

		outputFile << base[i].name << " " << base[i].number;
	}

	outputFile.close();

	cout << "База сохранена" << endl;
}

void findPhone(Record base[100], int recordsNumber)
{
	int number = 0;

	cout << "Введите искомый номер" << endl;
	cin >> number;

	int counter = -1;
	bool numberIsFound = false;

	do
	{
		counter++;

		if (number == base[counter].number)
		{
			numberIsFound = true;
		}
	} while (counter < recordsNumber && !numberIsFound);

	if (numberIsFound)
	{
		cout << "Искомое имя: " << base[counter].name << endl;
	}
	else
	{
		cout << "Человек с таким номером в базе отсутствует, проверьте корректность ввода" << endl;
	}
}

void findName(Record base[100], int recordsNumber)
{
	string name = "";

	cout << "Введите искомое имя" << endl;
	cin >> name;

	int counter = -1;
	bool nameIsFound = false;

	do
	{
		counter++;

		if (name.compare(base[counter].name) == 0)
		{
			nameIsFound = true;
		}
	} while (counter < recordsNumber && !nameIsFound);

	if (nameIsFound)
	{
		cout << "Искомый номер: " << base[counter].number << endl;
	}
	else
	{
		cout << "Человек с таким именем в базе отсутствует, проверьте корректность ввода" << endl;
	}
}

int main()
{
	setlocale(LC_ALL, "rus");

	ifstream file("../base.txt", ios::in);
	Record base[100];
	int recordsNumber = 0;

	if (file.is_open())
	{
		while (!file.eof() && recordsNumber != 100)
		{
			file >> base[recordsNumber].name;
			file >> base[recordsNumber].number;

			recordsNumber++;
		}
	}

	file.close();

	unsigned short choice = 0;

	do
	{
		cout << "Введите 0 для выхода" << endl << "1 для добавления записи" << endl << "2, чтобы найти телефон по имени" << endl << "3, чтобы найти имя по телефону" << endl << "4, чтобы сохранить текущую базу в файл" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			if (recordsNumber == 100)
			{
				cout << "Достигнуто предельное число записей в базе, добавление новой записи невозможно" << endl;
			}
			else
			{
				cout << "Введите имя" << endl;
				cin >> base[recordsNumber].name;
				cout << "Введите телефон" << endl;
				cin >> base[recordsNumber].number;

				recordsNumber++;
			}
		}
		break;
		case 2:
		{
			findName(base, recordsNumber);
		}
		break;
		case 3:
		{
			findPhone(base, recordsNumber);
		}
		break;
		case 4:
		{
			saveBase(base, recordsNumber);
		}
		break;
		}

		cout << endl;
	} while (choice != 0);

	return EXIT_SUCCESS;
}

/*Общий случай:
Содержимое входного файла:
Andrew 7896079
Jack 7869809
Mike 9769679
David 7867575

Вывод консоли:
Введите 0 для выхода
1 для добавления записи
2, чтобы найти телефон по имени
3, чтобы найти имя по телефону
4, чтобы сохранить текущую базу в файл
1
Введите имя
Max
Введите телефон
7867474

Введите 0 для выхода
1 для добавления записи
2, чтобы найти телефон по имени
3, чтобы найти имя по телефону
4, чтобы сохранить текущую базу в файл
2
Введите искомое имя
Max
Искомый номер: 7867474

Введите 0 для выхода
1 для добавления записи
2, чтобы найти телефон по имени
3, чтобы найти имя по телефону
4, чтобы сохранить текущую базу в файл
2
Введите искомое имя
Mike
Искомый номер: 9769679

Введите 0 для выхода
1 для добавления записи
2, чтобы найти телефон по имени
3, чтобы найти имя по телефону
4, чтобы сохранить текущую базу в файл
3
Введите искомый номер
7869809
Искомое имя: Jack

Введите 0 для выхода
1 для добавления записи
2, чтобы найти телефон по имени
3, чтобы найти имя по телефону
4, чтобы сохранить текущую базу в файл
4
База сохранена

Введите 0 для выхода
1 для добавления записи
2, чтобы найти телефон по имени
3, чтобы найти имя по телефону
4, чтобы сохранить текущую базу в файл
0

Содержимое выходного файла:
Andrew 7896079
Jack 7869809
Mike 9769679
David 7867575
Max 7867474
*/