#include <iostream>
#include "list.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	int m = 0;
	int n = 0;

	cout << "Введите число воинов" << endl;
	cin >> n;
	cout << "Введите периодичность" << endl;
	cin >> m;

	cout << "Номер последнего выжившего: " << josephusPermutation(n, m) << endl;

	return EXIT_SUCCESS;
}


/*Общий случай:
Введите число воинов
41
Введите периодичность
3
Номер последнего выжившего: 3
*/