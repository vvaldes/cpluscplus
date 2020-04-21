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
#include "Barrio.h"
#include "pila.h"
#include "listapi.h"

using namespace std;



class Algoritmos {
	Pila <Barrio *> * pBarrios;

	void cargarBarrios ();
	void mostrar       (Pila <Barrio *> *pB);
	void insertarFondo (Pila <Barrio *> *pB, Barrio * b);

	int numElementos   (Pila <Barrio *> *pB);
	void getFondo      (Pila <Barrio *> *pB, Barrio *&b);
    // TODO terminar, poner la cabeceras correctas
	//void getListaBarrios(???);
	//void escribirFichero(???);
public:
	Algoritmos();

	void run();
	// Desc: inserta un nuevo elemento en la cima
	void insertar     (Barrio *b);
    // Desc: insertar un nuevo elemento al fondo de la pila
	void insertarFondo(Barrio *b);

	// Desc: cuenta el nº de elementos
	int numElementos();

	// Desc: obtiene el barrio que está en el fondo de la pila
	void getFondo (Barrio *&b);

	// TODO terminar, poner la cabeceras correctas
    // Desc: devuelve una lista ordenada con los barrios de un distrito
	void getListaBarrios(string nombre, ListaPI <Barrio *> *pB);
	void mostrar(ListaPI <Barrio *> *pB);
	void insertarOrdenado(Barrio *b,ListaPI <Barrio *> *pB); //insertamos barrio en lista ordenada

	// Desc: escribe eun un fichero de texto todos los barrios de un distrito
	void escribirFichero(string nombreDistrito,ListaPI <Barrio *> *pB);
	void recorrerLista(ofstream *fEnt,ListaPI <Barrio *> *pB);

	// Desc: muestra en pantalla todos los datos de la pila
	void mostrar();

	~Algoritmos();
};



#endif /* ALGORITMOS_H_ */
