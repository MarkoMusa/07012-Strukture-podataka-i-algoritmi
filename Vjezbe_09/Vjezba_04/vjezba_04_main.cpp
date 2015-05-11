/*
	Promijenite selection sort tako da sortira pravokutnike
	(širina, visina) prema površini. Učitajte svih 1000
	pravokutnika iz pravokutnici.txt (u svakom retku su širina
	i visina jednog pravokutnika odvojeni razmakom) i
	prepišite ih u drugu datoteku, ali sortirano.
*/
#include "selection_sort.h"
#include "Pravokutnik.h"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

int get_data(Pravokutnik* ps) {

	int i = 0;
	stringstream buffer;

	ifstream ifs("pravokutnici.txt");
	if (!ifs)
	{
		cout << "error opening file";
		return 1;
	}

	
	buffer << ifs.rdbuf();

	while(buffer >> ps[i].sirina) {
		buffer >> ps[i].visina;
		ps[i].povrsina = ps[i].visina * ps[i].sirina;
		i++;
	}
	ifs.close();
	return 0;
}

int save(Pravokutnik* ps, int size) {
	ofstream ofs("sorted.txt");
	if (!ofs)
	{
		cout << "error opening file for write";
		return 1;
	}
	for (int i = 0; i < size; i++)
		ofs << i << ": " << ps[i].sirina << ", " << ps[i].visina <<"  (" << ps[i].povrsina << ")"<< endl;
	ofs.close();
	return 0;
}

int main() {
	int size = 1000;
	Pravokutnik* ps = new Pravokutnik[1000];
	
	if(get_data(ps) == 1)
		return 1;


	selection_sort(ps, size);
	return save(ps, size);
}