/*
	Promijenite prvi zadatak tako da umjesto dinamičke liste koristite listu implementiranu poljem
*/
#include "lista_poljem.h"
#include "high_res_timer.h"
#include <ctime>
#include <iostream>

int main() {
	lista_poljem numbers;
	hr_timer timer;
	srand(time(nullptr));

	// Fill list and measure time
	int randNmbr;
	POSITION start = numbers.first();

	// How much does random number generatoin skew totals?
	// Ccould start/stop new timer before/after every insert and keep a total
	start_hr_timer(timer);
	for (int i = 0; i < 100000; i++)
	{
		randNmbr = rand() % 100 + 1;
		numbers.insert(randNmbr,start);
	}
	stop_hr_timer(timer);
	cout << " Added 100,000 elements to dynamic list in " << get_elapsed_time_microsec(timer)/1000 << " ms" << endl;

	int total = 0;
	ELTYPE element;
	start_hr_timer(timer);
	for (POSITION i = numbers.first(); i != numbers.end();)
	{
		numbers.read(i,element);
		total += element;
		i = numbers.next(i);
	}
	stop_hr_timer(timer);
	cout << " Averaged 100,000 elements (" <<  total/100000 << ") in " << get_elapsed_time_microsec(timer)/1000 << " ms" << endl;
}
/*
 Added 100,000 elements to array list in 9831.18 ms
 Averaged 100,000 elements (50) in 11.577 ms
 */