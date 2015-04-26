/*
	Napišite program koji će u BST-u moći čuvati datume:
		17.4.2015, 22.8.1998, 11.5.2002, 24.12.2021, 1.4.1971, 4.5.2006, 4.12.2016.
	
	Omogućite korisniku da upiše datum, a vi mu ispišite postoji li ili ne. 

	Hint: usporedba dva datuma je najlakša ako ih oba pretvorimo u cijeli broj formulom:
		int datum_kao_broj = dan + mjesec*100 + godina*10000;

*/

#include <iostream>
#include <string>
#include "bst.h"
#include <sstream>

using namespace std;

int convert_date_to_int(const string d)
{
	stringstream ss(d);
	string tmp;

	getline(ss, tmp, '.');
	int date = stoi(tmp);

	getline(ss, tmp, '.');
	int month = stoi(tmp);

	int year = 0;
	ss >> year;

	return date + month*100 + year*10000;
}

string convert_int_to_date(const int d)
{
	string tmp;
	// stuff & math
	return tmp;
}

void preload(bst& tree)
{
	string dates[] = { "17.4.2015", "22.8.1998", "11.5.2002", "24.12.2021", "1.4.1971", "4.5.2006","4.12.2016" };
	for (int i = 0; i < 7; i++)
		tree.insert(convert_date_to_int(dates[i]));
}

int main()
{
	bst tree;

	preload(tree);

	while (true)
	{
		string date;
		cout << "Enter date to find (dd.m.yyyy): ";
		getline(cin, date);
		if (tree.exists(convert_date_to_int(date)))
		{
			cout << "Found" << endl;
		} else {
			cout << "not Found"  << endl;
		}
	}

	return 0;
}