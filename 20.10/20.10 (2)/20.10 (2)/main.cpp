#include <iostream>
#include <vector>
#include "list.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	List *list = makeList();
	int choice = 0;

	do
	{
		cout << "������� 0 ��� ������" << endl << "1, ����� �������� �������� � ������" << endl << "2, ����� ������� �������� �� ������" << endl << "3, ����� ����������� ������" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
			{
				cout << "������� ��������" << endl;
				ElementType temp = 0;
				cin >> temp;

				unsigned position = search(list, temp);
				insertElement(list, position, temp);
			}
			break;
		case 2:
			{
				cout << "������� ��������" << endl;
				ElementType temp = 0;
				cin >> temp;

				deleteElement(list, temp);
			}
			break;
		case 3:
			{
				printList(list);
			}
		}
	} while (choice != 0);

	deleteList(list);

	return EXIT_SUCCESS;
}

/*����� ������:
������� 0 ��� ������
1, ����� �������� �������� � ������
2, ����� ������� �������� �� ������
3, ����� ����������� ������
1
������� ��������
1
������� 0 ��� ������
1, ����� �������� �������� � ������
2, ����� ������� �������� �� ������
3, ����� ����������� ������
1
������� ��������
2
������� 0 ��� ������
1, ����� �������� �������� � ������
2, ����� ������� �������� �� ������
3, ����� ����������� ������
1
������� ��������
4
������� 0 ��� ������
1, ����� �������� �������� � ������
2, ����� ������� �������� �� ������
3, ����� ����������� ������
1
������� ��������
3
������� 0 ��� ������
1, ����� �������� �������� � ������
2, ����� ������� �������� �� ������
3, ����� ����������� ������
3
1 2 3 4
������� 0 ��� ������
1, ����� �������� �������� � ������
2, ����� ������� �������� �� ������
3, ����� ����������� ������
2
������� ��������
3
������� 0 ��� ������
1, ����� �������� �������� � ������
2, ����� ������� �������� �� ������
3, ����� ����������� ������
3
1 2 4
������� 0 ��� ������
1, ����� �������� �������� � ������
2, ����� ������� �������� �� ������
3, ����� ����������� ������
1
������� ��������
5
������� 0 ��� ������
1, ����� �������� �������� � ������
2, ����� ������� �������� �� ������
3, ����� ����������� ������
3
1 2 4 5
������� 0 ��� ������
1, ����� �������� �������� � ������
2, ����� ������� �������� �� ������
3, ����� ����������� ������
0
*/