#ifndef _COUNTRY_H_
#define _COUNTRY_H_

#include <string>

struct ATMS {
	int year;
	double atms;
};

struct Country {

	std::string name;
	std::string acronim;
	ATMS atms[8];
};

#endif