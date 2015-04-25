/*
	Naš čvor ne zna ništa o svom roditelju, tj. za bilo koji čvor
	možemo pronaći djecu, ali ne možemo pronaći roditelja.
	Promijenite prethodni zadatak tako da promijenite
	definiciju čvora stabla na način da uz lijevo i desno dijete
	sadrži i pokazivač na roditelja. Nakon toga, promijenite i
	implementaciju gdje je potrebno (hint: na tri mjesta, iza
	poziva metode create_new_node). Na kraju, koristeći
	podatke o roditelju ispišite dubinu zadnjeg dodanog
	čvora
*/

#include "binarno_stablo.h"
#include <iostream>

using namespace std;


//TODO: randomize generation
int main() 
{
	binarno_stablo bs;
	int depth = 6;
	int counter = 0;

	bs.create(0);
	POSITION p = bs.root();

	for (int i = 1; i < depth; i++)
	{
		bs.insert_left(p, i);
		p = bs.get_left_child(p);
	}

	while(p != nullptr)
	{
		counter++;
		p = bs.get_parent(p);
	}

	bs.print_tree(bs.root(),counter);
	cout << "Dubina " << counter << endl;

	return 0;
}