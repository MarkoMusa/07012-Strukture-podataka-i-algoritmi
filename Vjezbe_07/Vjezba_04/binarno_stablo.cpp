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

void binarno_stablo::destroy(const POSITION node) {
	if (node == nullptr) { 
		return; 
	}
	
	destroy(node->left_child);
	destroy(node->right_child);
	delete node;
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

void binarno_stablo::inorder(const POSITION node) {
	if (node == nullptr) { 
		return; 
	}
	
	// Obradi lijevo dijete.
	inorder(node->left_child);

	// Obradi ovaj èvor (roditelja).
	ELTYPE element;
	if (get_node(node, element))
	{
		cout << element << ", ";
	}

	// Obradi desno dijete.
	inorder(node->right_child);
}

void binarno_stablo::preorder(const POSITION node) {
	if (node == nullptr) { 
		return; 
	}
	
	// Obradi ovaj èvor (roditelja).
	ELTYPE element;
	if (get_node(node, element))
	{
		cout << element << ", ";
	}

	// Obradi lijevo dijete.
	preorder(node->left_child);

	// Obradi desno dijete.
	preorder(node->right_child);
}

void binarno_stablo::postorder(const POSITION node) {
	if (node == nullptr) { 
		return; 
	}
	
	// Obradi lijevo dijete.
	postorder(node->left_child);

	// Obradi desno dijete.
	postorder(node->right_child);

	// Obradi ovaj èvor (roditelja).
	ELTYPE element;
	if (get_node(node, element))
	{
		cout << element << ", ";
	}
}

binarno_stablo::~binarno_stablo() {
	destroy(root_node);
}