#include "stdafx.h"
#include "Persona.h"


Persona::Persona(string name, int id){
	this->nombre = name;
	this->id = id;
}


Persona::~Persona(){
}

int Persona::compareTo(Persona* otro){
	int cmp = this->id < otro->id ? -1 : this->id == otro->id ? 0 : 1; // Se compara con otra Persona por id.
	return cmp;
}

ostream & operator<<(ostream & out, const Persona & per) {
	per.imprimir(out);
	return out;
}

void Persona::imprimir(ostream & out) const {
	out << nombre << " id: " << id;
}