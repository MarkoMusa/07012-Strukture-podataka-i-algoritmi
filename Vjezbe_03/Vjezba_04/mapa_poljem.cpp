#include "mapa_poljem.h"

mapa_poljem::mapa_poljem() {
	// Zadnji element liste je na poziciji 0 jer lista ne postoji ("prvi iza" je na poziciji 1).
	_last = 0;
	_pos = 0;
	_null = _v[CAPACITY - 1];
}

int mapa_poljem::getIndex(KEY key) {
	for (int i = 0; i < _last; i++) {
		if (_k[i] == key) {
			return i;
		}
	}
	return -1;
}


KEY mapa_poljem::first()	{	return _k[0];			}
KEY mapa_poljem::last()		{	return _k[_last-1];	}

bool mapa_poljem::add(KEY key, VALUE value) {

	if (_last < CAPACITY) {
		_k[_last] = key;
		_v[_last] = value;
		_last++;
		_pos = _last; // TODO: Decide if this and remove should update position
		return true;
	}
	return false;
}

bool mapa_poljem::remove(KEY key) {

	int pos = getIndex(key);

	// Je li ispravna pozicija unutar liste?
	if (pos >= 0 && pos < _last) {
		// Pomakni u lijevo. 
		for (int i = pos; i < _last; i++) {
			_k[i] = _k[i + 1];
			_v[i] = _v[i + 1];
		}

		// Ažuriraj _last.
		_last--;
		_pos =  pos;
		return true;
	}
	return false;
}


VALUE mapa_poljem::get(KEY key) {
	int pos = getIndex(key);
	if (pos >= 0) 
	{
		_pos = pos;
		return _v[pos];
	}
	return _null;
}

VALUE mapa_poljem::end() { return _null; }

void mapa_poljem::empty() { _last = _pos = 0; }


// Iteration
KEY mapa_poljem::next()		{ return _k[++_pos];	}
KEY mapa_poljem::prev()		{ return _k[--_pos];	}
void mapa_poljem::reset()	{ _pos = 0;				}
int mapa_poljem::size()		{ return _last;			}