#pragma once

#include "Lista.h"

using namespace std;

class Pila : protected Lista {

	friend ostream & operator<<(ostream &, Pila &);

public:

	Pila();
	virtual ~Pila();

	void push(Elemento *); // Agrega un elemento a la pila.
	Elemento * peek(); // Muestra el primer elemento de la pila.
	Elemento * pop(); // Devuelve y remueve el primer elemento de la pila.

private:

	void imprimir(Elemento *, ostream &);

};

ostream & operator<<(ostream & out, Pila & l);