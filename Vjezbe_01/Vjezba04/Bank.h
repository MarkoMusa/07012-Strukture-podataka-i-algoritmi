#ifndef _Bank_h_
#define _Bank_h_

#include <string>

class Bank 
{
public:
	Bank (std::string name, std::string vbdi);
	std::string getName();
	std::string getVBDI();
private:
	std::string name;
	std::string vbdi;
};

#endif