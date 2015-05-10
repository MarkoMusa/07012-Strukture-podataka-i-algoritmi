#ifndef _PRIORITETNI_RED_H_
#define _PRIORITETNI_RED_H_

#include <string>
#include "email.h"
using namespace std;

typedef email ELTYPE;

struct cvor {
	ELTYPE element;
	int priority;
	cvor* next;
};

class prioritetni_red {
private:
	cvor* _head;
	cvor* _tail;
	cvor* last_before_lower(int priority); // Èvor iza kojeg slijedi èvor s nižim prioritetom.

public:
	prioritetni_red();
	bool is_empty();
	bool enqueue(ELTYPE element, int priority);
	bool dequeue(ELTYPE& element);
	bool front(ELTYPE& element);
	~prioritetni_red();
};

#endif