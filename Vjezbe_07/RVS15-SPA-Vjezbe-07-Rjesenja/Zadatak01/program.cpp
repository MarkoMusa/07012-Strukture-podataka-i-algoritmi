#include <iostream>
#include <string>
#include <fstream>
#include "binarno_stablo.h"
using namespace std;

int main() {
	binarno_stablo tree;
	tree.create(63);

	POSITION root = tree.root();
	tree.insert_left(root, 32);
	tree.insert_right(root, 70);

	POSITION node32 = tree.get_left_child(root);
	tree.insert_left(node32, 27);
	tree.insert_right(node32, 33);

	POSITION node70 = tree.get_right_child(root);
	tree.insert_right(node70, 90);

	POSITION node27 = tree.get_left_child(node32);
	tree.insert_right(node27, 30);

	POSITION node33 = tree.get_right_child(node32);
	tree.insert_right(node33, 50);

	POSITION node90 = tree.get_right_child(node70);
	tree.insert_right(node90, 92);

	// INORDER: 27, 30, 32, 33, 50, 63, 70, 90, 92
	// PREORDER: 63, 32, 27, 30, 33, 50, 70, 90, 92
	// POSTORDER: 30, 27, 50, 33, 32, 92, 90, 70, 63

	cout << "INORDER: "; tree.inorder(tree.root()); cout << endl;
	cout << "PREORDER: "; tree.preorder(tree.root()); cout << endl;
	cout << "POSTORDER: "; tree.postorder(tree.root()); cout << endl;

	return 0;
}