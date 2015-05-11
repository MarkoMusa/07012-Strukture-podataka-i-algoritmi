/*
	Promijenite prethodni zadatak tako da koristite prvih
20.000 brojeva iz datoteke puno_brojeva3.txt (brojevi su
sad sortirani padajuće – najgori mogući slučaj).
*/


#include <fstream>
#include <iostream>
#include <sstream>
#include "high_res_timer.h"
#include "bubble_sort.h"
#include "insertion_sort.h"
#include "merge_sort.h"
#include "selection_sort.h"
#include "shell_sort.h"


using namespace std;

/// Fill numbers into array
// Bad code assumes input file is just right for array elements
// should pass size and read that many in a for loop
int get_numbers(int* numbers) {

	int tmp, count = 0;

	ifstream ifs("puno_brojeva3.txt");
	if (!ifs)
	{
		cout << "error opening file";
		return 1;
	}

	std::stringstream buffer;
	buffer << ifs.rdbuf();


	while(buffer >> tmp && count < 20000)
		numbers[count++] = tmp;

	return 0;
}

int main() {

	hr_timer timer;
	int size = 20000;
	int* numbers = new int[size];
	int* numbersCopy = new int[size];
	
	if(get_numbers(numbers) == 1)
		return 1;

	// BUBBLE
	memcpy(numbersCopy, numbers , size*sizeof(int));
	start_hr_timer(timer);
	bubble_sort(numbersCopy, size);
	stop_hr_timer(timer);
	cout << "Bubble sort in " << get_elapsed_time_microsec(timer) << endl;

	// INSERTION
	memcpy(numbersCopy, numbers , size*sizeof(int));
	start_hr_timer(timer);
	insertion_sort(numbersCopy, size);
	stop_hr_timer(timer);
	cout << "Insertion sort in " << get_elapsed_time_microsec(timer) << endl;

	// MERGE
	memcpy(numbersCopy, numbers , size*sizeof(int));
	start_hr_timer(timer);
	merge_sort(numbersCopy, size);
	stop_hr_timer(timer);
	cout << "Merge sort in " << get_elapsed_time_microsec(timer) << endl;


	// SHELL
	memcpy(numbersCopy, numbers , size*sizeof(int));
	start_hr_timer(timer);
	shell_sort(numbersCopy, size);
	stop_hr_timer(timer);
	cout << "Shell sort in " << get_elapsed_time_microsec(timer) << endl;

	// SELECTION
	memcpy(numbersCopy, numbers , size*sizeof(int));
	start_hr_timer(timer);
	selection_sort(numbersCopy, size);
	stop_hr_timer(timer);
	cout << "Selection sort in " << get_elapsed_time_microsec(timer) << endl;

	delete[] numbers;
	delete[] numbersCopy;
	return 0;
}