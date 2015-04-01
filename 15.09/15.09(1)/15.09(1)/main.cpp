#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
	int varx;

	cout << "Insert x" << endl;
	cin >> varx;

	int const sqrx = varx * varx;

	cout << "Result of formula is " << (sqrx + varx) * (sqrx + 1) + 1 << endl;
	
	return EXIT_SUCCESS;
}