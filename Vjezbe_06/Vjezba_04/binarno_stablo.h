#ifndef _BINARNO_STABLO_H_
#define _BINARNO_STABLO_H_

#include <string>
#include "Osoba.h"

using namespace std;

struct cvor;

typedef Osoba ELTYPE;
typedef cvor* POSITION;

struct cvor {
	ELTYPE element;
	POSITION parent;
	POSITION left_child;
	POSITION right_child;
};

class binarno_stablo {
private:
	POSITION root_node;
	POSITION create_new_node(const POSITION parent, const ELTYPE& element);

public:
	void create(const ELTYPE& element);
	bool insert_left(const POSITION parent, const ELTYPE& element);
	bool insert_right(const POSITION parent, const ELTYPE& element);
	POSITION root();
	POSITION get_parent(const POSITION parent);
	POSITION get_left_child(const POSITION parent);
	POSITION get_right_child(const POSITION parent);
	bool get_node(const POSITION pos, ELTYPE& element);
	void print_tree(const POSITION node, int level);
};

#endif