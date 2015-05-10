#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "prioritetni_red.h"
using namespace std;

int procitaj_int(ifstream& dat, char separator) {
	stringstream sstr;
	string temp;
	int rez;

	getline(dat, temp, separator);
	sstr << temp;
	sstr >> rez;

	return rez;
}

int main() {
	prioritetni_red pred;

	ifstream dat("za_printanje.txt");
	if (!dat) {
		cout << "Greska pri otvaranju datoteke" << endl;
		return 1;
	}

	while (true) {
		dokument d;
		if (!getline(dat, d.naziv, ';')) {
			break;
		}

		d.broj_stranica = procitaj_int(dat, ';');
		int prioritet = procitaj_int(dat, '\n');

		pred.enqueue(d, prioritet);
	}
	dat.close();

	dokument procitano;
	while (pred.dequeue(procitano)) {
		cout << "printam dokument " << procitano.naziv << ", broj stranica: " << procitano.broj_stranica << endl;
	}

	return 0;
}
