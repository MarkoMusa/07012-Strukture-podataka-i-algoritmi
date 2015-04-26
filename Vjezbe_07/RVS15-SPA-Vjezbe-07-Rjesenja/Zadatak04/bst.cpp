#include "bst.h"

/*************** PRIVATNE METODE ****************/

POSITION bst::create_new_node(const ELTYPE& element) {
	cvor* novi = new cvor;
	novi->element = element;
	novi->left_child = nullptr;
	novi->right_child = nullptr;

	return novi;
}

void bst::insert(const ELTYPE& element, POSITION current) {
	if (element > current->element) {
		if (current->left_child != nullptr) {
			insert(element, current->left_child);
		}
		else {
			current->left_child = create_new_node(element);
		}
	}
	else {
		if (current->right_child != nullptr) {
			insert(element, current->right_child);
		}
		else {
			current->right_child = create_new_node(element);
		}
	}
}

bool bst::exists(const ELTYPE& element, POSITION parent) {
	if (parent == nullptr) {
		return false;
	}

	if (element > parent->element) {
		return exists(element, parent->left_child);
	}
	else if (element < parent->element) {
		return exists(element, parent->right_child);
	}
	else {
		return true;
	}
}

void bst::destroy(const POSITION node) {
	if (node == nullptr) { 
		return; 
	}
	
	destroy(node->left_child);
	destroy(node->right_child);
	delete node;
}

/*************** JAVNE METODE ****************/

bst::bst() {
	root_node = nullptr;
}

void bst::insert(const ELTYPE& element) {
	if (root_node == nullptr) {
		root_node = create_new_node(element); // Prvi uvijek ide u korijen.
	}
	else {
		insert(element, root_node); // Za sve ostale počnemo od korijena pa gdje završimo...
	}
}

bool bst::exists(const ELTYPE& element) {
	return exists(element, root_node); // Počni pretragu od korijena.
}

bst::~bst() {
	destroy(root_node);
}

POSITION bst::root() {
	return root_node;
}

void bst::inorder(const POSITION node) {
	if (node == nullptr) {
		return;
	}

	inorder(node->left_child);
	cout << node->element << ", ";
	inorder(node->right_child);
}