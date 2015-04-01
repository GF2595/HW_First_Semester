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

	cout << "���� ���������" << endl;
}

void findPhone(Record base[100], int recordsNumber)
{
	int number = 0;

	cout << "������� ������� �����" << endl;
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
		cout << "������� ���: " << base[counter].name << endl;
	}
	else
	{
		cout << "������� � ����� ������� � ���� �����������, ��������� ������������ �����" << endl;
	}
}

void findName(Record base[100], int recordsNumber)
{
	string name = "";

	cout << "������� ������� ���" << endl;
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
		cout << "������� �����: " << base[counter].number << endl;
	}
	else
	{
		cout << "������� � ����� ������ � ���� �����������, ��������� ������������ �����" << endl;
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
		cout << "������� 0 ��� ������" << endl << "1 ��� ���������� ������" << endl << "2, ����� ����� ������� �� �����" << endl << "3, ����� ����� ��� �� ��������" << endl << "4, ����� ��������� ������� ���� � ����" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			if (recordsNumber == 100)
			{
				cout << "���������� ���������� ����� ������� � ����, ���������� ����� ������ ����������" << endl;
			}
			else
			{
				cout << "������� ���" << endl;
				cin >> base[recordsNumber].name;
				cout << "������� �������" << endl;
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

/*����� ������:
���������� �������� �����:
Andrew 7896079
Jack 7869809
Mike 9769679
David 7867575

����� �������:
������� 0 ��� ������
1 ��� ���������� ������
2, ����� ����� ������� �� �����
3, ����� ����� ��� �� ��������
4, ����� ��������� ������� ���� � ����
1
������� ���
Max
������� �������
7867474

������� 0 ��� ������
1 ��� ���������� ������
2, ����� ����� ������� �� �����
3, ����� ����� ��� �� ��������
4, ����� ��������� ������� ���� � ����
2
������� ������� ���
Max
������� �����: 7867474

������� 0 ��� ������
1 ��� ���������� ������
2, ����� ����� ������� �� �����
3, ����� ����� ��� �� ��������
4, ����� ��������� ������� ���� � ����
2
������� ������� ���
Mike
������� �����: 9769679

������� 0 ��� ������
1 ��� ���������� ������
2, ����� ����� ������� �� �����
3, ����� ����� ��� �� ��������
4, ����� ��������� ������� ���� � ����
3
������� ������� �����
7869809
������� ���: Jack

������� 0 ��� ������
1 ��� ���������� ������
2, ����� ����� ������� �� �����
3, ����� ����� ��� �� ��������
4, ����� ��������� ������� ���� � ����
4
���� ���������

������� 0 ��� ������
1 ��� ���������� ������
2, ����� ����� ������� �� �����
3, ����� ����� ��� �� ��������
4, ����� ��������� ������� ���� � ����
0

���������� ��������� �����:
Andrew 7896079
Jack 7869809
Mike 9769679
David 7867575
Max 7867474
*/