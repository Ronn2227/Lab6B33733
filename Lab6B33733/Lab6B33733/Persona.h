#pragma once

using namespace std;

class Persona {

	friend ostream & operator<<(ostream &, const Persona &);

private:

	int id;
	string nombre;

public:

	Persona(string, int);
	virtual ~Persona();

	int compareTo(Persona*);
	void imprimir(ostream &) const;
};

ostream & operator<<(ostream &, const Persona &);
