#include <iostream>
#include <string>
#include <fstream>
#include "shell_sort.h"
#include "high_res_timer.h"
using namespace std;

int main() {
	// Prvo napravimo polje brojeva.
	ifstream dat("puno_brojeva1.txt");
	if (!dat) {
		cout << "Greska pri otvaranju datoteke" << endl;
		return 1;
	}

	const int BROJ_ELEMENATA = 1000000;
	int* brojevi = new int[BROJ_ELEMENATA];
	
	for (int i = 0; i < BROJ_ELEMENATA; i++) {
		dat >> brojevi[i];
	}
	dat.close();

	hr_timer timer;

	// Sortiramo.
	start_hr_timer(timer);
	shell_sort(brojevi, BROJ_ELEMENATA);
	stop_hr_timer(timer);
	cout << "Trajanje: " << get_elapsed_time_microsec(timer) / 1000000 << " s" << endl;
	delete[] brojevi;
	return 0;
}