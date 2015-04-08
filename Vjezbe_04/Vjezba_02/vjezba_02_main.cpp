/*
	Promijenite prethodni zadatak tako da umjesto na početak ubacujete na kraj liste.
*/
#include "lista_dinamicka.h"
#include "high_res_timer.h"
#include <ctime>
#include <iostream>

int main() {
	lista_dinamicka numbers;
	POSITION pos = numbers.end();
	ELTYPE element;

	hr_timer timer;
	srand(time(nullptr));

	int randNmbr;
	int total = 0;

		
	start_hr_timer(timer);
	for (int i = 0; i < 100000; i++)
	{
		randNmbr = rand() % 100 + 1;
		numbers.insert(randNmbr,pos);
	}
	stop_hr_timer(timer);
	cout << " Added 100,000 elements to dynamic list in " << get_elapsed_time_microsec(timer)/1000 << " ms" << endl;
	
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
	Added 100,000 elements to dynamic list in 23.871 ms
	Averaged 100,000 elements (50) in 7.881 ms
*/