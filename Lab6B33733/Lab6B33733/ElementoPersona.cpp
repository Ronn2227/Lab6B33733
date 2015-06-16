#include "stdafx.h"
#include "ElementoPersona.h"

ElementoPersona::ElementoPersona(Persona* per) : Elemento() {
	this->persona = per;
}

ElementoPersona::~ElementoPersona() {
	delete persona;
}

int ElementoPersona::compareTo(Elemento * otro) {
	int cmp = 0;
	ElementoPersona * ePer = dynamic_cast<ElementoPersona *>(otro);
	if (ePer != 0) {
		cmp = this->persona->compareTo(ePer->persona);
	}
	return cmp;
}

void ElementoPersona::imprimir(ostream & out) const {
	out << *persona;
}