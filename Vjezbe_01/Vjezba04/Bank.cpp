#include "Bank.h";

Bank::Bank (std::string name, std::string vbdi)
{
	this->name = name;
	this->vbdi = vbdi;
}

std::string Bank::getName() { return name; }
std::string Bank::getVBDI() { return vbdi; }