/*
Promijenite prethodni zadatak tako da od korisnika
učitate puni naziv države, a nakon toga iscrtate graf s
brojem bankomata (svaki redak je jedna godina, svaki "#"
predstavlja do 10 bankomata). Broj bankomata u godini
jednostavno pretvorite u prvi veći cijeli broj funkcijom
ceil(). Primjer prikaza za Hrvatsku:
Upisite naziv: Croatia
Graf za: Croatia
#######
########
#########
#########
##########
###########
###########
############
*/
#include "lista_dinamicka.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Country.h"

using namespace std;


int read_file_into_list(lista_dinamicka& list)
{
	// FILE READ LOGIC (too lazy to make a function)
	ifstream ifs("Atms.csv");
	if(!ifs) 
	{
		cout << "error opening file";
		return 1;
	}

	POSITION first = list.first();
	string tmp;
	// Get header
	getline(ifs, tmp);

	while (getline(ifs, tmp))
	{	
		ELTYPE c;
		stringstream ss(tmp);

		getline(ss, c.name, ';');
		getline(ss, c.acronim, ';');
		for (int i = 0; i < 8; i++)
		{
			getline(ss,tmp,';');
			if (tmp == "..")
				tmp = "0";
			c.atms[i].year = 2005+i;
			c.atms[i].atms = stod(tmp);
		}
		list.insert(c,first);
	};
	ifs.close();

	return 1;
}


void print_graph(ELTYPE& e)
{
	cout << "Graph for " << e.name << endl;
	for (int j = 0; j < 8; j++)
	{
		int bankomati = ceil(e.atms[j].atms);

		for (int i = 0; i < bankomati; i += 10)
			cout << "#";

		cout << endl;
	}
}

int main() 
{
	lista_dinamicka countries;

	if(!read_file_into_list(countries)) 
		return 1;


	ELTYPE c;
	POSITION p;

	cout << "Enter name of country: ";
	getline(cin, c.name);

	p = countries.find(c);
	countries.read(p,c);

	print_graph(c);
 
	return 0;
}