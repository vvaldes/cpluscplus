/*
 * Barrio.cpp
 *
 *  Created on: 15 feb. 2019
 *      Author: mariscal
 */

#include "Barrio.h"
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
Barrio::Barrio() {

	nombre = "";
	area = 0.0;
	perimetro = 0.0;
	codigo = 0;
	distrito = "";


}
Barrio::Barrio(string nombre, float area, float perimetro, int codigo,
		string distrito) {

	this->nombre = nombre;
	this->area = area;
	this->perimetro = perimetro;
	this->codigo = codigo;
	this->distrito = distrito;

}

void Barrio::setNombre(string nombre) {
	this->nombre = nombre;
}

void Barrio::setArea(double area) {
	this->area = area;
}

void Barrio::setPerimetro(float perimetro) {
	this->perimetro = perimetro;
}

void Barrio::setCodigo(int codigo) {
	this->codigo = codigo;
}

void Barrio::setDistrito(string distrito) {
	this->distrito = distrito;
}

string Barrio::getNombre() {
	return nombre;
}

void Barrio::getNombre(string &nombre) {
	nombre = this->nombre;
}

double Barrio::getArea() {
	return area;
}

float Barrio::getPerimetro() {
	return perimetro;
}

int Barrio::getCodigo() {
	return codigo;
}

string Barrio::getDistrito() {
	return distrito;
}

void Barrio::mostrar() {


	cout << nombre << " - " << fixed << setprecision(2) << area << " - "
			<< perimetro << " - " << codigo << " - " << distrito << endl;

}




Barrio::~Barrio() {


}
