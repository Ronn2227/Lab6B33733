// Lab6B33733.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Pila.h"
#include "ElementoInt.h"
#include "ElementoIntInt.h"
#include "ElementoDouble.h"
#include "ElementoPersona.h"

int _tmain(int argc, _TCHAR* argv[]){

	srand((unsigned int)time(NULL));

	ofstream filePruebas;
	filePruebas.open("Pruebas.txt");// Como las salidas de pruebas son muchas y no caben en la pantalla, se guardarán en un archivo a revisar.

	// Nombres posibles a elegir para las personas.
	string nombres[20] = { "Maria", "Juan", "Ana", "Pedro", "Alejandra", "Ronald", "Ximena", "Alfredo", "Amanda", "Jose",
							"Elsa", "Diego", "Amaia", "Esteban", "Elena", "Antonio", "Stephanie", "Ruben", "Tiana", "Elias" };

	int cantidadElementos = rand() % 41 + 15; // Setea cantidad de Elementos de la Pila en un valor aleatorio entre 15 y 50.
	Pila enteros;
	for (int i = 0; i < cantidadElementos; i++){
		enteros.push(new ElementoInt(rand() % 100));
	}

	filePruebas << "Pila de enteros:" << endl;
	filePruebas << enteros << endl;
	
	Elemento * actual = enteros.peek();

	filePruebas << "Primer elemento de la pila de enteros:" << endl;
	filePruebas << *actual << endl;
	filePruebas << endl;

	for (int i = 0; i < 10; i++){

		if (i > 0){ // Como lo que traía de antes era el peek no se debe hacer delete hasta después.
			delete actual;
		}

		actual = enteros.pop();
		
		filePruebas << "Actual pila de enteros :" << endl;
		filePruebas << enteros << "Antiguo primer elemento (Se elimino de la Pila):" << endl;
		filePruebas << *actual << endl;
		filePruebas << endl;
	}

	cantidadElementos = rand() % 41 + 15; // Setea cantidad de Elementos de la Pila en un valor aleatorio entre 15 y 50.
	Pila intints;
	for (int i = 0; i < cantidadElementos; i++){
		intints.push(new ElementoIntInt(rand() % 100, rand() % 100));
	}

	filePruebas << "Pila de intints:" << endl;
	filePruebas << intints << endl;

	delete actual;
	actual = intints.peek();

	filePruebas << "Primer elemento de la pila de intints:" << endl;
	filePruebas << *actual << endl;
	filePruebas << endl;

	for (int i = 0; i < 10; i++){

		if (i > 0){ // Como lo que traía de antes era el peek no se debe hacer delete hasta después.
			delete actual;
		}

		actual = intints.pop();

		filePruebas << "Actual pila de intints:" << endl;
		filePruebas << intints << "Antiguo primer elemento (Se elimino de la Pila):" << endl;
		filePruebas << *actual << endl;
		filePruebas << endl;
	}

	cantidadElementos = rand() % 41 + 15; // Setea cantidad de Elementos de la Pila en un valor aleatorio entre 15 y 50.
	Pila doubles;
	for (int i = 0; i < cantidadElementos; i++){
		double d = (double)rand() * 100 / (double)RAND_MAX; // Genera double aleatorio entre 0 y 100.
		doubles.push(new ElementoDouble(d));
	}

	filePruebas << "Pila de doubles:" << endl;
	filePruebas << doubles << endl;

	delete actual;
	actual = doubles.peek();

	filePruebas << "Primer elemento de la pila de doubles:" << endl;
	filePruebas << *actual << endl;
	filePruebas << endl;

	for (int i = 0; i < 10; i++){

		if (i > 0){ // Como lo que traía de antes era el peek no se debe hacer delete hasta después.
			delete actual;
		}

		actual = doubles.pop();

		filePruebas << "Actual pila de doubles:" << endl;
		filePruebas << doubles <<  "Antiguo primer elemento (Se elimino de la Pila):" << endl;
		filePruebas << *actual << endl;
		filePruebas << endl;
	}

	cantidadElementos = rand() % 41 + 15; // Setea cantidad de Elementos de la Pila en un valor aleatorio entre 15 y 50.
	Pila personas;
	for (int i = 0; i < cantidadElementos; i++){
		string name = nombres[rand() % 20]; // Elige aleatoriamente entre los 20 nombres.
		int id = rand() % 100; // Genera un id aleatorio entre 0 y 100.
		Persona* per = new Persona(name, id); // Crea persona con valores aleatorios.
		personas.push(new ElementoPersona(per));
	}

	filePruebas << "Pila de personas:" << endl;
	filePruebas << personas << endl;

	delete actual;
	actual = personas.peek();

	filePruebas << "Primer elemento de la pila de personas:" << endl;
	filePruebas << *actual << endl;
	filePruebas << endl;

	for (int i = 0; i < 10; i++){

		if (i > 0){ // Como lo que traía de antes era el peek no se debe hacer delete hasta después.
			delete actual;
		}

		actual = personas.pop();

		filePruebas << "Actual pila de personas:" << endl;
		filePruebas << personas << "Antiguo primer elemento (Se elimino de la Pila):" << endl;
		filePruebas << *actual << endl;
		filePruebas << endl;
	}
	delete actual;
	filePruebas.close();

	system("pause");
	return 0;
}

