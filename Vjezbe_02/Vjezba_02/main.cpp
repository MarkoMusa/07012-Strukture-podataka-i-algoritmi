/*
	2. U prilogu su dva gotova algoritma sortiranja implementirana pomoću dvije 
	funkcije: bubble_sort i quick_sort.	Pripremite si
	a. 1.000
	b. 10.000
	c. 20.000
	slučajnih brojeva između 1 i 1000. Sortirajte dobivene
	brojeve prvo pomoću quick sorta, a zatim iste brojeve
	pomoću bubble sorta. Ispišite u konzolu koliko je
	izvođenje svakog algoritma trajalo.
*/
#include <ctime>
#include <cstdlib>
#include <iostream>
#include "funkcije_za_sortiranje.h"
#include "high_res_timer.h"

void fill_with_rand(int arr[], int length, int startRange, int endRange)
{
	srand(time(nullptr));
	for (int i = 0; i < length; i++)
	{
		arr[i] = rand() % (endRange - startRange + 1) + startRange;
	}
}

void time(int length, int sortType) {
	hr_timer timer;
	int* arr = new int[length];

	fill_with_rand(arr, length, 1, 1000);


	
	switch (sortType)
	{
		case 1:
			std::cout << "Bubble sort starting; ";
			start_hr_timer(timer);
			bubble_sort(arr, length);
			stop_hr_timer(timer);
			break;
		case 2:
			std::cout << "Quick sort starting; ";
			start_hr_timer(timer);
			quick_sort(arr, length);
			stop_hr_timer(timer);
			break;
		default:
			std::cout << "Error: Unknown sort type";
	}
	
	stop_hr_timer(timer);
	std::cout << "sorted " << length << " ints in : " << get_elapsed_time_microsec(timer) / 1000 << " ms" << std::endl;

	delete[] arr;
}

int main() 
{
	int thou[1000];
	int tenThou[10000];
	int twentyThou[20000];

	// 1 bubble, 2 quick
	time(1000, 1);
	time(10000, 1);
	time(20000, 1);

	time(1000, 2);
	time(10000, 2);
	time(20000, 2);

	return 0;
}