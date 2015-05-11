#include <iostream>
#include "insertion_sort.h"
#include "Banka.h"

using namespace std;

void insertion_sort(Banka data[], int n) {
	for (int i = 1; i < n; i++) { // Prvog preskaèemo.
		Banka temp = data[i];
		int j;
		for (j = i; j >= 1 && data[j - 1].ime[0] > temp.ime[0]; j--) {
			swap(data[j], data[j - 1]);
		}
	}
}