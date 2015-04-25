/*
Zadano je sljedeće binarno stablo:
Na papir nacrtajte kako će izgledati smještaj čvorova u
polju ako koristimo implementaciju stabla poljem. Napišite
program koji koristi implementaciju stabla poljem, u njemu
ostvarite prikazano stablo te ispišite njegov sadržaj.
*/

#include "binarno_stablo.h"


int main()
{
	binarno_stablo stablo;
	POSITION p;
	POSITION c;
	// Root node: 78
	stablo.create(78);
		
	p = stablo.root();
	stablo.insert_left(p, 1);
	stablo.insert_right(p, 14);

	// Node val 14
	p = stablo.get_right_child(p);

	stablo.insert_left(p, 15);
	stablo.insert_right(p, 99);

	// Node val 99
	p = stablo.get_right_child(p);
	stablo.insert_left(p, 3);
	stablo.insert_right(p, 4);

	// Node val 3
	c = stablo.get_left_child(p);
	stablo.insert_left(c, 29);
	stablo.insert_right(c, 67);

	// 4
	p = stablo.get_right_child(p);
	stablo.insert_right(p, 11);

	stablo.print_tree();

}