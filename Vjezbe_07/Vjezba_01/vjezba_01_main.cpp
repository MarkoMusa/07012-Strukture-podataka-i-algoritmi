/*
	Zadano je sljedeće binarno stablo:
	Na papir napišite redoslijed obilazaka čvorova INORDER,
	POSTORDER i PREORDER algoritmima. Napišite program,
	u njemu ostvarite prikazano stablo te pozivom algoritama
	obilazaka provjerite jeste li točno odgovorili.
	o Je li ovo BST? Kako izgleda INORDER na BST-u?
*/

#include "binarno_stablo.h"
#include <iostream>

void generate_test_tree(binarno_stablo& bs)
{
	// Waste of time should have used the BST which has insert()

	// Create root
	bs.create(63);
	POSITION p, l, r;
	
	// Right side of root:
	p = bs.root();
	bs.insert_right(p, 70);
	p = bs.get_right_child(p);
	bs.insert_right(p, 90);
	p = bs.get_right_child(p);
	bs.insert_right(p, 92);

	// Left side of root
	p = bs.root();
	bs.insert_left(p,32);
	
	// p=32
	p = bs.get_left_child(p);
	bs.insert_left(p, 27);
	bs.insert_right(p, 33);

	// l = 27, r = 33
	l = bs.get_left_child(p);
	r = bs.get_right_child(p);

	bs.insert_right(l, 30);
	bs.insert_right(r, 50);
}


int main() 
{
	binarno_stablo bs;

	generate_test_tree(bs);

	cout << endl << " INORDER: ";
	bs.inorder(bs.root());
	
	cout << endl << " POSTORDER: ";
	bs.postorder(bs.root());

	cout << endl << " PREORDER: ";
	bs.preorder(bs.root());
	cout << endl;

}