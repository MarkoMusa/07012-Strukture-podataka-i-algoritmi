#ifndef _LISTA_POLJEM_H_
#define _LISTA_POLJEM_H_

#include <string>
#include "Country.h"

typedef unsigned int POSITION;
typedef Country ELTYPE;

class lista_poljem {
private:
	unsigned int _capacity;
	ELTYPE* _elements;
	POSITION _last; // Pozicija zadnjeg elementa liste (odmah ispred mjesta "prvo iza").

public:
	lista_poljem();
	lista_poljem(int size);
	~lista_poljem();
	POSITION end();
	POSITION first();
	bool insert(ELTYPE element, POSITION pos);
	bool read(POSITION pos, ELTYPE& element);
	bool remove(POSITION pos);
	POSITION find(ELTYPE element);
	POSITION empty();
	POSITION next(POSITION pos);
	POSITION prev(POSITION pos);
};

#endif