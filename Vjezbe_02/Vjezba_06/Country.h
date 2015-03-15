#ifndef _Country_h_
#define _Country_h_
#include <string>
#include <map>

class Country 
{
public:
	Country ();
	Country (std::string name);
	~Country ();

	int getData(int year);
	std::map<int,int> getData();

	void addYear(int year);
	void addYear(int year, int dataForYear);
	void setDataForYear(int year, int dataForYear);
	std::string str();
private:
	std::string name;
	std::map<int,int> data;
};

#endif // _Country_h_