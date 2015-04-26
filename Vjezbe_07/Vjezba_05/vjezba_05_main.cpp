/*
	Napišite program koji će u BST-u moći čuvati nazive i šifre
	država te iz Sifre_drzava.csv ubacite sve podatke.
	Omogućite korisniku da upiše šifru države, a vi mu ispišite
	postoji li tražena država ili ne.
*/

#include "bst.h"
#include <iostream>
#include <fstream>
#include <string>
#include "Drzava.h"


using namespace std;



int main()
{
	bst bsTree;
	
	ifstream ifs("Drzave.csv");
	if (!ifs)
	{
		cout << "error reading file";
		return 1;
	}

	// Fill array and BST
	string tmp;

	getline(ifs, tmp); // Get rid of header
	while (getline(ifs,tmp, ';')) {

		Drzava d;
		d.ime = tmp;
		
		getline(ifs,tmp);
		d.kratica = tmp;
		bsTree.insert(d);
	}

	while (true)
	{
		string find;
		cout << endl << "Enter country code to search for: ";
		getline(cin,find);

		Drzava d;
		d.kratica = find;

		bsTree.exists(d);

		// If found in array should exist in both
		if (bsTree.exists(d)) {
			cout << "found it" << endl;
		} else {
			cout << " not found " << endl;
		}
	}

	return 0;
}