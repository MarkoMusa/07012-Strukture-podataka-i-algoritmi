#include "prioritetni_red.h"

cvor* prioritetni_red::last_before_lower(int priority) {
	cvor* c = _head;
	while (c != nullptr) {
		if (c->next != nullptr && c->next->priority < priority) {
			break;
		}
		c = c->next;
	}
	return c;
}

prioritetni_red::prioritetni_red() {
	_head = new cvor;
	_head->next = nullptr;

	_tail = new cvor;
	_tail->next = nullptr;
}

bool prioritetni_red::is_empty() {
	return _head->next == nullptr && _tail->next == nullptr;
}

bool prioritetni_red::enqueue(ELTYPE element, int priority) {
	
	// Napravimo novi element.
	cvor* novi = new cvor; 
	novi->element = element;
	novi->priority = priority;
	novi->next = nullptr;

	if (is_empty()) { // Prazan red je jednostavna prièa...
		_head->next = novi;
		_tail->next = novi;
		return true;
	}

	// OK, red nije prazan pa moram pronaæi gdje æu ga zapravo insertati.
	cvor* x = last_before_lower(priority);

	if (x != nullptr) { // Iza ima elemenata nižeg prioriteta.
		novi->next = x->next;
		x->next = novi;
	}
	else { // Na kraj reda.
		_tail->next->next = novi;
		_tail->next = novi;
	}

	return true;
}

bool prioritetni_red::dequeue(ELTYPE& element) {
	if (is_empty()) {
		return false;
	}

	cvor* prvi = _head->next;
	if (prvi->next == nullptr) {
		_head->next = nullptr;
		_tail->next = nullptr;
	}
	else {
		_head->next = prvi->next;
	}

	element = prvi->element;
	delete prvi;

	return true;
}

bool prioritetni_red::front(ELTYPE& element) {
	if (is_empty()) {
		return false;
	}

	element = _head->next->element;
	return true;
}

prioritetni_red::~prioritetni_red() {
	cvor* temp = _head->next;
	while (temp != nullptr) {
		cvor* dalje = temp->next;
		delete temp;
		temp = dalje;
	}
	
	delete _head;
	delete _tail;
}