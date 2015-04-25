#include <string>
#include "osoba.h"
using namespace std;

osoba::osoba() {
}

osoba::osoba(string ime, string prezime) {
	this->ime = ime;
	this->prezime = prezime;
}