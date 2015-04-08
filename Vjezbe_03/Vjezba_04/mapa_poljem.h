#ifndef _MAPA_POLJEM_H_
#define _MAPA_POLJEM_H_

#include <string>
using namespace std;

typedef string KEY;
typedef double VALUE;

class mapa_poljem {
private:
	static const unsigned int CAPACITY = 200;
	KEY _k[CAPACITY];
	VALUE _v[CAPACITY];
	VALUE _null;
	int _pos;
	int _last; // Pozicija zadnjeg elementa liste (odmah ispred mjesta "prvo iza").
	int getIndex(KEY key);

public:
	mapa_poljem();
	
	bool add(KEY key, VALUE val);
	bool remove(KEY key);
	VALUE get(KEY key);
	VALUE end();

	KEY last();
	KEY first();
	KEY next();
	KEY prev();

	int size();
	void empty();
	void reset();
};

#endif