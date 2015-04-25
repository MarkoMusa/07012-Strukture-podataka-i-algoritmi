#include "Osoba.h"
#include <string>

using namespace std;

Osoba::Osoba() {};

Osoba::Osoba(string first, string last) 
{
	this->first = first;
	this->last = last;
}

string Osoba::getName()
{
	return this->first + " " + this->last;
}