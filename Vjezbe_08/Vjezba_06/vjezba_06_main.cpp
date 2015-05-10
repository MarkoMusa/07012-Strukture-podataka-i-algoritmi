/*
	Promijenite prethodni program tako da se prioritet broja
	izračunava ovako: prioritet je 200 ako je broj paran, 100
	ako je broj neparan. Kojim su redoslijedom sad brojevi
	ispisani i zašto? Zašto brojevi više nisu ispisani padajuće?


	2 do 100 parni, pa 1 do 99 neparni. 
	Sada su samo dva prioriteta, veći za neparne i manji za parne tako
	da osim ove divje skupine brojevi su ispisani u redosljedu upisa 1 to 100.

*/


#include <iostream>
#include "prioritetni_red.h"

using namespace std;

int main() {
	prioritetni_red red;

	int p;
	for (int i = 1; i < 101; i++) {
		if (i%2 == 0) // Paran
			p = 200;
		else 
			p = 100;
		red.enqueue(i, p);
	}
		

	ELTYPE e;
	while (!red.is_empty())
	{
		red.dequeue(e);
		cout << e << endl;
	}

	return 0;
}