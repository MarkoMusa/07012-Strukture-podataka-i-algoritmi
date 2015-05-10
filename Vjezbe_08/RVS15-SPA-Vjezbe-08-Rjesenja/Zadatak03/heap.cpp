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
	// Pomièi taj element prema vrhu hrpe.
	POSITION pos = _next;

	// Petlju vrtimo sve dok ne doðemo do korijena ili dok roditelj nije veæi ili jednak djetetu.
	while (pos > 0 && _elements[pos].sifra > _elements[calc_parent(pos)].sifra) {
		swap(_elements[pos], _elements[calc_parent(pos)]);

		pos = calc_parent(pos);
	}
}

void heap::reheapify_downward() {
	// Indeks trenutnog èvora roditelja, poèinjemo s korijenom.
	POSITION pos = 0;
	
	// Radi sve dok je indeks roditelja na predzadnjem nivou.
	while (pos < _next / 2) {

		// Izraèunaj indeks djeteta koje sadrži veæi element.
		POSITION left_child = calc_left(pos);
		POSITION right_child = calc_right(pos);

		POSITION index_with_greater_value;

		// Moguæe su tri situacije: nema djece, postoji lijevo dijete ili postoje oba djeteta.
		if (left_child >= _next && right_child >= _next) {
			return; // Nema djece.
		}
		else if (left_child < _next && right_child >= _next) {
			index_with_greater_value = left_child; // Postoji samo lijevo.
		}
		else { // Postoje oba djeteta pa usporeðujem koje je veæe.
			if (_elements[left_child].sifra >= _elements[right_child].sifra) {
				index_with_greater_value = left_child;
			}
			else {
				index_with_greater_value = right_child;
			}
		}

		// Zamijeni ako je u djetetu veæi element.
		if (_elements[pos].sifra < _elements[index_with_greater_value].sifra) {
			swap(_elements[pos], _elements[index_with_greater_value]);
		}
		else {
			// Inaèe je algoritam gotov, element je na svom mjestu.
			return;
		}

		// Nastavi zamjene u toj grani.
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

	// Spremi element na sljedeæe mjesto.
	_elements[_next] = element;

	reheapify_upward();

	// Oznaèi da smo ubacili još jedan element.
	_next++;
}

ELTYPE heap::remove() {
	if (is_empty()) {
		throw string("Hrpa je prazna");
	}

	ELTYPE element_na_vrhu = _elements[0];

	// Oznaèi da vadimo element.
	_next--;

	// Ako nismo obrisali korijen, presloži hrpu.
	if (_next > 0) {

		// Stavi zadnji element na mjesto korijena.
		_elements[0] = _elements[_next];

		// Presloži hrpu.
		reheapify_downward();
	}

	return element_na_vrhu;
}
