/*
	Napišite program koji iz hygdata_v3.csv  (astronexus.com/hyg)
	uzima imena svih zvijezda koje imaju poznato ime (polje
	proper), stavlja ih u red te ih upisuje u novu datoteku,
	svaku zvijezdu u novi red. Program će uvijek raditi samo s
	tom datotekom pa ga optimizirajte koliko god je moguće.
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
		ELTYPE name;
		for (int i = 0; i < 7; i++)		// Name is 7th entry
		{
			getline(row, name, ',');	// Last read will leave correct value in name
		}
		if(name != "")
			list.enqueue(name);
	}
	ifs.close();
	return 0;
}

int write_names(string fn, red_dinamicki& names)
{
	ofstream ofs(fn);
	if (!ofs)
	{
		cout << "Error writing " << fn << endl;
		return 1;
	}

	ELTYPE name;
	while (!names.is_empty())
	{
		names.dequeue(name);
		ofs << name << endl;
	}

	ofs.close();
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

	return write_names("proper_names.txt", names);
}