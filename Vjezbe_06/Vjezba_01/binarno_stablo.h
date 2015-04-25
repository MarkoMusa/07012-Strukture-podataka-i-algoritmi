#ifndef _BINARNO_STABLO_H_
#define _BINARNO_STABLO_H_

#include <string>
using namespace std;

typedef int ELTYPE;
typedef unsigned int POSITION;

struct cvor {
	ELTYPE element;
};

class binarno_stablo {
private:
	static const unsigned int CAPACITY = 100;
	cvor _elements[CAPACITY];
	POSITION calc_left(const POSITION pos);
	POSITION calc_right(const POSITION pos);
	bool is_valid_pos(const POSITION pos);
	bool insert(const POSITION pos, const ELTYPE& element);

public:
	void create(const ELTYPE& element);
	bool insert_left(const POSITION parent, const ELTYPE& element);
	bool insert_right(const POSITION parent, const ELTYPE& element);
	POSITION root();
	POSITION get_left_child(const POSITION parent);
	POSITION get_right_child(const POSITION parent);
	bool get_node(const POSITION pos, ELTYPE& element);
	
	void print_tree(); // Samo za potrebe debuga...
};

#endif