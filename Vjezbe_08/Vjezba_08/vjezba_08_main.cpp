/*
	 Učitajte popis dokumenata za printanje iz datoteke
	za_printanje.txt u prioritetni red. Svaki dokument je
	opisan nazivom, brojem stranica i prioritetom (već broj je
	veći prioritet). Obradite (ispišite) sve dokumente u formi:
	„printam dokument naziv, broj stranica: broj”.
*/


#include <iostream>
#include "prioritetni_red.h"
#include <fstream>

using namespace std;


int fill_red(prioritetni_red& r) {
	ifstream ifs("za_printanje.txt");
	if (!ifs)
	{
		cout << "error reading file";
		return 1;
	}

	string tmp;

	while (getline(ifs,tmp)) {
		ELTYPE e;
		int firstSplit = tmp.find(';');
		int secSplit = tmp.find_last_of(';');
		e.naziv = tmp.substr(0, firstSplit);
		e.stranica = stoi(tmp.substr(firstSplit+1, secSplit));
		e.prioritet = stoi(tmp.substr(secSplit+1, tmp.length()));
		r.enqueue(e, e.prioritet);
	}
	return 0;
}


void print_docs(prioritetni_red& r) {
	while (!r.is_empty())
	{
		ELTYPE e;
		r.dequeue(e);
		cout << "---------------------------------" << endl;
		cout << "printam dokument " << e.naziv  << ", ";
		cout << "broj stranica: " << e.stranica << "  p(" << e.prioritet << ")" << endl;
	}
}

int main() {
	prioritetni_red r;
	fill_red(r);
	print_docs(r);
}