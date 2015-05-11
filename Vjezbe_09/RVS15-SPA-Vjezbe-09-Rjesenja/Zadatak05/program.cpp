#include <iostream>
#include <string>
#include <fstream>
#include "insertion_sort.h"
#include "banka.h"
using namespace std;

string procitaj_string(ifstream& dat, int duljina) {
	char* temp = new char[duljina];
	dat.read(temp, duljina);
	string s(temp, duljina);
	delete[] temp;
	return s;
}

int main() {
	// Prvo napravimo polje banaka.
	ifstream dat("banke.bin", ios_base::binary);
	if (!dat) {
		cout << "Greska pri otvaranju datoteke" << endl;
		return 1;
	}
	const int BROJ_ELEMENATA = 9;

	banka* banke = new banka[BROJ_ELEMENATA];
	
	short n;
	for (int i = 0; i < BROJ_ELEMENATA; i++) {
		dat.read((char*)(&n), sizeof(n));
		banke[i].naziv = procitaj_string(dat, n);
		banke[i].vbdi = procitaj_string(dat, 7);
	}
	dat.close();

	// Sortiramo i ispišemo.
	insertion_sort(banke, BROJ_ELEMENATA);
	for (int i = 0; i < BROJ_ELEMENATA; i++) {
		cout << banke[i].naziv << " (" << banke[i].vbdi << ")" << endl;
	}

	delete[] banke;
	return 0;
}