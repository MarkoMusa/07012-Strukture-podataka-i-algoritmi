#include <iostream>
#include <string>
#include "prioritetni_red.h"
using namespace std;

int main() {
	prioritetni_red pred;

	for (int i = 1; i <= 100; i++) {
		pred.enqueue(i, i);
	}

	int procitano;
	while (pred.dequeue(procitano)) {
		cout << procitano << endl;
	}

	return 0;
}