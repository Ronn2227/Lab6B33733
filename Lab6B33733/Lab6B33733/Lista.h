#pragma once

#include "Elemento.h"

using namespace std;

class Lista {

	friend ostream & operator<<(ostream &, Lista &);

protected:

	Elemento * cabeza;
	Elemento * cola;
	int size;

	Lista();
	virtual ~Lista();
	void insertarCabeza(Elemento *);
	void insertarCola(Elemento *);
	void insertarElemento(Elemento *, int);
	void removerCabeza();
	void removerCola();
	void removerElemento(int); // Remueve un elemento de la lista seg�n una posici�n.
	void retrocederCola(); // Mueve la cola al Elemento anterior.
	int getSize(); // Devuelve el tama�o de la lista (cantidad de elementos).
	int buscarPorElemento(Elemento *); // Busca un elemento en la lista y deuelve la posici�n donde lo encontr� (El primero que encuentra).
	Elemento * buscarPorPosicion(int); // Devuelve el Elemento seg�n una posici�n.
	virtual void imprimir(Elemento *, ostream &); // Devuelve un out que sirve para imprimir la lista.

private:
	void destruirLista(); // Destruye la lista.
};

ostream & operator<<(ostream &, Lista &);