/*
		Napravite tip podataka koji će omogućavati čuvanje
	podataka o nazivu države te više podataka o broju
	znanstvenika na milijun stanovnika. Definirajte i operaciju
	koja vraća prosječni broj znanstvenika na milijun
	stanovnika za sve unesene godine. Iz datoteke
	Broj_znanstvenika_na_milijun_stanovnika.csv učitajte
	sve podatke u polje, te nakon toga ispišite prosjeke broja
	znanstvenika na milijun stanovnika za sve unesene države
	(ignorirajte godine u kojima nema upisanog broja)
*/
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Country.h"
#include <sstream>

int readCountryDataFromFile(std::vector<Country>& countries) {
	std::string inputFileName = "Broj_znanstvenika_na_milijun_stanovnika.csv";
	std::ifstream ifs(inputFileName);
	if(!ifs) 
	{
		std::cout << "Error opening input file";
		return 1;
	}
	
	std::vector<int> yearList;
	std::string tmp = "";

	// Process header with year list
	std::getline(ifs, tmp);
	std::stringstream ss(tmp);		
	getline(ss, tmp, ';');				// get rid of "Country" label
	while (getline(ss, tmp, ';'))		// Loop through years and add to vector for later use
		yearList.push_back(stoi(tmp));

	// Process individual country data
	while(std::getline(ifs, tmp))
	{
		std::string countryName = "";
		std::stringstream ss(tmp);
		getline(ss, countryName, ';');

		Country c(countryName);
		// We only want years that are defined in header, also can get year from yearList via index
		for (unsigned int i = 0; i < yearList.size(); i++)
		{
			getline(ss, tmp, ';');
			if(tmp == "")
				continue;

			std::stringstream year(tmp);
			int num = 0;
			year >> num;
			c.addYear(yearList[i], num);
		}
		countries.push_back(c);
	}
	return 0;
}


int  main() 
{
	std::vector<Country> countries;
	readCountryDataFromFile(countries);
	
	for (Country c : countries)
		std::cout << c.str() << std::endl;

	return 0;
}