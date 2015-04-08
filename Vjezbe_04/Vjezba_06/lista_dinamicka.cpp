#include "lista_dinamicka.h"

lista_dinamicka::lista_dinamicka() {
	_head = new cvor;
	_tail = new cvor;

	_head->previous = nullptr;
	_head->next = _tail;

	_tail->previous = _head;
	_tail->next = nullptr;
}

POSITION lista_dinamicka::end() {
	return _tail;
}

POSITION lista_dinamicka::first() {
	return _head->next;
}

bool lista_dinamicka::insert(ELTYPE element, POSITION pos) {
	cvor* novi = new cvor;

	novi->element = element;
	novi->previous = pos->previous;
	novi->next = pos;

	pos->previous->next = novi;
	pos->previous = novi;

	return true;
}

bool lista_dinamicka::read(POSITION pos, ELTYPE& element) {
	element = pos->element;
	return true;
}

bool lista_dinamicka::remove(POSITION pos) {
	pos->previous->next = pos->next;
	pos->next->previous = pos->previous;
	delete pos;

	return true;
}

POSITION lista_dinamicka::find(ELTYPE element) {
	cvor* temp = _head;
	while (temp != end()) {
		// hacked to work with Country
		if (temp->element.name == element.name) {
			return temp;
		}
		temp = temp->next;
	}
	return end();
}

POSITION lista_dinamicka::empty() {
	cvor* temp = _head->next;
	while (temp != end()) {
		cvor* dalje = temp->next;
		delete temp;
		temp = dalje;
	}

	_head->next = _tail;
	_tail->previous = _head;

	return end();
}

POSITION lista_dinamicka::next(POSITION pos) {
	return pos->next;
}

POSITION lista_dinamicka::prev(POSITION pos) {
	return pos->previous;
}

lista_dinamicka::~lista_dinamicka() {
	empty();
	delete _head;
	delete _tail;
}