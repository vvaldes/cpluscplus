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
#include <string>

#include "bstree.h"
using namespace std;

class Algoritmos {

	BSTree<int> *abb;

	void run();

	void inOrden(BSTree<int> *bst);
	void preOrden(BSTree<int> *bst);
	void postOrden(BSTree<int> *bst);

	/*
	 * Cuenta el número de nodos del árbol
	 */
	int numElementos(BSTree<int> *bst);

	/*
	 * suma los elementos de los nodos del árbol
	 */
	int suma(BSTree<int> *bst);

	/*
	 * Cuenta el número de enlaces vacíos de los nodos del árbol
	 */
	int contarEnlacesVacios(BSTree<int> *bst);
	/*
	 * Cuenta el número de hojas del árbol, devuelve el valor como retorno del método
	 */
	int contarHojas(BSTree<int> *bst);

	/*
	 * Escribe en el fichero de texto "Datos.txt" todo el contenido del árbol
	 */
	void arbolAFichero (BSTree<int> *bts, ofstream &f);


public:
	Algoritmos();

	void insertar(int num);

	void recorridoInOrden();
	void recorridoPreOrden();
	void recorridoPostOrden();
	/*
	 * devuelve la suma de los datos del árbol
	 */
	int suma();
	/*
	 * Devuelve el número de nodos del árbol
	 */
	int numElementos();
	/*
	 * Devuelve el número de enlaces vacíos del árbol, cada nodo tiene dos enlaces,
	 * uno a cada hijo
	 */
	int contarEnlacesVacios();
	/*
	 * Devuelve el número de nodos no hojas del árbol
	 */
	int contarHojas();
	/*
	 * Escribe en el fichero de texto "Datos.txt" todo el contenido del árbol
	 */
	void arbolAFichero();

	~Algoritmos();
};

#endif /* ALGORITMOS_H_ */
