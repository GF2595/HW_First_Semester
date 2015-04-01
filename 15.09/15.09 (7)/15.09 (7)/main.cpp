#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

int main()
{
	int n;

	cout << "Insert number" << endl;
	cin >> n;

	vector<bool> prime(n + 1, true);
	prime[0] = prime[1] = false;
	for (int i = 2; i*i <= n; ++i)
	{
		if (prime[i])
		{
			for (int j = i*i; j <= n; j += i)
			{
				prime[j] = false;
			}
		}
	}

	for (int i = 1; i < n + 1; i++)
	{
		if (prime[i] == 1)
		{
			cout << i << " ";
		}
	}
	
	return EXIT_SUCCESS;
}