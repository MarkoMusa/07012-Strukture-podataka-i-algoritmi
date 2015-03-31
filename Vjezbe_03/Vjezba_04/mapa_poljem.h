#ifndef _MAPA_POLJEM_H_
#define _MAPA_POLJEM_H_

#include <string>
using namespace std;

typedef string KEY;
typedef string VALUE;

class mapa_poljem {
private:
	static const unsigned int CAPACITY = 10;
	KEY _k[CAPACITY];
	VALUE _v[CAPACITY];
	int _pos;
	int _last; // Pozicija zadnjeg elementa liste (odmah ispred mjesta "prvo iza").
	int getIndex(KEY key);
	int getIndex(VALUE val);
public:
	mapa_poljem();
	
	bool add(KEY key, VALUE val);
	bool remove(KEY key);
	
	VALUE get(KEY key);
	KEY get(VALUE val);
	
	KEY last();
	KEY first();
	KEY next();
	KEY prev();

	void empty();
	void reset();
};

#endif