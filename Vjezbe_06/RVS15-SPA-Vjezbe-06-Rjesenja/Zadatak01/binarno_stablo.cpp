#include "binarno_stablo.h"
#include <iostream>
using namespace std;

/*************** PRIVATNE METODE ****************/

POSITION binarno_stablo::calc_left(const POSITION pos) {
	return 2 * pos + 1;
}

POSITION binarno_stablo::calc_right(const POSITION pos) {
	return 2 * pos + 2;
}

bool binarno_stablo::is_valid_pos(const POSITION pos) {
	return pos >= 0 && pos < CAPACITY;
}

bool binarno_stablo::insert(const POSITION pos, const ELTYPE& element) {
	if (!is_valid_pos(pos)) {
		return false; // Neuspjeh.
	}

	cvor novi;
	novi.element = element;
	_elements[pos] = novi;
	
	return true; // Uspjeh.
}

/*************** JAVNE METODE ****************/

void binarno_stablo::create(const ELTYPE& element) {
	insert(0, element);
}

bool binarno_stablo::insert_left(const POSITION parent, const ELTYPE& element) {
	POSITION pos = calc_left(parent);
	return insert(pos, element);
}

bool binarno_stablo::insert_right(const POSITION parent, const ELTYPE& element) {
	POSITION pos = calc_right(parent);
	return insert(pos, element);
}

POSITION binarno_stablo::root() {
	return 0;
}

POSITION binarno_stablo::get_left_child(const POSITION parent) {
	return calc_left(parent);
}

POSITION binarno_stablo::get_right_child(const POSITION parent) {
	return calc_right(parent);
}

bool binarno_stablo::get_node(const POSITION pos, ELTYPE& element) {
	if (!is_valid_pos(pos)) {
		return false;
	}

	element = _elements[pos].element;
	return true;
}

void binarno_stablo::print_tree() {
	for (unsigned int i = 0; i < CAPACITY; i++) {
		cout << "(" << i << ") " << _elements[i].element << endl;
	}
}