#include "binarno_stablo.h"
#include <iostream>
using namespace std;

/*************** PRIVATNE METODE ****************/

POSITION binarno_stablo::create_new_node(const ELTYPE& element) {
	cvor* novi = new cvor;
	novi->element = element;
	novi->left_child = nullptr;
	novi->right_child = nullptr;
	
	return novi;
}

/*************** JAVNE METODE ****************/

void binarno_stablo::create(const ELTYPE& element) {
	root_node = create_new_node(element);
}

bool binarno_stablo::insert_left(const POSITION parent, const ELTYPE& element) {
	if (parent->left_child != nullptr) {
		return false;
	}

	parent->left_child = create_new_node(element);
	return true;
}

bool binarno_stablo::insert_right(const POSITION parent, const ELTYPE& element) {
	if (parent->right_child != nullptr) {
		return false;
	}

	parent->right_child = create_new_node(element);
	return true;
}

POSITION binarno_stablo::root() {
	return root_node;
}

POSITION binarno_stablo::get_left_child(const POSITION parent) {
	return parent->left_child;
}

POSITION binarno_stablo::get_right_child(const POSITION parent) {
	return parent->right_child;
}

bool binarno_stablo::get_node(const POSITION pos, ELTYPE& element) {
	element = pos->element;
	return true;
}

void binarno_stablo::print_tree(const POSITION node, int level) {
	if (node == nullptr) { return; }

	ELTYPE element;
	if (get_node(node, element)) {
		for (int i = 0; i < level; i++) { cout << " "; }
		cout << element << endl; // TU MIJENJAJ ISPIS.
	}

	print_tree(node->left_child, level + 3);
	print_tree(node->right_child, level + 3);
}