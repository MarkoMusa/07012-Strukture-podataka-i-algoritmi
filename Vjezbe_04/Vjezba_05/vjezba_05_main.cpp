/*
	Izradite listu koja može čuvati puni i kratki naziv države.
	Ubacite u listu sve države iz datoteke Atms.csv (broj
	bankomata na 100.000 odraslih stanovnika) tako da
	svaku državu dodajete na početak liste (odaberite
	optimalnu implementaciju liste). Nakon toga, učitajte od
	korisnika neko slovo i ispišite sve države čiji puni naziv
	započinje tim slovom. Za rješavanje zadataka koristite
	odgovarajuće priloge. Hint: funkcija toupper().
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

	string tmp;
	string country;
	string acronim;

	// Get rid of header column
	getline(ifs, tmp);

	while (getline(ifs, tmp))
	{	
		Country c;
		stringstream ss(tmp);

		getline(ss, country, ';');
		getline(ss, acronim, ';');
		// dont care about ATMS

		c.name = country;
		c.acronim = acronim;
		list.insert(c,list.first());
	};
	ifs.close();
	// END FILE READ LOGIC
	return 1;
}


int main() 
{
	lista_dinamicka countries;

	if(!read_file_into_list(countries)) 
		return 1;

	char firstLetter;
	
	cout << "Enter first letter of country: ";
	cin >> firstLetter;
	cin.ignore();
	cin.clear();

	Country c;
	for (POSITION i = countries.first(); i != countries.end(); i = countries.next(i))
	{
		countries.read(i,c);
		if (toupper(c.name[0]) == toupper(firstLetter))
		{
			cout << c.name << " (" << c.acronim << ")" << endl;
		}
	}
	 
	return 0;
}