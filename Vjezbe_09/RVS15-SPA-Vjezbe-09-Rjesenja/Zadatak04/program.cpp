#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include "selection_sort.h"
#include "pravokutnik.h"
using namespace std;

int main() {
	// Prvo napravimo polje pravokutnika.
	ifstream dat("pravokutnici.txt");
	if (!dat) {
		cout << "Greska pri otvaranju datoteke" << endl;
		return 1;
	}
	const int BROJ_ELEMENATA = 1000;

	pravokutnik* pravokutnici = new pravokutnik[BROJ_ELEMENATA];
	
	int temp;
	for (int i = 0; i < BROJ_ELEMENATA; i++) {
		dat >> temp;
		pravokutnici[i].a = temp;
		dat >> temp;
		pravokutnici[i].b = temp;
	}
	dat.close();

	// Sortiramo i upišemo u drugu datoteku.
	ofstream datout("pravokutnici_sortirano.txt");
	if (!datout) {
		cout << "Greska pri otvaranju datoteke" << endl;
		return 2;
	}

	selection_sort(pravokutnici, BROJ_ELEMENATA);
	for (int i = 0; i < BROJ_ELEMENATA; i++) {
		datout << pravokutnici[i].a << " " << pravokutnici[i].b << endl;
	}

	datout.close();
	delete[] pravokutnici;
	return 0;
}