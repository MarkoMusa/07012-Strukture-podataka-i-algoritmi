#include <iostream>
#include <string>
#include "prioritetni_red.h"
using namespace std;

int odaberi_akciju();
void napisi_spremi(prioritetni_red& pred);
void posalji(prioritetni_red& pred);

int main() {
	prioritetni_red pred;

	int odabrano;
	do {
		odabrano = odaberi_akciju();
		switch (odabrano) {
			case 1:
				napisi_spremi(pred);
				break;
			case 2:
				posalji(pred);
				break;
		}
	} while (odabrano != 3);

	return 0;
}

int odaberi_akciju() {
	int rezultat;
	cout << "------------------------------------------------" << endl;
	cout << "Odaberite:" << endl;
	cout << "1 = Napisati i spremiti e-mail" << endl;
	cout << "2 = Poslati sve napisane i spremljene e-mailove" << endl;
	cout << "3 = Zavrsetak rada" << endl;
	cout << "------------------------------------------------" << endl;
	cout << ">> ";
	cin >> rezultat;
	cin.ignore();
	return rezultat;
}

void napisi_spremi(prioritetni_red& pred) {
	email novi;

	cout << "Naslov: ";
	getline(cin, novi.naslov);

	cout << "Sadrzaj: ";
	getline(cin, novi.sadrzaj);

	int prioritet;
	do {
		cout << "Prioritet (0 = standardno, 3 = jako vazno, -3 = nevazno): ";
		cin >> prioritet;
	} while (prioritet != 0 && prioritet != 3 && prioritet != -3);

	pred.enqueue(novi, prioritet);
}

void posalji(prioritetni_red& pred) {
	email procitano;
	while (pred.dequeue(procitano)) {
		cout << procitano.naslov << ": " << procitano.sadrzaj << endl;
	}
}