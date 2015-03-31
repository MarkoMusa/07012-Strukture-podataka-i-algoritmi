/*
	Promijenite prethodni zadatak tako da umjesto izračuna
	prosjeka omogućite korisniku pretraživanje postoji li
	traženi broj u listi ili ne, dokle god to korisnik želi.
*/

#include "lista_poljem.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() 
{
	lista_poljem list;
	ifstream ifs("brojevi.txt");
	if(!ifs) 
	{
		cout << "error opening file";
		return 1;
	}

	string tmpStr;
	POSITION current = list.first();
	while (getline(ifs, tmpStr, ' '))
	{		
		list.insert(tmpStr, current);
		current = list.next(current);
	};
	ifs.close();

	ELTYPE toFind = "";
	POSITION pos = list.end();

	while(true) 
	{

		cout << "Enter a number to find (or x to exit): ";
		getline(cin, toFind);
		cin.clear();

		pos = list.find(toFind);

		if(toFind == "x")
			break;

		if(pos != list.end())
			cout << "found at position " << pos << endl;
		else
			cout << "not found" << endl;
	}

	return 0;
}