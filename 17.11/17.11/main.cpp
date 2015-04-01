#include <iostream>
#include <fstream>
#include <string>
#include "hashtable.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	ifstream file("../file.txt", ios::in);
	if (!file.is_open())
	{
		cout << "File not found!" << endl;
		return EXIT_FAILURE;
	}

	Hashtable *table = makeTable();

	while (!file.eof())
	{
		string temp;
		file >> temp;

		addHashElement(table, temp);
	}

	printTable(table);

	deleteTable(table);
	file.close();

	return EXIT_SUCCESS;
}


/*����� ������:
���������� �����:
Hello?
Is there anybody in there?
Just nod if you can hear me.
Is there anyone at home?
Come on now
I hear you're feeling down.
Well I can ease your pain
Get you on your feet again.
Relax.
I'll need some information first.
Just the basic facts.
Can you show me where it hurts?

There is no pain you are receding
A distant ship smoke on the horizon.
You are only coming through in waves.
Your lips move but I can't hear what you're saying.
When I was a child I had a fever
My hands felt just like two balloons.
Now I've got that feeling once again
I can't explain you would not understand
This is not how I am.
I have become comfortably numb.


����� �������:
����� A �����������1 ���

����� I �����������8 ���

����� a �����������2 ���

����� waves. �����������1 ���

����� comfortably �����������1 ���

����� become �����������1 ���

����� through �����������1 ���

����� are �����������2 ���

����� feeling �����������2 ���

����� feet �����������1 ���

����� Well �����������1 ���

����� again. �����������1 ���

����� me �����������1 ���

����� was �����������1 ���

����� if �����������1 ���

����� I've �����������1 ���

����� can't �����������2 ���

����� home? �����������1 ���

����� in �����������2 ���

����� on �����������3 ���

����� would �����������1 ���

����� hear �����������3 ���

����� no �����������1 ���

����� Is �����������2 ���

����� is �����������2 ���

����� at �����������1 ���

����� it �����������1 ���

����� Hello? �����������1 ���
����� only �����������1 ���

����� receding �����������1 ���

����� My �����������1 ���

����� understand �����������1 ���

����� Can �����������1 ���

����� can �����������2 ���

����� I'll �����������1 ���

����� pain �����������2 ���

����� Just �����������2 ���

����� just �����������1 ���

����� facts. �����������1 ���

����� Relax. �����������1 ���

����� again �����������1 ���

����� coming �����������1 ���

����� explain �����������1 ���

����� hurts? �����������1 ���

����� lips �����������1 ���

����� Get �����������1 ���

����� had �����������1 ���

����� horizon. �����������1 ���

����� got �����������1 ���

����� not �����������2 ���

����� anybody �����������1 ���

����� me. �����������1 ���

����� that �����������1 ���

����� what �����������1 ���

����� but �����������1 ���

����� nod �����������1 ���

����� Come �����������1 ���

����� some �����������1 ���

����� am. �����������1 ���

����� hands �����������1 ���

����� basic �����������1 ���

����� child �����������1 ���

����� felt �����������1 ���

����� Your �����������1 ���

����� your �����������2 ���

����� Now �����������1 ���

����� how �����������1 ���

����� now �����������1 ���

����� numb. �����������1 ���

����� down. �����������1 ���

����� two �����������1 ���

����� ease �����������1 ���

����� fever �����������1 ���

����� ship �����������1 ���

����� saying. �����������1 ���

����� smoke �����������1 ���

����� anyone �����������1 ���

����� distant �����������1 ���

����� like �����������1 ���

����� This �����������1 ���

����� When �����������1 ���

����� have �����������1 ���

����� need �����������1 ���

����� show �����������1 ���

����� balloons. �����������1 ���

����� information �����������1 ���

����� once �����������1 ���

����� first. �����������1 ���

����� you're �����������2 ���

����� You �����������1 ���

����� you �����������5 ���

����� There �����������1 ���

����� the �����������2 ���

����� there �����������2 ���

����� where �����������1 ���

����� there? �����������1 ���

����� move �����������1 ���

*/