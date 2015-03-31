#ifndef _Fraction_h_
#define _Fraction_h_

#include <string>
#include <sstream>

class Fraction
{
private:
	int numerator;
	int denominator;
	
	void simplify();
public:
	Fraction();
	Fraction(int numerator, int denominator);

	void multiplyWithWholeNumber(int n);
	std::string getFraction();
};
#endif