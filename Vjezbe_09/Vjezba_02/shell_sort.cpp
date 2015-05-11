#include <iostream>
#include "shell_sort.h"
using namespace std;

void shell_sort(int data[], int n) {
	for (int step = n / 2; step > 0; step = step / 2) {
		for (int i = step; i < n; i++) { // Kreæemo od step
			int temp = data[i];
			int j;
			for (j = i; j >= step && data[j - step] > temp; j = j - step) {
				swap(data[j], data[j - step]);
			}
		}
	}
}