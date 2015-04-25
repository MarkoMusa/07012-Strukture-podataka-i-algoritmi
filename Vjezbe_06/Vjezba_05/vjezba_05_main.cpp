/*
	Promijenite prethodni zadatak tako da na stablo dodate
	novu operaciju remove_children. Neka operacija primi
	poziciju čvora i neka na ispravan način ukloni onu djecu
	zadanog čvora koji su listovi; onu djecu koja nisu listovi
	nemojte uklanjati. Metoda uvijek uspijeva. Demonstrirajte
	rad operacije na Ani Anić.
*/
#include <iostream>
#include "binarno_stablo.h"
#include "Osoba.h"

int main()
{
	binarno_stablo bs;

	POSITION parent;
	POSITION ivoPosition;

	ELTYPE ana("Ana", "Anic");
	ELTYPE juro("Juro", "Juric");
	ELTYPE ivo("Ivo", "Ivic");
	ELTYPE fredo("Fredo", "Fredic");
	ELTYPE dino("Dino", "Dinic");
	ELTYPE ema("Ema", "Emic");
	ELTYPE ranko("Ranko", "Rankic");

	// Root
	bs.create(ana);
	parent = bs.root();
	bs.insert_left(parent, juro);
	bs.insert_right(parent, ivo);

	// Ivo
	parent = bs.get_right_child(parent);
	ivoPosition = parent;
	bs.insert_left(parent, fredo);

	// Fredo
	parent = bs.get_left_child(parent);
	bs.insert_left(parent, dino);
	bs.insert_right(parent, ema);

	bs.print_tree(bs.root(), 0);

	cout << endl << "---- Iserting Ranko mid node at Ivo Ivic ----" << endl;
	// isert ivo left
	bs.insert_left(ivoPosition,ranko);

	bs.print_tree(bs.root(), 0);

	cout << endl << "---- removing children of Ana ----" << endl;
	bs.remove_children(bs.root());
	bs.print_tree(bs.root(), 0);

	return 0;
}