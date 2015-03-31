/*
	Promijenite prethodni zadatak tako da na listu dodate
	novu operaciju koja vraća broj elemenata u listi.
	Demonstrirajte rad operacije.
*/

#include "lista_poljem.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() 
{
	lista_poljem list;
	ifstream ifs("brojevi.txt");
	if(!ifs) 
	{
		cout << "error opening file";
		return 1;
	}

	string tmpStr;
	POSITION current = list.first();
	while (getline(ifs, tmpStr, ' '))
	{		
		list.insert(tmpStr, current);
		current = list.next(current);
	};
	ifs.close();

	ELTYPE toFind = "";
	POSITION pos = list.end();

	cout << "COUNT " << list.size() << endl;
	
	return 0;
}