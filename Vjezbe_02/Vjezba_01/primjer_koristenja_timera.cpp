#include <iostream>
#include "high_res_timer.h"
using namespace std;

int main() {
	hr_timer timer; // Instanca mjera�a.
	start_hr_timer(timer); // Zapamti vrijeme po�etka.

	// ...
	// ...
	// ...
	
	stop_hr_timer(timer); // Zapamti vrijeme kraja.

	// Ispi�i vrijeme trajanja
	cout << get_elapsed_time_microsec(timer) / 1000 << " ms" << endl;

	return 0;
}