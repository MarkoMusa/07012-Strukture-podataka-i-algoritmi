/*
	 Promijenite prethodni zadatak tako da lista umjesto
	statičkog polja koristi dinamičko polje. Neka kapacitet
	tog polja korisnik može zadati kroz konstruktor.
*/

#include "lista_poljem.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Country.h"

using namespace std;

void filterLower(lista_poljem& list, double val)
{
	for (POSITION i = list.first(); i < list.end(); )
	{
		Country tmp;
		list.read(i, tmp);
		if (tmp.avgAge < val) {
			list.remove(i);
			// Field shrinks if we remove so new value to test in same pos
			continue;
		}

		i = list.next(i);
	}
}

void print_list(lista_poljem& list)
{
	for (POSITION i = list.first(); i < list.end(); i = list.next(i))
	{
		Country tmp;
		list.read(i, tmp);
		cout << tmp.name << " - " << tmp.avgAge << endl;
	}
}

int main() 
{
	lista_poljem countries(300);
	ifstream ifs("Life_expectancy.csv");
	if(!ifs) 
	{
		cout << "error opening file";
		return 1;
	}

	string tmp;
	string country;
	string lifeExp;

	// Get rid of header column
	getline(ifs, tmp);

	while (getline(ifs, tmp))
	{	
		Country c;
		stringstream ss(tmp);

		getline(ss, country, ';');
		getline(ss, lifeExp, ';');

		if (lifeExp == "..")
			lifeExp = "-1";

		c.name = country;
		c.avgAge = stof(lifeExp);
		countries.insert(c,countries.end());
	};
	ifs.close();



	print_list(countries);

	float valToFilter;
	
	cout << "Enter age to filter: ";
	cin >> valToFilter;

	
	filterLower(countries, valToFilter);
	
	cout << "Ages filtered";
	system("cls");
	 

	print_list(countries);
	
	return 0;
}