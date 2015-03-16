#include "Fraction.h"

Fraction::Fraction() 
{
	this->numerator = 0;
	this->denominator = 1;
}

Fraction::Fraction(int numerator, int denominator) 
{
	this->numerator = numerator;
	this->denominator = denominator;
}


void Fraction::simplify()
{
	int m = this->denominator;
	int n = this->numerator;
	int r = 1;	// Init to 1 since we are looking for 0
	// TODO: TEST CASE NO GDC
	// Algorithm stolen from Euclid
	// Given two positive integers find GCD
	while(true) 
	{
		r = m % n;					// Find remainder. Divide m by n and let r be the remainder. Gives us ( 0 <= r < n )
		if (r == 0)					// If remainder is 0, we have an answer (GCD).
		{
			// n is the GCD
			this->numerator /= n;			
			this->denominator /= n;
			break;
		}
		// Reduce
		m = n; 
		n = r;
	}

}

void Fraction::multiplyWithWholeNumber(int n)
{
	this->numerator *= n;
	simplify();
}

std::string Fraction::getFraction() {
	std::stringstream sstr;
	sstr << this->numerator;
	if(denominator != 1)
		sstr << "/" << this->denominator;
	
	return sstr.str();
}