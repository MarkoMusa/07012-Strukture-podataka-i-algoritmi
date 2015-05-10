/*
Napišite program koji u prioritetni red ubacuje brojeve od
1 do 100, pri čemu je prioritet jednak samom broju.
Obradite (ispišite) sve brojeve iz dinamičkog reda. Kojim
redoslijedom su brojevi ispisani i objasnite zašto?

100 to 1, 100 is highest priority.

*/

#include <iostream>
#include "prioritetni_red.h"

using namespace std;

int main() {
	prioritetni_red red;

	for (int i = 1; i < 101; i++)
		red.enqueue(i, i);

	ELTYPE e;
	while (!red.is_empty())
	{
		red.dequeue(e);
		cout << e << endl;
	}

	return 0;
}