#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "high_res_timer.h"
using namespace std;

int main() {
	hr_timer timer;
	int* brojevi = new int[20000];

	// Upis u polje.
	ifstream dat("slucajni_brojevi.txt");
	if (!dat) {
		cout << "Greska pri otvaranju ulazne datoteke" << endl;
		return 1;
	}

	int i = 0;
	string procitano;
	stringstream sstr;
	while (getline(dat, procitano, ' ')) {
		sstr << procitano;
		sstr >> brojevi[i];
		sstr.str("");
		sstr.clear();
		i++;
	}

	dat.close();

	// Pretraživanje.
	int trazeni_broj;
	cout << "Upisite broj: ";
	cin >> trazeni_broj;

	start_hr_timer(timer);
	bool pronadjen = false;
	for (int i = 0; i < 20000; i++) {
		if (brojevi[i] == trazeni_broj) {
			cout << "Trazeni broj postoji." << endl;
			pronadjen = true;
			break;
		}
	}

	if (!pronadjen) {
		cout << "Trazeni broj ne postoji." << endl;
	}
	stop_hr_timer(timer);

	cout << "Pretraga je trajala: " << get_elapsed_time_microsec(timer) << endl;

	delete[] brojevi;
	return 0;
}