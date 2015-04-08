#include "lista_poljem.h"

lista_poljem::lista_poljem() {
	lista_poljem(100);
}

lista_poljem::lista_poljem(int size) 
{
	// Zadnji element liste je na poziciji 0 jer lista ne postoji ("prvi iza" je na poziciji 1).
	_capacity = size;
	_last = 0;
	_elements = new ELTYPE[_capacity];
}


lista_poljem::~lista_poljem()
{
	delete[] _elements;
}
POSITION lista_poljem::end() {
	return _last + 1;
}

POSITION lista_poljem::first() {
	return 1;
}

bool lista_poljem::insert(ELTYPE element, POSITION pos) {
	// Je li ispravna pozicija za umetanje? 
	// Pozicija je ispravna ako se nalazi unutar liste ili na "prvom iza" (ali samo ako æe "prvi iza" stati u polje).
	if (pos >= first() && pos <= end() && _last < _capacity) {
		// Pomakni u desno.
		for (POSITION i = _last; i >= pos; i--) {
			_elements[i] = _elements[i - 1];
		}

		// Upiši novi i ažuriraj _last.
		_elements[pos - 1] = element;
		_last++;
		return true;
	}
	return false;
}

bool lista_poljem::read(POSITION pos, ELTYPE& element) {
	// Je li ispravna pozicija unutar liste?
	if (pos >= first() && pos < end()) {
		element = _elements[pos - 1];
		return true;
	}
	return false;
}

bool lista_poljem::remove(POSITION pos) {
	// Je li ispravna pozicija unutar liste?
	if (pos >= first() && pos < end()) {
		// Pomakni u lijevo. 
		for (POSITION i = pos - 1; i < _last - 1; i++) {
			_elements[i] = _elements[i + 1];
		}

		// Ažuriraj _last.
		_last--;
		return true;
	}
	return false;
}

POSITION lista_poljem::find(ELTYPE element) {
	// TODO: This would really require operator overloading and templates
	for (POSITION i = first(); i < end(); i++) {
		if (_elements[i - 1].name == element.name && _elements[i - 1].avgAge == element.avgAge) {
			return i;
		}
	}
	return end();
}

POSITION lista_poljem::empty() {
	_last = 0;
	return end();
}

POSITION lista_poljem::next(POSITION pos) {
	return pos + 1;
}

POSITION lista_poljem::prev(POSITION pos) {
	return pos - 1;
}