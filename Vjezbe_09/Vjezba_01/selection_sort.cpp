#include <iostream>
#include "selection_sort.h"
using namespace std;

void selection_sort(int data[], int n) {
	for (int i = 0; i < n - 1; i++) {
		int min_index = i;
		for (int j = i + 1; j < n; j++) {
			if (data[j] < data[min_index]) {
				min_index = j;
			}
		}

		swap(data[min_index], data[i]);
	}
}