#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	srand(time(nullptr));

	int const length = 10;
	int array[length];
	int numOfNull = 0;

	for (int i = 0; i < (length); i++)
	{
		array[i] = rand() % 10;
		if (!array[i])
		{
			numOfNull++;
		}
	}

	cout << "There is " << numOfNull << " zeros in array" << endl;

	return EXIT_SUCCESS;
}