#include "stdafx.h"
#include "Elemento.h"


Elemento::Elemento() {
	next = NULL;
}

Elemento::~Elemento() {
}

Elemento *& Elemento::getNext() {
	return next;
}

void Elemento::setNext(Elemento * e) {
	this->next = e;
}

ostream & operator<<(ostream & out, const Elemento & e) {
	e.imprimir(out);
	return out;
}

bool Elemento::operator <(Elemento& otro) {
	return this->compareTo(&otro) < 0;
}

bool Elemento::operator <=(Elemento& otro) {
	return this->compareTo(&otro) <= 0;
}

bool Elemento::operator >(Elemento& otro) {
	return this->compareTo(&otro) > 0;
}

bool Elemento::operator >=(Elemento& otro) {
	return this->compareTo(&otro) >= 0;
}
