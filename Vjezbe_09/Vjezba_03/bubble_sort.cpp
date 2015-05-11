#include <iostream>
#include "bubble_sort.h"
using namespace std;

void bubble_sort(int data[], int n) {
	bool sortirano;
	for (int i = 0; i < n - 1; i++) {
		sortirano = true;
		for (int j = 0; j < n - 1 - i; j++) { // Jer je ostatak liste sortiran.
			if (data[j] > data[j + 1]) {
				swap(data[j], data[j + 1]);
				sortirano = false;
			}
		}

		if (sortirano) {
			break;
		}
	}
}