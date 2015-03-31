/*
	Definirajte tip podataka za čuvanje podataka o
	studentima. Za svakog studenta čuvajte ime, prezime te
	godinu rođenja. Kreirajte polje od tri studenta; imena i
	prezimena učitajte od korisnika, a za vrijednost godine
	rođenja stavite slučajnu vrijednost između 1961. i 1997.
*/
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>

struct Student 
{
	std::string f_name;
	std::string l_name;
	int year_of_birth;
};


int main() 
{
	srand(time(nullptr));

	Student s[3];

	for (int i = 0; i < 3; i++)
	{
		std::cout << "Enter student first name: ";
		std::getline(std::cin, s[i].f_name);

		std::cout << "Enter student lastname name: ";
		std::getline(std::cin, s[i].l_name);

		s[i].year_of_birth = rand() % (1997 - 1961 + 1) + 1961;
	}



}