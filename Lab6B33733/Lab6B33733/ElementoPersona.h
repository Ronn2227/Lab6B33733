#pragma once

#include "Elemento.h"
#include "Persona.h"

using namespace std;

class ElementoPersona : public Elemento {

protected:
	Persona* persona;

public:
	ElementoPersona(Persona* per);
	virtual ~ElementoPersona();
	virtual int compareTo(Elemento *);
	virtual void imprimir(ostream &) const;

};