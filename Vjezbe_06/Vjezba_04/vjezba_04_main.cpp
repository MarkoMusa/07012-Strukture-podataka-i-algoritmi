/*
 Promijenite prethodni zadatak tako da promijenite logiku
dodavanja novog čvora u stablo na sljedeći način: ako
korisnik želi dodati lijevo dijete N nekom čvoru P koji već
ima lijevo dijete L, umjesto da javite neuspjeh (kao što je
sada) napravite sljedeće: lijevo dijete čvora P sad postaje
N, a lijevo dijete čvora N sad postaje čvor L:
Isprobajte novu funkcionalnost tako da u postojeće
stablo dodate Ranka Rankića kao lijevo dijete Ive Ivić
*/

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

	// isert ivo left
	bs.insert_left(ivoPosition,ranko);

	bs.print_tree(bs.root(), 0);

	return 0;
}