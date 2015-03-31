/*
	Izradite listu koja može čuvati cijele brojeve. Na najbrži
	mogući način ubacite u listu sve brojeve iz datoteke
	brojevi.txt (brojeva ima oko 10.000 i međusobno su
	odvojeni razmacima; nijedan nije veći od 20 milijuna).
	Nakon toga, ispišite prosječnu vrijednost svih brojeva iz
	liste. Za rješavanje zadataka koristite odgovarajuće
	priloge
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

	int avrg = 0;
	int count = 0;
	string temp = "";
	// get average
	for (POSITION i = list.first(); i < list.end(); i = list.next(i))
	{
		list.read(i, temp);
		avrg += stoi(temp);
		count++;
	}
	cout << "average = " << avrg/count << endl;

	return 0;
}