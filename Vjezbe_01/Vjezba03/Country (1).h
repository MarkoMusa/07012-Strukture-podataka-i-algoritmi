#ifndef _Country_h_
#define _Country_h_

#include <vector>
#include <string>

class Country 
{
public:
	Country ();
	~Country ();

private:
	std::vector<int> emissions;
	std::string countryCode;
	std::string countryName;
};
#endif