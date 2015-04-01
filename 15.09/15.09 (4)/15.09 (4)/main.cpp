#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
	int array[28] = { 0 };

	for (int i = 0; i <= 9; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			for (int k = 0; k <= 9; k++)
			{
				array[i + j + k]++;
			}
		}
	}

	int result = 0;

	for (int i = 0; i < 28; i++)
	{
		result = result + array[i] * array[i];
	}

	cout << "Number of 'happy' tickets is " << result << endl;

	return EXIT_SUCCESS;
}