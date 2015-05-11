#include <iostream>
#include <vector>
#include "shell_sort.h"
using namespace std;

void shell_sort(int data[], int n) {
	// Prvo generiramo sekvencu.
	vector<int> sequence;
	int h;
	int k = 1;
	while (true) {
		h = ceil((pow(9, k) - pow(4, k)) / (5 * pow(4, k - 1)));
		if (h < n) {
			sequence.push_back(h);
			k++;
		}
		else {
			break;
		}
	}

	// Sad koristimo elemente sekvence.
	for (int j = sequence.size() - 1; j >= 0; j--) {
		int step = sequence[j];
		for (int i = step; i < n; i++) { // Kreæemo od step
			int temp = data[i];
			int j;
			for (j = i; j >= step && data[j - step] > temp; j = j - step) {
				swap(data[j], data[j - step]);
			}
		}
	}
}