/*
	Ubacite sve podatke iz Sifre_drzava.csv u hrpu (državu a
	smatramo manjom od države b ako joj je šifra abecedno
	ispred). Obradite sadržaj hrpe tako da ispišete sve
	elemente u obliku „Naziv (šifra)”. Kojim redoslijedom su
	države ispisane?
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