#include "red_dinamicki.h"

red_dinamicki::red_dinamicki() {
	_head = new cvor;
	_head->next = nullptr;

	_tail = new cvor;
	_tail->next = nullptr;
}

bool red_dinamicki::is_empty() {
	return _head->next == nullptr && _tail->next == nullptr;
}

bool red_dinamicki::enqueue(ELTYPE element) {
	cvor* novi = new cvor;
	novi->element = element;
	novi->next = nullptr;

	if (_head->next == nullptr) {
		_head->next = novi;
	}

	if (_tail->next != nullptr) {
		_tail->next->next = novi;
	}

	_tail->next = novi;

	return true;
}

bool red_dinamicki::dequeue(ELTYPE& element) {
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

bool red_dinamicki::front(ELTYPE& element) {
	if (is_empty()) {
		return false;
	}

	element = _head->next->element;
	return true;
}

red_dinamicki::~red_dinamicki() {
	empty();
	delete _head;
	delete _tail;
}

void red_dinamicki::empty() {
	cvor* temp = _head->next;
	while (temp != nullptr) {
		cvor* dalje = temp->next;
		delete temp;
		temp = dalje;
	}
	
	_head->next = nullptr;
	_tail->next = nullptr;
}