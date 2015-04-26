#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <ctime>
#include "bst.h"
using namespace std;

int main() {
	bst datumi;

	datumi.insert(datum(17, 4, 2015));
	datumi.insert(datum(22, 8, 1998));
	datumi.insert(datum(11, 5, 2002));
	datumi.insert(datum(24, 12, 2021));
	datumi.insert(datum(1, 4, 1971));
	datumi.insert(datum(4, 5, 2006));
	datumi.insert(datum(4, 12, 2016));


	ELTYPE upit;
	cout << "Upisite dan: ";
	cin >> upit.dan;
	cout << "Upisite mjesec: ";
	cin >> upit.mjesec;
	cout << "Upisite dan: ";
	cin >> upit.godina;

	if (datumi.exists(upit)) {
		cout << "Datum postoji." << endl;
	}
	else {
		cout << "Datum ne postoji." << endl;
	}

	return 0;
}