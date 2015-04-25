#include "binarno_stablo.h"
#include "Osoba.h"

int main()
{
	binarno_stablo bs;

	POSITION parent;

	ELTYPE ana("Ana", "Anic");
	ELTYPE juro("Juro", "Juric");
	ELTYPE iva("Iva", "Ivic");
	ELTYPE fredo("Fredo", "Fredic");
	ELTYPE dino("Dino", "Dinic");
	ELTYPE ema("Ema", "Emic");

	// Root
	bs.create(ana);
	parent = bs.root();
	bs.insert_left(parent, juro);
	bs.insert_right(parent, iva);

	// Iva
	parent = bs.get_right_child(parent);
	bs.insert_left(parent, fredo);

	// Fredo
	parent = bs.get_left_child(parent);
	bs.insert_left(parent, dino);
	bs.insert_right(parent, ema);

	bs.print_tree(bs.root(), 0);

	return 0;
}