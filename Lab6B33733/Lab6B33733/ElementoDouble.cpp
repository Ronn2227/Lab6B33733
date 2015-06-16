#include "stdafx.h"
#include "ElementoDouble.h"

ElementoDouble::ElementoDouble(double d) : Elemento(),
d(d) {
}

ElementoDouble::~ElementoDouble() {
}

int ElementoDouble::compareTo(Elemento * otro) {
	int cmp = 0;
	ElementoDouble * eDouble = dynamic_cast<ElementoDouble *>(otro);
	if (eDouble != 0) {
		cmp = this->d < eDouble->d ? -1 : this->d == eDouble->d ? 0 : 1;
	}
	return cmp;
}

void ElementoDouble::imprimir(ostream& out) const {
	out << d;
}
