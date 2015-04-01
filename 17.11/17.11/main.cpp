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


/*Общий случай:
Содержимое файла:
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


Вывод консоли:
Слово A встретилось1 раз

Слово I встретилось8 раз

Слово a встретилось2 раз

Слово waves. встретилось1 раз

Слово comfortably встретилось1 раз

Слово become встретилось1 раз

Слово through встретилось1 раз

Слово are встретилось2 раз

Слово feeling встретилось2 раз

Слово feet встретилось1 раз

Слово Well встретилось1 раз

Слово again. встретилось1 раз

Слово me встретилось1 раз

Слово was встретилось1 раз

Слово if встретилось1 раз

Слово I've встретилось1 раз

Слово can't встретилось2 раз

Слово home? встретилось1 раз

Слово in встретилось2 раз

Слово on встретилось3 раз

Слово would встретилось1 раз

Слово hear встретилось3 раз

Слово no встретилось1 раз

Слово Is встретилось2 раз

Слово is встретилось2 раз

Слово at встретилось1 раз

Слово it встретилось1 раз

Слово Hello? встретилось1 раз
Слово only встретилось1 раз

Слово receding встретилось1 раз

Слово My встретилось1 раз

Слово understand встретилось1 раз

Слово Can встретилось1 раз

Слово can встретилось2 раз

Слово I'll встретилось1 раз

Слово pain встретилось2 раз

Слово Just встретилось2 раз

Слово just встретилось1 раз

Слово facts. встретилось1 раз

Слово Relax. встретилось1 раз

Слово again встретилось1 раз

Слово coming встретилось1 раз

Слово explain встретилось1 раз

Слово hurts? встретилось1 раз

Слово lips встретилось1 раз

Слово Get встретилось1 раз

Слово had встретилось1 раз

Слово horizon. встретилось1 раз

Слово got встретилось1 раз

Слово not встретилось2 раз

Слово anybody встретилось1 раз

Слово me. встретилось1 раз

Слово that встретилось1 раз

Слово what встретилось1 раз

Слово but встретилось1 раз

Слово nod встретилось1 раз

Слово Come встретилось1 раз

Слово some встретилось1 раз

Слово am. встретилось1 раз

Слово hands встретилось1 раз

Слово basic встретилось1 раз

Слово child встретилось1 раз

Слово felt встретилось1 раз

Слово Your встретилось1 раз

Слово your встретилось2 раз

Слово Now встретилось1 раз

Слово how встретилось1 раз

Слово now встретилось1 раз

Слово numb. встретилось1 раз

Слово down. встретилось1 раз

Слово two встретилось1 раз

Слово ease встретилось1 раз

Слово fever встретилось1 раз

Слово ship встретилось1 раз

Слово saying. встретилось1 раз

Слово smoke встретилось1 раз

Слово anyone встретилось1 раз

Слово distant встретилось1 раз

Слово like встретилось1 раз

Слово This встретилось1 раз

Слово When встретилось1 раз

Слово have встретилось1 раз

Слово need встретилось1 раз

Слово show встретилось1 раз

Слово balloons. встретилось1 раз

Слово information встретилось1 раз

Слово once встретилось1 раз

Слово first. встретилось1 раз

Слово you're встретилось2 раз

Слово You встретилось1 раз

Слово you встретилось5 раз

Слово There встретилось1 раз

Слово the встретилось2 раз

Слово there встретилось2 раз

Слово where встретилось1 раз

Слово there? встретилось1 раз

Слово move встретилось1 раз

*/