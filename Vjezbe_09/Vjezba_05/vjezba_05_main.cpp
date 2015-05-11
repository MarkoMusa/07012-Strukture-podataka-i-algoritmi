/*
	Promijenite insertion sort tako da radi s bankama (naziv,
	VBDI identifikator). Učitajte svih 9 banaka iz datoteke
	banke.bin (format je dan u tablici ispod), sortirajte ih
	padajuće prema nazivu te ih sortirano ispišite na ekran.
	Duljina u bajtovima Opis
	2  n = duljina naziva banke
	n naziv banke
	7 VBDI banke
*/

#include "insertion_sort.h"
#include "Banka.h"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

int get_data(Banka* banks) {
	int i = 0;
	short nameLength = 0;


	ifstream ifs("banke.bin", ios_base::binary);
	if (!ifs)
	{
		cout << "error opening file";
		return 1;
	}


	while (ifs)
	{
		ifs.read( (char*)(&nameLength), 2);

		if(!ifs)
			break;
		char* ime = new char[nameLength];
		char* VBDI = new char[7];

		ifs.read(ime, nameLength);
		ifs.read(VBDI, 7);

		string imeStr(ime, nameLength);
		string VBDIStr(VBDI, 7);

		banks[i].ime = imeStr;
		banks[i].VBDI = VBDIStr;

		i++;
		delete[] ime;
		delete[] VBDI;
	}

	ifs.close();
	return 0;
}

void show(Banka* ps, int size) {

	for (int i = 0; i < size; i++)
		cout << i << ": " << ps[i].ime << ", " << ps[i].VBDI << endl;

}

int main() {
	int size = 9;
	Banka* banke = new Banka[size];
	
	if(get_data(banke) == 1)
		return 1;


	insertion_sort(banke, size);
	show(banke, size);

	return 0;
}