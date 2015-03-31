/* 
	Iz datoteke Co2_regije_drzave.xls izvucite podatke o
	svim državama (naziv i šifra) te za svaku državu zbrojite
	ispuštenu količinu C02 za sve godine. Ispišite nazive i
	emisije svih država.
*/

#include "Country.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;


int readCountries(string fn, vector<Country>& countries) {

	ifstream ifs(fn);
	if (!ifs)
		return 1;

	string record = "";

	while(getline(ifs, record)) {

		stringstream ss(record);				// Have one country data in a stream.

		string countryName;						// 1st item country name
		getline(ss, countryName, ';');
		
		string countryCode;						// 2nd item country code
		getline(ss, countryCode, ';');

		vector<double> co2Data;					// Rest is co2 records
		string co2Number;						// Temp to read number in
		while (getline(ss, co2Number, ';'))		// Get numbers, convert to int and push into vector
			co2Data.push_back(atoi(co2Number.c_str()));
	
		Country c(countryName, countryCode, co2Data);	// Create new Country object and put it in the vector.
		countries.push_back(c);
	}

	ifs.close();
	return 0;
}


int main() {
	vector<Country> countries;
	string fn = "Co2_emisije.csv";

	if(readCountries(fn, countries)) {
		cout << "Error reading file ";
		return 1;
	}

	for(Country c : countries)
		cout << c.printSummary() << endl;

	return 0;

}