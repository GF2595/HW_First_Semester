#include <iostream>
#include "list.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	int m = 0;
	int n = 0;

	cout << "������� ����� ������" << endl;
	cin >> n;
	cout << "������� �������������" << endl;
	cin >> m;

	cout << "����� ���������� ���������: " << josephusPermutation(n, m) << endl;

	return EXIT_SUCCESS;
}


/*����� ������:
������� ����� ������
41
������� �������������
3
����� ���������� ���������: 3
*/