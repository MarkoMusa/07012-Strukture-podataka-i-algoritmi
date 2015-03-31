/*
	Izradite listu koja može čuvati podatke o očekivanom životnom dobu u raznim državama. Na najbrži mogući
	način ubacite u listu sve podatke iz datoteke Life_expectancy.csv. Nakon toga, ispišite prosječnu
	životnu dob cijelog svijeta te omogućite korisniku pretraživanje životne dobi po nazivu države, dok god to
	želi. Za rješavanje zadataka koristite odgovarajuće priloge. Primjer rada programa:
	
	Prosjecna svjetska ocekivana zivotna dob: 70.5985 
	Upisite naziv drzave: Nepostojeca	Trazena drzava ne postoji u listi										Dalje (1 = da, 0 = ne): 1
	Upisite naziv drzave: Croatia		Ocekivana zivotna dob je: 76.9											Dalje (1 = da, 0 = ne): 1 
	Upisite naziv drzave: Greenland		Za trazenu drzavu nema dostupnih podataka o ocekivanoj zivotnoj dobi	Dalje (1 = da, 0 = ne): 0
*/

#include "mapa_poljem.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() 
{
	mapa_poljem map;
	ifstream ifs("Life_expectancy.csv");
	if(!ifs) 
	{
		cout << "error opening file";
		return 1;
	}

	string country;
	string lifeExpectancy;

	while (ifs)
	{		
		getline(ifs, country, ';');
		getline(ifs, lifeExpectancy, ';');

		map.add(country, lifeExpectancy);
	};
	ifs.close();

	KEY keyToFind = "";
	while(true) 
	{

		cout << "Enter country to find (or x to exit): ";
		getline(cin, keyToFind);
		cin.clear();

		if(toFind == "x")
			break;

		pos = list.find(toFind);



		if(pos != list.end())
			cout << "found at position " << pos << endl;
		else
			cout << "not found" << endl;
	}

	cout << "COUNT " << list.size() << endl;
	
	return 0;
}