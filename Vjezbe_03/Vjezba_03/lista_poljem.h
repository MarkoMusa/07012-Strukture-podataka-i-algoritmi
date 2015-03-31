#ifndef _LISTA_POLJEM_H_
#define _LISTA_POLJEM_H_

#include <string>
using namespace std;

typedef unsigned int POSITION;
typedef string ELTYPE;

class lista_poljem {
private:
	static const unsigned int CAPACITY = 10000;
	ELTYPE _elements[CAPACITY];
	POSITION _last; // Pozicija zadnjeg elementa liste (odmah ispred mjesta "prvo iza").

public:
	lista_poljem();
	POSITION end();
	POSITION first();
	bool insert(ELTYPE element, POSITION pos);
	bool read(POSITION pos, ELTYPE& element);
	bool remove(POSITION pos);
	POSITION find(ELTYPE element);
	POSITION empty();
	POSITION next(POSITION pos);
	POSITION prev(POSITION pos);
	int size();
};

#endif