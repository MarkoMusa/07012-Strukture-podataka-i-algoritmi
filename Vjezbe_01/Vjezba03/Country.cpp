#include "Country.h";
<<<<<<< HEAD

Country ::Country ()
{
	countryCode = nullptr;
	countryCode = nullptr;
}

Country ::~Country ()
{
=======
#include <string>
#include <sstream>

Country ::Country ()
{
	countryName = nullptr;
	countryCode = nullptr;
}

Country ::Country (std::string countryName, std::string countryCode, std::vector<double> co2numbers )
{
	this->countryName = countryName;
	this->countryCode = countryCode;
	this->co2numbers = co2numbers;
	this->totalEmissions = sumEmissions();
}


double Country::sumEmissions()
{
	double result = 0;
	for (double i : co2numbers)
		result += i;

	return result;
}

std::string Country::printSummary() {
	std::stringstream ss;
	ss.precision(2);
	ss << countryName << " (" << countryCode << "); total emissions: " << std::fixed << totalEmissions;
	return ss.str();
>>>>>>> origin/master
}