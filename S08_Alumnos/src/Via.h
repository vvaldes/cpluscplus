//============================================================================
// Name        : Via.h
// Author      : Profesores de la asignatura EDI
// Version     : curso 19/20
// Copyright   : Your copyright notice
// Description : Definición de la clase vía
//============================================================================


#ifndef VIA_H_
#define VIA_H_



#include <iostream>
using namespace std;

class Via {
	string tipo;
	string nombre;
	float  longitud;
	int    codigo;
	int    codBarrio;



public:
	Via    ();
	Via    (string tipo, string nombre,float longitud ,int codigo, int codBarrio);

	void   setCod(int cod);
	void   setNombre(string nombre);
	void   mostrar();

	string getNombre();
	int    getCodigo();
	int    getCodBarrio();
	float  getLongitud();
	string getTipo();


	 ~Via();
};

#endif /* VIA_H_ */
