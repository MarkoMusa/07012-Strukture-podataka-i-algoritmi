#ifndef _BST_H_
#define _BST_H_

#include <iostream>
using namespace std;

typedef int ELTYPE;

struct cvor;

typedef cvor* POSITION;

struct cvor {
	ELTYPE element;
	POSITION left_child;
	POSITION right_child;
};

class bst {
private:
	POSITION root_node;
	POSITION create_new_node(const ELTYPE& element);
	void insert(const ELTYPE& element, POSITION parent);
	bool exists(const ELTYPE& element, POSITION parent);
	void destroy(const POSITION node);

public:
	bst();
	void insert(const ELTYPE& element);
	bool exists(const ELTYPE& element);
	~bst();
};

#endif
