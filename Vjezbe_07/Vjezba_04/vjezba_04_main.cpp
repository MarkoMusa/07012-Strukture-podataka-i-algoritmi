/*
	Promijenite sve što treba u prethodnom programu tako
	da kad primijenite INORDER algoritam, brojevi su ispisani
	padajuće. Kôd za INORDER algoritam uzmite s općenitog
	binarnog stabla.
*/

#include "bst.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


void generate_test_tree(bst& bs)
{
	bs.insert(63);
	bs.insert(70);
	bs.insert(90);
	bs.insert(92);
	bs.insert(32);
	bs.insert(27);
	bs.insert(33);
	bs.insert(30);
	bs.insert(50);
}


int main()
{
	bst bsTree;

	generate_test_tree(bsTree);

	cout << endl << " INORDER: ";
	bsTree.inorder(bsTree.root());

	cout << endl << " INORDER Reverse: ";
	bsTree.inorder_reverse(bsTree.root());

	cout << endl;

	return 0;
}