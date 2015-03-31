#include "Country.h"
#include <sstream>

Country ::Country () { name = ""; }
Country ::Country (std::string name) { this->name = name; }
Country ::~Country () {}

std::map<int,int> Country ::getData() { return data; }

int Country ::getData(int year)
{
	if(data[year])
		return data[year];
	return 0;
}

std::string Country ::str() 
{
	std::stringstream ss;
	ss << name;
	ss << " [";

	if(data.size() > 0)
	{
		for(std::map<int, int>::iterator iterator = data.begin(); iterator != data.end(); iterator++) 
		{
			if (iterator->second == 0)
				continue;
			ss << " ";
			ss << iterator->first;
			ss << ":";
			ss << iterator->second;
			ss << ";";
		}
	} 
	else 
	{
		ss << " no data";
	}
	ss << " ]";
	return ss.str();
}

void Country ::addYear(int year) { addYear(year, 0); }
void Country ::addYear(int year, int dataForYear) { data[year] = dataForYear; }
