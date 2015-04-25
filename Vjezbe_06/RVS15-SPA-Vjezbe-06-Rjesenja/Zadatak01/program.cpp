#include <iostream>
#include <string>
#include "binarno_stablo.h"
using namespace std;

int main() {
	binarno_stablo tree;

	// Razina 1.
	tree.create(78);

	// Razina 2.
	POSITION korijen = tree.root();
	tree.insert_left(korijen, 1);
	tree.insert_right(korijen, 14);

	// Razina 3.
	POSITION node14 = tree.get_right_child(korijen);
	tree.insert_left(node14, 15);
	tree.insert_right(node14, 99);

	// Razina 4.
	POSITION node99 = tree.get_right_child(node14);
	tree.insert_left(node99, 3);
	tree.insert_right(node99, 4);

	// Razina 5.
	POSITION node3 = tree.get_left_child(node99);
	tree.insert_left(node3, 29);
	tree.insert_right(node3, 67);
	POSITION node4 = tree.get_right_child(node99);
	tree.insert_right(node4, 11);

	tree.print_tree();

	return 0;
}