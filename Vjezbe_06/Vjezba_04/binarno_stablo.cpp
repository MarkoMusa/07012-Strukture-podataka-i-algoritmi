#include "binarno_stablo.h"
#include <iostream>
using namespace std;

/*************** PRIVATNE METODE ****************/

POSITION binarno_stablo::create_new_node(const POSITION parent, const ELTYPE& element) {
	cvor* novi = new cvor;
	novi->element = element;
	novi->parent = parent;
	novi->left_child = nullptr;
	novi->right_child = nullptr;
	
	return novi;
}

/*************** JAVNE METODE ****************/

void binarno_stablo::create(const ELTYPE& element) {
	root_node = create_new_node(nullptr, element);
}

bool binarno_stablo::insert_left(const POSITION parent, const ELTYPE& element) {


	POSITION newNode = create_new_node(parent, element);

	if (parent->left_child != nullptr)
	{
		newNode->left_child = parent->left_child;
		newNode->left_child->parent = newNode;
	}
	parent->left_child = newNode;

	return true;
}

bool binarno_stablo::insert_right(const POSITION parent, const ELTYPE& element) {

	POSITION newNode = create_new_node(parent, element);

	if (parent->right_child != nullptr)
	{
		newNode->right_child = parent->right_child;
		newNode->right_child->parent = newNode;
	}

	parent->right_child = newNode;

	return true;
}

POSITION binarno_stablo::root() {
	return root_node;
}


POSITION binarno_stablo::get_parent(const POSITION parent) {
		return parent->parent;
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
		cout << element.getName() << endl; // TU MIJENJAJ ISPIS.
	}

	print_tree(node->left_child, level + 3);
	print_tree(node->right_child, level + 3);
}