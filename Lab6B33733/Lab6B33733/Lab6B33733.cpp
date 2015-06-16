// Lab6B33733.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Pila.h"
#include "ElementoInt.h"


int _tmain(int argc, _TCHAR* argv[]){

	srand((unsigned int)time(NULL));

	Pila p;
	for (int i = 0; i < 10; i++){
		p.push(new ElementoInt(rand() % 100));
	}

	cout << p << endl;

	Elemento * actual = p.peek();

	cout << *actual << endl;

	actual = p.pop();

	cout << *actual << endl;
	cout << "nueva pila" << endl;
	cout << p << endl;

	actual = p.pop();

	cout << *actual << endl;
	cout << "nueva pila" << endl;
	cout << p << endl;

	actual = p.pop();

	cout << *actual << endl;
	cout << "nueva pila" << endl;
	cout << p << endl;

	system("pause");
	return 0;
}

