/*
		Promijenite prethodni zadatak tako da uz svaku državu u
	polju čuvate i broj bankomata za svaku godinu (ako nema
	podataka, za tu godinu upišite 0). Nakon toga u datoteku
	ispišite sve države i uz svaku državu ispišite broj
	bankomata za svaku godinu.
*/
#include "lista_dinamicka.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Country.h"

using namespace std;


int read_file_into_list(lista_dinamicka& list)
{
	// FILE READ LOGIC (too lazy to make a function)
	ifstream ifs("Atms.csv");
	if(!ifs) 
	{
		cout << "error opening file";
		return 1;
	}

	POSITION first = list.first();
	string tmp;
	// Get header
	getline(ifs, tmp);

	while (getline(ifs, tmp))
	{	
		ELTYPE c;
		stringstream ss(tmp);

		getline(ss, c.name, ';');
		getline(ss, c.acronim, ';');
		for (int i = 0; i < 8; i++)
		{
			getline(ss,tmp,';');
			if (tmp == "..")
				tmp = "0";
			c.atms[i].year = 2005+i;
			c.atms[i].atms = stod(tmp);
		}
		list.insert(c,first);
	};
	ifs.close();

	return 1;
}


int main() 
{
	lista_dinamicka countries;

	if(!read_file_into_list(countries)) 
		return 1;


	ELTYPE c;
	for (POSITION i = countries.first(); i != countries.end(); i = countries.next(i))
	{
		countries.read(i, c);
		cout << c.name << " (" << c.acronim << ")" << endl;
		for (int j = 0; j < 8; j++)
		{
			cout << "\t" << c.atms[j].year << ": " << c.atms[j].atms << endl;
		}
	}
	 
	return 0;
}