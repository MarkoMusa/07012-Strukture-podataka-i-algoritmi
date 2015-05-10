/*
Promijenite prethodni zadatak tako da hrpa bude min-
heap umjesto max-heap. Kojim redoslijedom su države
ispisane?

A to Z, char A value = 64 and Z = 90, so when compared Z > A
Slova idu poredu tako da A je minimum i na vrhu heap, 
kad se elementi skidaju ide se s vrha.

*/



#include <iostream>
#include <fstream>
#include "heap.h"
#include <string>
#include <vector>

int main() {
	ifstream ifs("Sifre_drzava.csv");
	if (!ifs)
	{
		cout << "error reading file";
		return 1;
	}

	heap h;
	string tmp;

	// Skip column titles
	getline(ifs,tmp); 
	while (getline(ifs,tmp)) {
		ELTYPE e;
		int splitAt = tmp.find(';');
		e.ime = tmp.substr(0, splitAt);
		e.sifra = tmp.substr(splitAt+1, tmp.length());
		h.insert(e);
	}
	
	ELTYPE e;
	while (!h.is_empty())
	{
		e = h.remove();
		cout << e.ime << " (" << e.sifra << ")" << endl;
	}
}