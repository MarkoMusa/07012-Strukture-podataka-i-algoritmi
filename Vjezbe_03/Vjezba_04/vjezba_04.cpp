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
#include <sstream>
#include <vector>

using namespace std;


void print_prosjek(mapa_poljem& m)
{
	double total = 0;
	int count = 0;

	for (KEY key = m.first(); key < m.last(); key = m.next())
	{
		VALUE val = m.get(key);

		
		if (val > 0) 
		{
			count++;
			total += val;
		}
	}
	cout << "Prosjecna svjetska ocekivana zivotna dob: " << total / count << endl;
}



// Went way overborad here, assignment was looking for a list of structs :)

int main() 
{
	mapa_poljem map;
	ifstream ifs("Life_expectancy.csv");
	if(!ifs) 
	{
		cout << "error opening file";
		return 1;
	}

	

	string tmp;
	string coutnry;
	string lifeExp;

	// Get rid of header column
	getline(ifs, tmp);

	while (getline(ifs, tmp))
	{		
		stringstream ss(tmp);

		getline(ss, coutnry, ';');
		getline(ss, lifeExp, ';');

		if (lifeExp == "..")
			lifeExp = "0";

		map.add(coutnry, stof(lifeExp));
	};
	ifs.close();


	print_prosjek(map);

	KEY keyToFind = "";
	while(true) 
	{

		cout << "Enter country to find (or x to exit): ";
		getline(cin, keyToFind);
		cin.clear();

		if(keyToFind == "x")
			break;

		VALUE val = map.get(keyToFind);



		if(val != map.end()) 
		{
			if (val == 0)
				cout << "Za trazenu drzavu nema dostupnih podataka o ocekivanoj zivotnoj dobi";
			else
				cout << "Ocekivana zivotna dob je:  " << val << endl;
		}
		else
		{
			cout << "Trazena drzava ne postoji u listi" << endl;
		}
	}

	cout << "COUNT " << map.size() << endl;
	
	return 0;
}