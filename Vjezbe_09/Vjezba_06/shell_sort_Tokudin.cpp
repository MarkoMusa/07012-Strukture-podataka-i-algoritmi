#include <iostream>
#include "shell_sort_Tokudin.h"
using namespace std;




void shell_sort_Tokudin(int data[], int n) {
	// assume we will not have more then 100 steps, will overflow int way before that
	int steps[100];
	
	// keep track of index after loop
	int i = -1;
	// Generate steps untill we pass n
	do {
		i++;
		steps[i] = (int)((pow(9,i) - pow(4,i)) / (5*pow(4,i - 1)) ) + 1;
	} while(steps[i] < n);
	i--;


	for (int step = steps[i]; i >= 0; step = steps[i--]) {
		for (int i = step; i < n; i++) { // Kreæemo od step
			int temp = data[i];
			int j;
			for (j = i; j >= step && data[j - step] > temp; j = j - step) {
				swap(data[j], data[j - step]);
			}
		}
	}
}