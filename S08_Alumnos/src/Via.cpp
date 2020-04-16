//============================================================================
// Name        : Via.cpp
// Author      : Profesores de la asignatura EDI
// Version     : curso 19/20
// Copyright   : Your copyright notice
// Description : Implementación de la clase vía
//============================================================================


#include "Via.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

Via::Via() {
	this->nombre = "";
	this->codigo = 0;
	this->codBarrio = 0;
	this->longitud = 0;
	this->tipo = "";

}
Via::Via(string tipo, string nombre, float longitud, int codigo,
		int codBarrio) {
	this->nombre = nombre;
	this->codigo = codigo;
	this->codBarrio = codBarrio;
	this->longitud = longitud;
	this->tipo = tipo;

}

void Via::setCod(int cod) {
	codigo = cod;
}

void Via::setNombre(string nombre) {
	this->nombre = nombre;
}

void Via::mostrar() {
	cout<< tipo<<" "<<nombre<< " "<<longitud<<" cb: "<<codBarrio<< " cv: "<<codigo<< " "<<endl;



}


string Via::getNombre() {
	return nombre;
}



int Via::getCodigo() {
	return codigo;
}

int Via::getCodBarrio() {
	return codBarrio;
}


float Via::getLongitud() {
	return longitud;
}

string Via::getTipo() {
	return tipo;
}



Via::~Via() {

}
