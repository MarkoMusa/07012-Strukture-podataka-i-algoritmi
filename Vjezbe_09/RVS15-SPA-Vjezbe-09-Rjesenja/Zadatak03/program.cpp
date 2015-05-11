#include <iostream>
#include <string>
#include <fstream>
#include "bubble_sort.h"
#include "selection_sort.h"
#include "insertion_sort.h"
#include "shell_sort.h"
#include "merge_sort.h"
#include "high_res_timer.h"
using namespace std;

void prekopiraj(int* originalni_brojevi, int* radno_polje, const int BROJ_ELEMENATA) {
	for (int i = 0; i < BROJ_ELEMENATA; i++) {
		radno_polje[i] = originalni_brojevi[i];
	}
}

int main() {
	// Prvo uèitamo brojeve iz datoteke u oba polja.
	ifstream dat("puno_brojeva3.txt");
	if (!dat) {
		cout << "Greska pri otvaranju datoteke" << endl;
		return 1;
	}
	const int BROJ_ELEMENATA = 20000;

	int* originalni_brojevi = new int[BROJ_ELEMENATA];
	int* radno_polje = new  int[BROJ_ELEMENATA];

	int temp;
	for (int i = 0; i < BROJ_ELEMENATA; i++) {
		dat >> temp;
		originalni_brojevi[i] = temp;
		radno_polje[i] = temp;
	}
	dat.close();

	hr_timer timer;
	
	// Bubble sort.
	start_hr_timer(timer);
	bubble_sort(radno_polje, BROJ_ELEMENATA);
	stop_hr_timer(timer);
	cout << "Bubble sort: " << get_elapsed_time_microsec(timer) / 1000 << " ms" << endl;

	// Selection sort.
	prekopiraj(originalni_brojevi, radno_polje, BROJ_ELEMENATA);
	start_hr_timer(timer);
	selection_sort(radno_polje, BROJ_ELEMENATA);
	stop_hr_timer(timer);
	cout << "Selection sort: " << get_elapsed_time_microsec(timer) / 1000 << " ms" << endl;

	// Insertion sort.
	prekopiraj(originalni_brojevi, radno_polje, BROJ_ELEMENATA);
	start_hr_timer(timer);
	insertion_sort(radno_polje, BROJ_ELEMENATA);
	stop_hr_timer(timer);
	cout << "Insertion sort: " << get_elapsed_time_microsec(timer) / 1000 << " ms" << endl;

	// Shell sort.
	prekopiraj(originalni_brojevi, radno_polje, BROJ_ELEMENATA);
	start_hr_timer(timer);
	shell_sort(radno_polje, BROJ_ELEMENATA);
	stop_hr_timer(timer);
	cout << "Shell sort: " << get_elapsed_time_microsec(timer) / 1000 << " ms" << endl;

	// Merge sort.
	prekopiraj(originalni_brojevi, radno_polje, BROJ_ELEMENATA);
	start_hr_timer(timer);
	merge_sort(radno_polje, BROJ_ELEMENATA);
	stop_hr_timer(timer);
	cout << "Merge sort: " << get_elapsed_time_microsec(timer) / 1000 << " ms" << endl;
	
	delete[] originalni_brojevi;
	delete[] radno_polje;
	return 0;
}