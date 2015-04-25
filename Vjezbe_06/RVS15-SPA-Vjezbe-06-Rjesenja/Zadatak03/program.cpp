#include <iostream>
#include <string>
#include "binarno_stablo.h"
using namespace std;

int main() {
	binarno_stablo tree;

	osoba ana("Ana", "Anic");
	osoba juro("Juro", "Juric");
	osoba iva("Iva", "Ivic");
	osoba ferdo("Ferdo", "Ferdic");
	osoba dino("Dino", "Dinic");
	osoba ema("Ema", "Emic");

	// Razina 1.
	tree.create(ana);

	// Razina 2.
	POSITION korijen = tree.root();
	tree.insert_left(korijen, juro);
	tree.insert_right(korijen, iva);

	// Razina 3.
	POSITION node_iva = tree.get_right_child(korijen);
	tree.insert_left(node_iva, ferdo);

	// Razina 4.
	POSITION node_ferdo = tree.get_left_child(node_iva);
	tree.insert_left(node_ferdo, dino);
	tree.insert_right(node_ferdo, ema);

	tree.print_tree(tree.root(), 0);

	// Zadnje dodani èvor.
	int n = 0;
	POSITION temp = tree.get_right_child(node_ferdo);
	while (temp->parent != nullptr) {
		n++;
		temp = temp->parent;
	}
	cout << "Dubina zadnjeg dodanog cvora je: " << n << endl;

	return 0;
}
