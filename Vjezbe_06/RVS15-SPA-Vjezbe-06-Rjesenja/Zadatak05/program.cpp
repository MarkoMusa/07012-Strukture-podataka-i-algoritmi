#include <iostream>
#include <string>
#include "binarno_stablo.h"
using namespace std;

int ispisi_dubinu(binarno_stablo& tree, POSITION node) {
	int n = 0;
	while (node->parent != nullptr) {
		n++;
		node = node->parent;
	}
	return n;
}

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

	POSITION node_ema = tree.get_right_child(node_ferdo);

	cout << "Prije dodavanja:" << endl;
	tree.print_tree(tree.root(), 0);
	cout << "Dubina zadnjeg dodanog cvora je: " << ispisi_dubinu(tree, node_ema) << endl;

	// Dodavanje na veæ zauzeto mjesto.
	osoba ranko("Ranko", "Rankic");
	tree.insert_left(node_iva, ranko);

	cout << endl << "Nakon dodavanja:" << endl;
	tree.print_tree(tree.root(), 0);
	cout << "Dubina zadnjeg dodanog cvora je: " << ispisi_dubinu(tree, node_ema) << endl;

	// Pokušaj uklanjanja Anine djece æe ukloniti samo Juru jer on nema djece.
	tree.remove_children(korijen);
	cout << endl << "Nakon uklanjanja Anine djece:" << endl;
	tree.print_tree(tree.root(), 0);

	return 0;
}
