/*
 * figuras.cpp
 *
 *  Created on: 22 mar. 2020
 *      Author: root
 */



#include "iostream"
#include "figuras.h"

using namespace std;


void Rectangulo::dibujar(ostream& sal) const
{
	sal << _id << " en Posicion(" << _p.get_x() << ", " << _p.get_y() << ");" << endl;
	for (int i = 0; i < _altura; ++i) {
		for (int j = 0; j < _base; ++j) {
			sal << "*" ;
		}
		sal << endl;
	}
}

void Triangulo::dibujar(ostream& sal) const
{
	sal << _id << " en Posicion(" << _p.get_x() << ", " << _p.get_y() << ");" << endl;
	for (int i = 0; i < _altura; ++i) {
		for (int j = 0; j < _altura-i; ++j) {
			sal << " " ;
		}
		for (int j = 0; j < 2*i+1; ++j) {
			sal << "*" ;
		}
		sal << endl;
	}
}

