#include "stdafx.h"
#include "Pila.h"


Pila::Pila() : Lista(){
}


Pila::~Pila(){ // Llama automaticamente al desctructor de la lista que se destruye todo.
	cout << "destructor de pila" << endl;
}

void Pila::push(Elemento * nodo){ // Siempre se inserta en la cola (se toma la cola como primer elemento).
	insertarCola(nodo);
}

Elemento * Pila::peek(){ // Devuelve el primer elemento (el último que se agrego en la cola).
	return cola;
}

Elemento * Pila::pop(){ // Devuelve el primer elemento y lo remueve de la pila. 
	Elemento * temp = cola;
	retrocederCola();
	return temp;
}

ostream & operator<<(ostream & out, Pila & l) {
	l.imprimir(l.cabeza, out);
	return out;
}

void Pila::imprimir(Elemento * nodo, ostream & out){
	for (int i = size-1; i >= 0; i--){ // Imprime la pila de atras hacia adelante para que la cola quede arriba.
		out << *buscarPorPosicion(i) << endl; 
	}
}
