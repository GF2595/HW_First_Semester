#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

bool isInString(string strMain, string strSrch, int position)
{
	int lstrMain = strMain.length();
	int lstrSrch = strSrch.length();


	if ((lstrMain - position) >= lstrSrch)
	{
		int j = 0;
		do
		{
			j++;
		}
		while (j < lstrSrch - 1 && strSrch[j] == strMain[position + j]);
		if (j == lstrSrch - 1 && strSrch[j] == strMain[position + j])
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

int main()
{
	string s;
	string s1;
	int counter = 0;

	cout << "Insert string S" << endl;
	cin >> s;
	cout << "Insert string S1" << endl;
	cin >> s1;

	int length = s.length();
	for (int i = 0; i < length; i++)
	{
		if (s[i] == s1[0])
		{
			if (isInString(s, s1, i))
			{
				counter++;
			}
		}
	}

	cout << "s1 is contained in s for " << counter << " times" << endl;

	return EXIT_SUCCESS;
}