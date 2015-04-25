#ifndef _BINARNO_STABLO_H_
#define _BINARNO_STABLO_H_

#include <string>
#include "osoba.h"
using namespace std;

typedef osoba ELTYPE;

struct cvor;

typedef cvor* POSITION;

struct cvor {
	ELTYPE element;
	POSITION left_child;
	POSITION right_child;
	POSITION parent;
};

class binarno_stablo {
private:
	POSITION root_node;
	POSITION create_new_node(const ELTYPE& element);

public:
	void create(const ELTYPE& element);
	bool insert_left(const POSITION parent, const ELTYPE& element);
	bool insert_right(const POSITION parent, const ELTYPE& element);
	POSITION root();
	POSITION get_left_child(const POSITION parent);
	POSITION get_right_child(const POSITION parent);
	bool get_node(const POSITION pos, ELTYPE& element);
	void print_tree(const POSITION node, int level);
};

#endif