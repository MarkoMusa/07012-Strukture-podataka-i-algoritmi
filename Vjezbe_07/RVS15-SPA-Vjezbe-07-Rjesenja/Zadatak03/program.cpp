#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <ctime>
#include "high_res_timer.h"
#include "bst.h"
using namespace std;

int main() {
	hr_timer timer;
	bst brojevi;

	// Upis u polje.
	ifstream dat("slucajni_brojevi.txt");
	if (!dat) {
		cout << "Greska pri otvaranju ulazne datoteke" << endl;
		return 1;
	}

	int i = 0;
	string procitano;
	stringstream sstr;
	int broj;
	while (getline(dat, procitano, ' ')) {
		sstr << procitano;
		sstr >> broj;
		brojevi.insert(broj);
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
	if (brojevi.exists(trazeni_broj)) {
		cout << "Trazeni broj postoji." << endl;
	}
	else {
		cout << "Trazeni broj ne postoji." << endl;
	}
	stop_hr_timer(timer);

	cout << "Pretraga je trajala: " << get_elapsed_time_microsec(timer) << endl;

	return 0;
}