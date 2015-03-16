/*
	Definirajte tip podataka za čuvanje podataka o razlomku,
	te na njemu definirajte metode množenja sa cijelim
	brojem te vraćanja tekstualnog prikaza razlomka u
	formatu “brojnik/nazivnik”. Učitavajte od korisnika
	razlomke i skalare dok to želi i ispisujte razlomak prije i
	poslije množenja sa skalarom. Primjer rada programa:
	Upisite brojnik: 4
	Upisite nazivnik: 2
	Upisite skalar: 7
	4/2 * 7 = 28/2
	Dalje (1/0): 0
*/
#include <iostream>
#include <sstream>
#include "Fraction.h"
#include "Fraction.h"
#include <string>

using namespace std;

Fraction getFraction() 
{	
	int num = 0;
	int den = 0;

	cout << "Enter numerator: ";
	cin >> num;

	cout << "Enter denominator: ";
	cin >> den;

	Fraction f(num, den);

	return f;
}


int main() 
{
	char cont = 'y';
	int n = 0;

	while(true) {
		
		cout << "Continue? (y/n): ";
		cin >> cont;
		cin.clear();
		cin.ignore();

		if (cont == 'n')
			break;

		stringstream ss;

		Fraction f = getFraction();

		cout << "Scalar to multiply by: ";
		cin >> n;

		ss << f.getFraction() << " * " << n << " = ";
		f.multiplyWithWholeNumber(n);
		ss << f.getFraction();
		cout << ss.str() << endl;
	}

	return 0;
}