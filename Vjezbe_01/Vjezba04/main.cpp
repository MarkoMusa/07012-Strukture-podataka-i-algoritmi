/*
 Iz binarne datoteke banke.bin učitajte podatke o bankama i njihovim VBDI brojevima (vodeći broj
depozitne institucije - broj koji jedinstveno označava banku, koristi se kao prvi dio broja kod plaćanja na neki
račun u banci). Ispišite sve banke i njihove VBDI-jeve obrnutim redoslijedom. 
	1st 2 bytes = bank name length
	n byes = bank name
	7 bytes = VBDI
*/

#include "Bank.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int readBanksFileIntoVector(string fn, vector<Bank>& banks) {
	ifstream ifs(fn, ios_base::binary);
	if(!ifs)
		return 1;

	while (true)
	{
			
		int bankNameLength = 0;
		ifs.read((char*)(&bankNameLength), 2);

		char* tmp = new char[bankNameLength];
		ifs.read(tmp, bankNameLength);
		string bankName = string(tmp, bankNameLength);
		delete[] tmp;

		tmp = new char[7];
		ifs.read(tmp, 7);
		string vbdi = string(tmp, 7);
		delete[] tmp;

			
		if (ifs.eof())
			break;

		// For some reason an extra loop always happens, so ignore last entry.
		Bank b(bankName, vbdi);
		banks.push_back(b);
	}

	ifs.close();
	return 0;
}


int main() {
	vector<Bank> banks;
	string fn = "banke.bin";

	if (readBanksFileIntoVector(fn, banks))
	{
		cout << "Error reading file";
		return 1;
	}

	for (int i = banks.size() - 1; i >= 0; i--)
	{
		cout << banks[i].getName() << " " << banks[i].getVBDI() << endl;
	}
	return 0;
}

