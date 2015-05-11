/*
		 Učitajte 1.000.000 slučajnih brojeva iz datoteke
	puno_brojeva1.txt u program. Ispišite koliko traje njihovo
	sortiranje shell sortom. Nakon toga, promijenite shell sort
	algoritam tako da umjesto originalne sekvence razmaka
	koristi Tokudinu sekvencu iz 1992. Kako se promijenilo
	vrijeme sortiranja?
	o Uputa za rješavanje: sve sekvence koje počinju od 1 se koriste
	na sljedeći način: pomoću formule treba unaprijed izračunati
	sve elemente sekvence manje od veličine polja. Nakon toga, te
	elemente sekvence treba primijeniti na polje, ali obrnutim
	redoslijedom. Primjerice, ako imamo polje od 100 elemenata,
	prvo ćemo izračunati Tokudinu sekvencu 1, 4, 9, 20, 46, a zatim
	ćemo je primijeniti na polje, ali počevši od 46 pa sve do 1.
*/


#include <fstream>
#include <iostream>
#include <sstream>
#include "high_res_timer.h"
#include "shell_sort.h"
#include "shell_sort_Tokudin.h"


using namespace std;

// testing tokudin formula generation
void gen(int n){

	// assume we will not have more then 100 steps, will overflow int way before that
	int steps[100];
	int i = -1;			// keep track of index after loop
	do {				// Generate steps untill we pass n
		i++;
		steps[i] = (int)((pow(9,i) - pow(4,i)) / (5*pow(4,i - 1)) ) + 1;
	} while(steps[i] < n);
	i--; // TODO: fix this when its not so late

	for (int step = steps[i]; i >= 0; step = steps[i--]) {
		cout << steps[i] << endl;
	}
}


/// Fill numbers into array
// Bad code assumes input file is just right for array elements
// should pass size and read that many in a for loop
int get_numbers(int* numbers, int size) {

	ifstream ifs("puno_brojeva1.txt");
	if (!ifs)
	{
		cout << "error opening file";
		return 1;
	}

	std::stringstream buffer;
	buffer << ifs.rdbuf();

	for (int i = 0; i < size; i++)
		buffer >> numbers[i];

	return 0;
}

int main() {

	hr_timer timer;
	int size = 1000000;
	int* numbers = new int[size];
	int* numbersCopy = new int[size];
	

	//gen(100);
	//return 0;

	if(get_numbers(numbers, size) == 1)
		return 1;

	// SHELL
	memcpy(numbersCopy, numbers , size*sizeof(int));
	start_hr_timer(timer);
	shell_sort(numbersCopy, size);
	stop_hr_timer(timer);
	cout << "Shell sort in " << get_elapsed_time_microsec(timer)/60 << endl;

	// SHELL Tukadin
	memcpy(numbersCopy, numbers , size*sizeof(int));
	start_hr_timer(timer);
	shell_sort_Tokudin(numbersCopy, size);
	stop_hr_timer(timer);
	cout << "Tokudin Shell sort in " << get_elapsed_time_microsec(timer)/60 << endl;

	delete[] numbers;
	delete[] numbersCopy;
	return 0;
}