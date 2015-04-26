#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <ctime>
#include "bst.h"
using namespace std;

int main() {
	bst brojevi;

	ifstream dat("slucajni_brojevi.txt");
	if (!dat) {
		cout << "Greska pri otvaranju ulazne datoteke" << endl;
		return 1;
	}

	int i = 0;
	string procitano;
	stringstream sstr;
	int broj;
	while (getline(dat, procitano, ' ')) {
		sstr << procitano;
		sstr >> broj;
		brojevi.insert(broj);
		sstr.str("");
		sstr.clear();
		i++;
	}

	dat.close();

	// Ispis padajuæe.
	brojevi.inorder(brojevi.root()); cout << endl;

	return 0;
}