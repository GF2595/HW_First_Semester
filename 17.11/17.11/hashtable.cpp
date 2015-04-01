#include "pointerList.h"
#include <vector>
#include <string>

using namespace std;

struct Hashtable {
	vector<List*> table;
};

Hashtable* makeTable()
{
	Hashtable *newTable = new Hashtable;
	vector < List* > temp(10000);

	for (int i = 0; i < 10000; i++)
	{
		temp[i] = makeList();
	}

	newTable->table = temp;

	return newTable;
}

//Computes hashfunction for specified string
//Receives string
//Returns hash function result
int hashFunction(string const &element)
{
	unsigned long long int primeNumber = 1;
	unsigned long long int hash = 0;

	for (int i = 0; i < element.length(); i++)
	{
		int letterCode = 0;
		if (element[i] >= 'A' && element[i] <= 'Z')
		{
			letterCode = element[i] - 64;
		}
		else if (element[i] >= 'a' && element[i] <= 'z')
		{
			letterCode = element[i] - 80;
		}
		else
		{
			switch (element[i])
			{
			case '!':
			{
				letterCode = 53;
			}
				break;
			case '?':
			{
				letterCode = 54;
			}
				break;
			case '.':
			{
				letterCode = 55;
			}
				break;
			case ',':
			{
				letterCode = 56;
			}
				break;
			case ':':
			{
				letterCode = 57;
			}
				break;
			case ')':
			{
				letterCode = 58;
			}
				break;
			case '(':
			{
				letterCode = 59;
			}
				break;
			default:
			{
				letterCode = 60;
			}
				break;
			}
		}

		hash += letterCode * primeNumber;
		primeNumber *= 61;
	}

	return hash % 10000;
}

void addHashElement(Hashtable *table, std::string element)
{
	addTimesFound(table->table[hashFunction(element)], element);
}

void printTable(Hashtable *table)
{
	for (int i = 0; i < 10000; i++)
	{
		printList(table->table[i]);
	}
}

void deleteTable(Hashtable *table)
{
	for (int i = 0; i < 10000; i++)
	{
		deleteList(table->table[i]);
	}

	delete table;
}