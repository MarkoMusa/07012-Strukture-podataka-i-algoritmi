#ifndef _Country_h_
#define _Country_h_

#include <vector>
#include <string>

class Country 
{
public:
	Country ();
	Country (std::string name, std::string code, std::vector<double> co2Numbers);
	double sumEmissions();
	std::string printSummary();

private:
	std::string countryName;
	std::string countryCode;
	std::vector<double> co2numbers;
	double totalEmissions;
};
#endif