/*
	Definirajte tip podataka za èuvanje širina i visina
	pravokutnika. U mainu kreirajte statièko polje od 5
	pravokutnika, kroz funkciju uèitajte vrijednosti od
	korisnika, te njihove površine pomoæu funkcije ispišite u
	tekstualnu datoteku. Format ispisa treba biti (svaki
	pravokutnik u svoj redak):
	P(širina, visina) = površina
	Otvaranje i zatvaranje datoteke radite u main-u.
*/
#include "rectangle.h"
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;


void fill_rectangle_array(Rectangle rectangles[], int length)
{
	for (int i = 0; i < length; i++)
	{
		int width = 0;
		int height = 0;

		cout << "Enter rectangle " << i << " width: ";
		cin >> width;

		cout << "Enter rectangle " << i << " hight: ";
		cin >> height;

		rectangles[i].set(width, height);
	}
}


int main() 
{
	int recSize = 5;
	Rectangle rec[5];
	fill_rectangle_array(rec, recSize);

	ofstream ofs("output.txt");
	if (!ofs)
	{
		cout << "Error opening file for write";
		return 1;
	}

	for (int i = 0; i < recSize; i++)
		ofs << "Rectangle(" << rec[i].getWidth() << ", " << rec[i].getHeight() << ") = " << rec[i].getArea() << endl;

	ofs.close();
	return 0;
}