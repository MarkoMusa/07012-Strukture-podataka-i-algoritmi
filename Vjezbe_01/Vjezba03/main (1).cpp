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


void readCountries(string fn, vector<Country>& countries) throw(string) {

	ifstream ifs(fn);
	if (!ifs)
		throw "Some error opening file.";

	string record = "";

	while(getline(ifs, record)) {

		
		stringstream ss(record);				// Have one country data in a stream.

		string countryName;						// 1st item country name
		getline(ss, countryName, ';');
		
		string countryCode;						// 2nd item country code
		getline(ss, countryCode, ';');

		vector<int> co2Data;					// Rest is co2 records
		string co2Number;							// Temp to read number in
		while (getline(ss, co2Number, ';'))		// Get one number as string
		{

			co2Data.push_back(data)K
		}
	
	}

	ifs.close();

}


int main() {
	vector<Country> countries;
	string fn = "Co2_emisije.csv";

	try	{
		readCountries(fn, countries);
	} catch (string e) {
		cout << "An exception occurred. Exception Nr. " << e << '\n';
		return 1;
	}

	return 0;

}