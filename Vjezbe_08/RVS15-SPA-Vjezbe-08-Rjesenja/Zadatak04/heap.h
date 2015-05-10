#ifndef _HEAP_H_
#define _HEAP_H_

#include "drzava.h"
using namespace std;

typedef drzava ELTYPE;
typedef unsigned int POSITION;

class heap {
private:
	static const unsigned int CAPACITY = 1000;
	ELTYPE _elements[CAPACITY];
	POSITION _next;
	
	POSITION calc_left(const POSITION parent);
	POSITION calc_right(const POSITION parent);
	POSITION calc_parent(const POSITION child);
	bool is_full();
	void reheapify_upward();
	void reheapify_downward();
	
public:
	heap();
	bool is_empty();
	void insert(const ELTYPE& element);
	ELTYPE remove();
};

#endif
