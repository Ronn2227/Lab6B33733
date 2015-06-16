#include "stdafx.h"
#include "Lista.h"


Lista::Lista(){ // Estado inicial de la lista.
	size = 0;
	cabeza = NULL;
	cola = NULL;
}


Lista::~Lista(){
	if (cabeza != NULL) {
		destruirLista();
	}
}

void Lista::insertarCabeza(Elemento * nodo){
	if (cabeza == NULL) { // Si la cabeza está vacía solo asigna (si solo hay un elemento la cabeza y la cola aputan al mimo lugar).
		cabeza = nodo;
		cabeza->setNext(NULL);
		cola = nodo;
		cola->setNext(NULL);
	}
	else { // Si no está vacía corre a todos los Elementos.
		Elemento * temp = nodo;
		temp->setNext(cabeza);
		cabeza = temp;
	}
	size++;
}

void Lista::insertarCola(Elemento* nodo){
	if (cola == NULL){ // Si la cola está vacía solo asigna.
		cola = nodo;
		cola->setNext(NULL);
		cabeza = nodo;
		cabeza->setNext(NULL);
	}
	else { // Si no lo inserta al final.
		Elemento * temp = nodo;
		cola->setNext(temp);
		cola = temp;
		cola->setNext(NULL);
	}
	size++;
}

void Lista::insertarElemento(Elemento * nodo, int donde){
	if (donde <= 0 || size == 0){ // Si la dirección es 0 (o menos para evitar excepciones) o si no hay ningún elemento en la lista (también para evitar excepciones) se inserta el Elemento en la cabeza.
		insertarCabeza(nodo);
	}
	else if (donde >= size - 1){ // Si la dirección es igual al tamaño-1 (última posición accesable pues se cuenta desde 0) o mayor (también para evitar excepciones) se inserta el Elemento en la cola.
		insertarCola(nodo);
	}
	else { // Si no avanza hasta la posicion deseada y lo inserta en ese lugar.
		Elemento * actual = cabeza;
		for (int i = 0; i < donde - 1; i++){ // Avanza en la lista hasta el elemento anterior a donde se quiere insertar.
			actual = actual->getNext();
		}
		Elemento * temp = actual->getNext();
		Elemento * nuevo = nodo;
		actual->setNext(nuevo);
		nuevo->setNext(temp);
		size++;
	}
}

void Lista::removerCabeza(){
	if (cabeza != NULL){
		if (cabeza->getNext() != NULL){ // Si hay más de un elemento elimina la cabeza y asigna la cabeza a la siguiente posición.
			Elemento * temp = cabeza;
			cabeza = cabeza->getNext();
			delete temp;
		}
		else{ // Si solo hay uno, lo borra y vuelve al estado inicial.
			Elemento * temp = cabeza;
			cabeza = NULL;
			cola = NULL;
			delete temp;
		}
		size--;
	}
}

void Lista::removerCola(){
	if (cola != NULL){
		if (size == 1){ // Si solo hay un Elemento lo borra y vuelve al estado inicial.
			Elemento * temp = cola;
			cola = NULL;
			cabeza = NULL;
			delete temp;
		}
		else{ // Sino avanza hasta el penúltimo Elemento, lo asigana como cola y borra la antigua cola.
			Elemento * actual = cabeza;
			for (int i = 0; i < size - 2; i++){
				actual = actual->getNext();
			}
			Elemento * temp = actual->getNext();
			cola = actual;
			delete temp;
			cola->setNext(NULL);
		}
		size--;
	}
}

void Lista::removerElemento(int donde){
	if (cabeza != NULL){
		if (donde <= 0 || size == 1){ // Si la dirección es 0 (o menor) o solo hay un elemento se elimina la cabeza.
			removerCabeza();
		}
		else if (donde >= size - 1){ // Si la direcciÓn es igual al tamaño-1 o mayor se elimina la cola.
			removerCola();
		}
		else { // Si no avanza hasta antes del elemento a elmininar y se elimina.
			Elemento * actual = cabeza;
			for (int i = 0; i < donde - 1; i++){ // Avanza en la lista hasta el elemento anterior al que se quiere eliminar.
				actual = actual->getNext();
			}
			Elemento * borrar = actual->getNext();
			actual->setNext(actual->getNext()->getNext());
			delete borrar;
		}
		size--;
	}
}

int Lista::buscarPorElemento(Elemento * nodo){
	bool encontrado = false;
	int posicion = -1; // Posición a devolver, si no lo encuentra devuelve un -1.
	int contador = 0;
	Elemento * actual = cabeza;
	while (encontrado == false && actual->getNext() != NULL){ // Avanza buscando hasta que lo encuentre o ya no haya más elementos.
		if (actual->compareTo(nodo) == 0){
			posicion = contador;
			encontrado = true;
		}
		else {
			actual = actual->getNext();
			contador++;
		}
	}
	if (actual->compareTo(nodo) == 0){ // Se sale del ciclo antes de comprobar el último así que se comprueba afuera.
		posicion = contador;
	}
	return posicion;
}

Elemento* Lista::buscarPorPosicion(int posicion){
	Elemento * actual = cabeza; // Elemento a devolver.
	if (posicion <= 0){ // Si la dirección es 0 (o menor) se devuelve la cabeza.
		actual = cabeza;
	}
	else if (posicion >= size - 1){ // Si la dirección es igual al tamaño-1 o mayor se devuelve la cola.
		actual = cola;
	}
	else {
		for (int i = 0; i < posicion; i++){ // Si no avanza hasta la posición solicitada y la devuelve.
			actual = actual->getNext();
		}
	}
	return actual;
}

ostream & operator<<(ostream & out, Lista & l) {
	l.imprimir(l.cabeza, out);
	return out;
}

void Lista::imprimir(Elemento* nodo, ostream& out){
	Elemento* actual = nodo;
	while (actual->getNext() != NULL){
		out << *actual << endl;
		actual = actual->getNext();
	}
	out << *actual << endl;
}

void Lista::destruirLista(){
	int tam = size;
	for (int i = 0; i < tam; i++){
		removerCabeza();
	}
}

int Lista::getSize(){
	return size;
}