/*
	Iz datoteke slucajni_brojevi.txt učitajte sve brojeve u
	polje (brojeva ima 20.000). Omogućite korisniku unos
	broja, a zatim pretraživanjem polja i ispis postoji li broj u
	polju ili ne. Ispišite koliko traje pretraživanje.
*/

#include <iostream>
#include <fstream>
#include <string>
#include "high_res_timer.h"

using namespace std;


int find_in_array(int& n, int array[], int& arrayLength)
{
	for (int i = 0; i < arrayLength; i++)
		if (array[i] == n)
			return i;
	return -1;
}

int main()
{
	static const int arrayLength = 20000;
	int numbers[arrayLength];

	hr_timer timer;
	int result;

	ifstream ifs("slucajni_brojevi.txt");
	if (!ifs)
	{
		cout << "error reading file";
		return 1;
	}

	int counter = 0;
	string tmp;
	while (getline(ifs, tmp, ' '))
		numbers[counter++] = stoi(tmp);

	while (true)
	{
		int find;
		cout << endl << "Enter number to search for: ";
		cin >> find;

		start_hr_timer(timer);
		result = find_in_array(find, numbers, arrayLength);
		stop_hr_timer(timer);

		if (result != -1)
			cout << "Found at index " << result << " in " << get_elapsed_time_microsec(timer) << " microsec" << endl;
		else
			cout << "Not found." << " " << get_elapsed_time_microsec(timer) << " microsec" << endl;
	}

	return 0;
}