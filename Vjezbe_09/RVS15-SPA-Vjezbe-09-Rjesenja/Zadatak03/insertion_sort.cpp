#include <iostream>
#include "insertion_sort.h"
using namespace std;

void insertion_sort(int data[], int n) {
	for (int i = 1; i < n; i++) { // Prvog preskaèemo.
		int temp = data[i];
		int j;
		for (j = i; j >= 1 && data[j - 1] > temp; j--) {
			swap(data[j], data[j - 1]);
		}
	}
}