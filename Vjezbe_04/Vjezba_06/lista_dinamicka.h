#ifndef _LISTA_DINAMICKA_H_
#define _LISTA_DINAMICKA_H_

#include <string>
#include "Country.h"

struct cvor;

typedef Country ELTYPE;
typedef cvor* POSITION;

struct cvor {
	ELTYPE element;
	POSITION previous;
	POSITION next;
};

class lista_dinamicka {
private:
	POSITION _head; // "Prvi ispred" poèetka liste.
	POSITION _tail; // "Prvi iza" kraja liste.

public:
	lista_dinamicka();
	POSITION end();
	POSITION first();
	bool insert(ELTYPE element, POSITION pos);
	bool read(POSITION pos, ELTYPE& element);
	bool remove(POSITION pos);
	POSITION find(ELTYPE element);
	POSITION empty();
	POSITION next(POSITION pos);
	POSITION prev(POSITION pos);
	~lista_dinamicka();
};

#endif