/*
	Promijenite prethodni program tako da umjesto polja
	koristite BST. Je li pretraživanje brže ili sporije? Puno ili
	malo? Obrazložite odgovor.
*/

#include "bst.h"
#include <iostream>
#include <fstream>
#include <string>
#include "high_res_timer.h"


using namespace std;


int find_in_array(int& n, int array[], int arrayLength)
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
	bst bsTree;
	hr_timer arrayTimer;
	hr_timer bstTimer;
	int resultArray;
	bool resultBSTree;
	int counter = 0;
	int number = 0; 
	
	ifstream ifs("slucajni_brojevi.txt");
	if (!ifs)
	{
		cout << "error reading file";
		return 1;
	}

	// Fill array and BST
	string tmp;
	while (getline(ifs, tmp, ' ')) {
		number = stoi(tmp);
		bsTree.insert(number);
		numbers[counter++] = number;
	}

	while (true)
	{
		int find;
		cout << endl << "Enter number to search for: ";
		cin >> find;

		start_hr_timer(arrayTimer);
		resultArray = find_in_array(find, numbers, arrayLength);
		stop_hr_timer(arrayTimer);

		start_hr_timer(bstTimer);
		resultBSTree = bsTree.exists(find);
		stop_hr_timer(bstTimer);

		// If found in array should exist in both
		if (resultArray != -1) {
			cout << "Array " << get_elapsed_time_microsec(arrayTimer) << " microsec" << " (@index " << resultArray << ")" << endl;
			cout << "bsTree " << get_elapsed_time_microsec(bstTimer) << " microsec" << endl;
		} else {
			cout << "Array not found in " << get_elapsed_time_microsec(arrayTimer) << " microsec" << endl;
			cout << "bsTree not found in " << get_elapsed_time_microsec(bstTimer) << " microsec" << endl;
		}
	}

	return 0;
}