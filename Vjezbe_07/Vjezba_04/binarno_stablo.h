#ifndef _BINARNO_STABLO_H_
#define _BINARNO_STABLO_H_

#include <string>
using namespace std;

typedef string ELTYPE;

struct cvor;

typedef cvor* POSITION;

struct cvor {
	ELTYPE element;
	POSITION left_child;
	POSITION right_child;
};

class binarno_stablo {
private:
	POSITION root_node;
	POSITION create_new_node(const ELTYPE& element);
	void destroy(const POSITION node);

public:
	void create(const ELTYPE& element);
	bool insert_left(const POSITION parent, const ELTYPE& element);
	bool insert_right(const POSITION parent, const ELTYPE& element);
	POSITION root();
	POSITION get_left_child(const POSITION parent);
	POSITION get_right_child(const POSITION parent);
	bool get_node(const POSITION pos, ELTYPE& element);

	void inorder(const POSITION node);
	void preorder(const POSITION node);
	void postorder(const POSITION node);

	~binarno_stablo();
};

#endif