#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	ifstream file("../file.txt", ios::in);
	if (!file.is_open())
	{
		cout << "Файл не найден" << endl;

		return EXIT_FAILURE;
	}

	int n = 0;
	int m = 0;

	file >> n;
	file >> m;

	vector<vector<int>> roadsTable;

	for (int i = 0; i < n; i++)
	{
		vector<int> temp;

		for (int j = 0; j < n; j++)
		{
			temp.push_back(0);
		}

		roadsTable.push_back(temp);
	}

	for (int i = 0; i < m; i++)
	{
		int firstCity = 0;
		int secondCity = 0;

		file >> firstCity;
		file >> secondCity;
		file >> roadsTable[firstCity - 1][secondCity - 1];
		roadsTable[secondCity - 1][firstCity - 1] = roadsTable[firstCity - 1][secondCity - 1];
	}

	int k = 0;

	file >> k;

	int freeCitiesNumber = n - k;

	vector<vector<int>> states;

	for (int i = 0; i < k; i++)
	{
		vector<int> temp;

		states.push_back(temp);
	}

	for (int i = 0; i < k; i++)
	{
		int temp = 0;

		file >> temp;

		states[i].push_back(temp - 1);
		
		for (int i = 0; i < n; i++)
		{
			roadsTable[i][temp - 1] = 0;
		}
	}
	
	file.close();

	int currentState = 0;

	do
	{
		int minimalRoadLength = 2147483647;
		int minimalRoadHostCity = -1;

		unsigned temp = states[currentState].size();

		for (unsigned i = 0; i < temp; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (roadsTable[states[currentState][i]][j] < minimalRoadLength && roadsTable[states[currentState][i]][j] != 0)
				{
					minimalRoadLength = roadsTable[states[currentState][i]][j];

					minimalRoadHostCity = j;
				}
			}
		}

		if (minimalRoadHostCity != -1)
		{
			for (int i = 0; i < n; i++)
			{
				roadsTable[i][minimalRoadHostCity] = 0;
			}

			states[currentState].push_back(minimalRoadHostCity);

			freeCitiesNumber--; 
		}

		if (currentState == k - 1)
		{
			currentState = 0;
		}
		else
		{
			currentState++;
		}
	} while (freeCitiesNumber != 0);

	for (int i = 0; i < k; i++)
	{
		int temp = states[i].size();

		cout << "Государство №" << i + 1 << endl;

		for (int j = 0; j < temp; j++)
		{
			cout << states[i][j] + 1 << endl;
		}

		cout << endl;
	}

	return EXIT_SUCCESS;
}


/*Общий случай:
Содержимое входного файла:
6
10
1 3 7
1 4 10
1 5 4
2 3 1
2 4 9
2 5 6
6 3 5
6 4 3
6 5 2
6 2 2
3
1 2 6

Вывод консоли:
Государство №1
1
5

Государство №2
2
3

Государство №3
6
4

*/