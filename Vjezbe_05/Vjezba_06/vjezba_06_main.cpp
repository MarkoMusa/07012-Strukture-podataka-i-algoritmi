/*
	Napišite program kojim ćete iz hygdata_v3.csv za svaku zvijezdu uzeti njen identitikator (polje id), poznati naziv
	(polje proper) te udaljenost od Sunca (polje dist), ali samo za one zvijezde koje imaju poznati naziv (one koje
	nemaju možete zanemariti). Sve zvijezde stavite u red. Nakon toga, pitajte korisnika da upiše udaljenost d te
	kreirajte dvije datoteke i u njih dodajte zvijezde iz reda – u jednu one koje su udaljenije od d, u drugu ostale
*/

#include "red_dinamicki.h"
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>



int parse_names(string fn, red_dinamicki& list)
{
	ifstream ifs(fn);
	if (!ifs)
	{
		cout << "Error reading " << fn << endl;
		return 1;

	}

	string tmp;
	getline(ifs, tmp); // Header row
	while (getline(ifs, tmp))
	{
		stringstream row(tmp);

		int id;
		string name;
		string tmp;
		double dist;

		row >> id;
		getline(row, tmp, ',');			// Get rid of comma after id
		for (int i = 0; i < 6; i++) 
			getline(row, name, ',');	// Last hit should be correct name

		if (name == "")
			continue;

		for (int i = 0; i < 2; i++)		// Burn 2 more entries before distance
			getline(row, tmp, ',');
		
		row >> dist;
		
		ELTYPE s;
		s.id = id;
		s.name = name;
		s.dist = dist;
		list.enqueue(s);
	}
	ifs.close();
	return 0;
}

int filter_and_write_names(red_dinamicki& names, double d)
{
	ofstream smaller("smaller.txt");
	if (!smaller)
	{
		cout << "Error writing smaller.txt" << endl;
		return 1;
	}
	ofstream larger("larger.txt");
	if (!smaller)
	{
		cout << "Error writing larger.txt" << endl;
		return 1;
	}
	
	ELTYPE name;
	while (!names.is_empty())
	{
		ELTYPE s;
		names.dequeue(s);

		if (s.dist >= d)
			larger << s.id << ", " << s.name << ", " << s.dist << endl;
		else 
			smaller << s.id << ", " << s.name << ", " << s.dist << endl;
	}

	smaller.close();
	larger.close();
	return 0;
}

int main() 
{
	// Red_poljem = stack overflow
	red_dinamicki names;

	int readResult = parse_names("hygdata_v3.csv", names);
	if (readResult) {
		return 1;
	}

	double distance;
	cout << "Distance? ";
	cin >> distance;

	return filter_and_write_names(names, distance);
}