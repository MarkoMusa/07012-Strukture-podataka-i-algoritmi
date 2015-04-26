#ifndef _BST_H_
#define _BST_H_

struct cvor;

typedef unsigned long int ELTYPE; // <==== DEFINE TYPE HERE
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
	POSITION root();
	void insert(const ELTYPE& element);
	void inorder(const POSITION node);
	void inorder_reverse(const POSITION node);
	bool exists(const ELTYPE& element);
	bool get_node(const POSITION pos, ELTYPE& element);
	~bst();
};

#endif
