/*
	Ubacite sve podatke iz Sifre_drzava.csv u hrpu (dr�avu a
	smatramo manjom od dr�ave b ako joj je �ifra abecedno
	ispred). Obradite sadr�aj hrpe tako da ispi�ete sve
	elemente u obliku �Naziv (�ifra)�. Kojim redoslijedom su
	dr�ave ispisane?
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