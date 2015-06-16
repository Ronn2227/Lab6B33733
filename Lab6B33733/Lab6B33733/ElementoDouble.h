#pragma once

#include "Elemento.h"

using namespace std;

class ElementoDouble : public Elemento {

protected:
	double d;

public:
	ElementoDouble(double d);
	virtual ~ElementoDouble();
	virtual int compareTo(Elemento *);
	virtual void imprimir(ostream &) const;
};
