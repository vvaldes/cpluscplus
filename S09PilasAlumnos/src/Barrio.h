
//============================================================================
// Name        : Barrio.h
// Author      : Profesores de la asignatura EDI
// Version     : curso 19/20
// Copyright   : Your copyright notice
// Description : Especificación de la clase barrio
//============================================================================
#ifndef BARRIO_H_
#define BARRIO_H_


#include <string>
#include <iostream>
using namespace std;

class Barrio {
private:
	string  nombre;
	double   area;
	float   perimetro;
	int     codigo;
	string  distrito;


public:
	/*
	* Pre:
	* Post: Inicializa los atributos del objeto creado
	* Complejidad: O(1)
	 */
	Barrio();
    // constructor parametrizado
	Barrio(string nombre, float area, float perimetro, int codigo, string distrito);


	/*
	 * pre:
	 * post:
	 * Complejidad:
	 */
	//métodos modificadores
	void setNombre    (string nombre  );
	void setArea      (double area    );
	void setPerimetro (float perimetro);
	void setCodigo    (int codigo     );
	void setDistrito  (string distrito);

	// selectores
	string getNombre   ();
	void   getNombre   (string &nombre);
	double getArea     ();
	float  getPerimetro();
	int    getCodigo   ();
	string getDistrito ();

	void   mostrar();

	/*
	* Pre:
	* Post: Libera los recursos asociados los atributos del objeto creado
	* Complejidad: O(1)
	*/
	~Barrio();
};

#endif /* BARRIO_H_ */
