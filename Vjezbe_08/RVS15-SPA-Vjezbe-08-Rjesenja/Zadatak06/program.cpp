#include <iostream>
#include <string>
#include "prioritetni_red.h"
using namespace std;

int main() {
	prioritetni_red pred;

	int prioritet;
	for (int i = 1; i <= 100; i++) {
		if (i % 2 == 0) {
			prioritet = 200;
		}
		else {
			prioritet = 100;
		}
		pred.enqueue(i, prioritet);
	}

	int procitano;
	while (pred.dequeue(procitano)) {
		cout << procitano << endl;
	}

	return 0;
}