#ifndef _OSOBA_H_
#define _OSOBA_H_

#include <string>

using namespace std;

class Osoba
{
private:
	string first;
	string last;
public:
	Osoba();
	Osoba(string first, string last);
	string getName();
};

#endif