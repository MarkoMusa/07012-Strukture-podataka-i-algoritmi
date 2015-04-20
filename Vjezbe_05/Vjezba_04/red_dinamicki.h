#ifndef _RED_H_
#define _RED_H_

#include <string>
using namespace std;

typedef string ELTYPE;

struct cvor {
	ELTYPE element;
	cvor* next;
};

class red_dinamicki {
private:
	cvor* _head;
	cvor* _tail;
	void empty();

public:
	red_dinamicki();
	bool is_empty();
	bool enqueue(ELTYPE element);
	bool dequeue(ELTYPE& element);
	bool front(ELTYPE& element);
	~red_dinamicki();
};

#endif