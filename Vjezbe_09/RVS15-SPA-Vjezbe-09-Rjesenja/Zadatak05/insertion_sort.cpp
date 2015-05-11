#include <iostream>
#include "insertion_sort.h"
using namespace std;

void insertion_sort(banka data[], int n) {
	for (int i = 1; i < n; i++) { // Prvog preskaèemo.
		banka temp = data[i];
		int j;
		for (j = i; j >= 1 && data[j - 1].naziv < temp.naziv; j--) {
			swap(data[j], data[j - 1]);
		}
	}
}