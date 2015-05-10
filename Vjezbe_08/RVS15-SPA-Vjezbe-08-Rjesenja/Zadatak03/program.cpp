#include <iostream>
#include <fstream>
#include <string>
#include "heap.h"
using namespace std;

int main() {
	heap drzave;

	ifstream dat("Sifre_drzava.csv");
	if (!dat) {
		cout << "Greska pri otvaranju datoteke" << endl;
		return 1;
	}

	string temp;
	getline(dat, temp);
	while (true) {
		drzava d;
		
		if (!getline(dat, d.naziv, ';')) { 
			break;
		}

		getline(dat, d.sifra);

		drzave.insert(d);
	}
	dat.close();

	while (!drzave.is_empty()) {
		drzava iz_hrpe = drzave.remove();
		cout << iz_hrpe.naziv << " (" << iz_hrpe.sifra << ")" << endl;
	}

	return 0;
}