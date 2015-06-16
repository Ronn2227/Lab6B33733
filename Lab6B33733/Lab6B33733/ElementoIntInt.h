#pragma once

#include "ElementoInt.h"

class ElementoIntInt : public ElementoInt {

private:
	int j;

public:
	ElementoIntInt(int i, int j);
	~ElementoIntInt();
	int compareTo(Elemento *);
	void imprimir(ostream &) const;
};

