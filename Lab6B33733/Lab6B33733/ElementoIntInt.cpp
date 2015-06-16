#include "stdafx.h"
#include "ElementoIntInt.h"


ElementoIntInt::ElementoIntInt(int i, int j) : ElementoInt(i), j(j) {
}


ElementoIntInt::~ElementoIntInt(){
}

int ElementoIntInt::compareTo(Elemento * otro){
	int cmp = 0;
	ElementoIntInt * eIntInt = dynamic_cast<ElementoIntInt *>(otro);
	if (eIntInt != 0) {
		int n = this->i * this->j;
		int m = eIntInt->i * eIntInt->j;
		cmp = n < m ? -1 : n == m ? 0 : 1;
	}
	return cmp;
}

void ElementoIntInt::imprimir(ostream & out) const {
	out << (i*j);
}