/*
	 Promijenite prethodni zadatak tako da umjesto crtanja
	grafa omogućite korisniku da pronađe sve države koje
	započinju zadanim slovom. Proširite listu operacijom
	find_all() koja prima prvo slovo države, a zatim vrati
	vektor naziva svih država koje započinju tim slovom
*/

#include "lista_dinamicka.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Country.h"
#include <vector>

using namespace std;


// Implementation change from previous method of using Country struct to contain data.

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
		list.insert(tmp,first);
	};
	ifs.close();

	return 1;
}


vector<ELTYPE> find_all(char firstLetter, lista_dinamicka& list)
{
	vector<ELTYPE> result;
	ELTYPE element;

	// convert char to uppercase (country entries already have first letter uppercase)
	if (((int)firstLetter) > 96)
		firstLetter -= 32;


	for (POSITION j = list.first(); j != list.end(); j = list.next(j))
	{
		list.read(j, element);

		// Needs modification if country first letter does not start with uppercase.
		if ( element[0] == firstLetter)
			result.push_back(element);
	}
	return result;
}

int main() 
{
	lista_dinamicka countries;
	

	if(!read_file_into_list(countries)) 
		return 1;


	char srchStr;
	POSITION p;

	cout << "Enter search string: ";
	cin >> srchStr;

	vector<ELTYPE> results = find_all(srchStr, countries);
 
	for (ELTYPE e : results)
	{
		cout << e << endl;
	}
	return 0;
}