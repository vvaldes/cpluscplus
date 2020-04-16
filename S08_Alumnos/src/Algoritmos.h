//============================================================================
// Name        : algoritmos.h
// Author      : Profesores de la asignatura EDI
// Version     : 2019/20
// Copyright   : Your copyright notice
// Description : clase para realizar algoritmos del proyecto
//============================================================================

#ifndef ALGORITMOS_H_
#define ALGORITMOS_H_
#include <iostream>
#include <fstream>
#include "Via.h"
#include "cola.h"
using namespace std;





class Algoritmos {
	Cola <Via*> * colaVias;

	void cargarVias();
	void run();
    // método privado para contar el nº de elementos de la cola recursivo
	int contar(Cola<Via*> *c);
	// método privado para mostrar los elementos de la cola recursivo
	void mostrar (Cola <Via*> *c);
public:
	Algoritmos();

	void mostrar();

	// muestra los datos de la cola de forma recursiva
	// sin perder los datos de la cola
	// TODO hacer este método
	void mostrarRecursivo();

	// cuenta el nº de elementos de la cola de forma iterativa
	// TODO hacer este método
	int  numElementos();
	// cuenta el nº de elementos de la cola de forma recursica
	int  numElementosRecursivo();

	// PRE: 0>= pos < numElementos
	// POST: inserta una nueva vía en la posición pos
	// TODO hacer este método
	void insertarEnPos (int pos, Via *v);

	// Devuelve una cola con todas las vías que empiezan por una determinada
	// raiz,
	// para saber si un string comienza por un determinado substring se puede usar
	// el método find de los string
	/*
	 *    ejemplo
	 *    string cad = "Salamanca";
	 *    string subCad1 = "Sa";
	 *
	 *    if (cad.find(subCad1) == 0)
	 *         cout  << "la cadena Salamanca comienza por la subCad1";
	 *    Lo que hace el método find es buscar en la cad la subCad, si la encuentra
	 *    devuelve la posición donde la encontro, por lo tanto si la encuentra
	 *    en la posición 0, significa que empieza por
	 *
	 */
	// TODO hacer este método
	void viasEmpiezanPor (string raiz, Cola <Via *> *&cVias);






	~Algoritmos();
};



#endif /* ALGORITMOS_H_ */
