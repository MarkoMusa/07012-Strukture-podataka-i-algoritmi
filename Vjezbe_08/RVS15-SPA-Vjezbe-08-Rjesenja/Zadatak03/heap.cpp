#include <string>
#include <iostream>
#include "heap.h"
using namespace std;

/**************** PRIVATNO ****************************/

POSITION heap::calc_left(POSITION parent) {
	return parent * 2 + 1;
}

POSITION heap::calc_right(POSITION parent) {
	return parent * 2 + 2;
}

POSITION heap::calc_parent(POSITION child) {
	return (child - 1) / 2;
}

bool heap::is_full() {
	return _next == CAPACITY;
}

void heap::reheapify_upward() {
	// Pomi�i taj element prema vrhu hrpe.
	POSITION pos = _next;

	// Petlju vrtimo sve dok ne do�emo do korijena ili dok roditelj nije ve�i ili jednak djetetu.
	while (pos > 0 && _elements[pos].sifra > _elements[calc_parent(pos)].sifra) {
		swap(_elements[pos], _elements[calc_parent(pos)]);

		pos = calc_parent(pos);
	}
}

void heap::reheapify_downward() {
	// Indeks�trenutnog��vora�roditelja,�po�injemo�s�korijenom.
	POSITION pos = 0;
	
	// Radi�sve�dok�je�indeks�roditelja�na�predzadnjem�nivou.
	while (pos < _next / 2) {

		// Izra�unaj�indeks�djeteta�koje�sadr�i�ve�i�element.
		POSITION left_child = calc_left(pos);
		POSITION right_child = calc_right(pos);

		POSITION index_with_greater_value;

		// Mogu�e su tri situacije: nema djece, postoji lijevo dijete ili postoje oba djeteta.
		if (left_child >= _next && right_child >= _next) {
			return; // Nema djece.
		}
		else if (left_child < _next && right_child >= _next) {
			index_with_greater_value = left_child; // Postoji samo lijevo.
		}
		else { // Postoje oba djeteta pa uspore�ujem koje je ve�e.
			if (_elements[left_child].sifra >= _elements[right_child].sifra) {
				index_with_greater_value = left_child;
			}
			else {
				index_with_greater_value = right_child;
			}
		}

		// Zamijeni�ako�je�u�djetetu�ve�i�element.
		if (_elements[pos].sifra < _elements[index_with_greater_value].sifra) {
			swap(_elements[pos], _elements[index_with_greater_value]);
		}
		else {
			// Ina�e�je�algoritam�gotov,�element�je�na�svom�mjestu.
			return;
		}

		// Nastavi�zamjene�u�toj�grani.
		pos = index_with_greater_value;
	}
}

/**************** JAVNO ****************************/

heap::heap() {
	_next = 0;
}

bool heap::is_empty() {
	return _next == 0;
}

void heap::insert(const ELTYPE& element) {
	if (is_full()) {
		throw string("Hrpa je puna!");
	}

	// Spremi element na sljede�e mjesto.
	_elements[_next] = element;

	reheapify_upward();

	// Ozna�i da smo ubacili jo� jedan element.
	_next++;
}

ELTYPE heap::remove() {
	if (is_empty()) {
		throw string("Hrpa je prazna");
	}

	ELTYPE element_na_vrhu = _elements[0];

	// Ozna�i da vadimo element.
	_next--;

	// Ako�nismo�obrisali�korijen,�preslo�i�hrpu.
	if (_next > 0) {

		// Stavi�zadnji�element�na�mjesto�korijena.
		_elements[0] = _elements[_next];

		// Preslo�i hrpu.
		reheapify_downward();
	}

	return element_na_vrhu;
}
