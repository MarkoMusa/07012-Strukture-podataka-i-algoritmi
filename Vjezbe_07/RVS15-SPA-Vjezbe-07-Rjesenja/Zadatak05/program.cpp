#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <ctime>
#include "bst.h"
using namespace std;

int main() {
	bst drzave;

	ifstream dat("Drzave.csv");
	if (!dat) {
		cout << "Greska pri otvaranju ulazne datoteke" << endl;
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

	ELTYPE upit;
	cout << "Upisite sifru drzave: ";
	getline(cin, upit.sifra);

	if (drzave.exists(upit)) {
		cout << "Drzava postoji." << endl;
	}
	else {
		cout << "Drzava ne postoji." << endl;
	}

	return 0;
}