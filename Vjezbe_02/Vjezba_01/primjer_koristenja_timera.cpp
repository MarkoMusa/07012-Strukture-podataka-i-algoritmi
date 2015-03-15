#include <iostream>
#include "high_res_timer.h"
using namespace std;

int main() {
	hr_timer timer; // Instanca mjeraèa.
	start_hr_timer(timer); // Zapamti vrijeme poèetka.

	// ...
	// ...
	// ...
	
	stop_hr_timer(timer); // Zapamti vrijeme kraja.

	// Ispiši vrijeme trajanja
	cout << get_elapsed_time_microsec(timer) / 1000 << " ms" << endl;

	return 0;
}