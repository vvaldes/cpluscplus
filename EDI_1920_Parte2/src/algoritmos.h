//============================================================================
// Name        : algoritmos.h
// Author      : Profesores de la asignatura EDI
// Version     : 2019/20
// Copyright   : Your copyright notice
// Description : clase para realizar algoritmos del proyecto
//============================================================================


#ifndef ALGORITMOS_H_
#define ALGORITMOS_H_

#include "barrio.h"
#include "bar.h"
#include "via.h"
#include "listapi.h"
#include "cola.h"
#include "bstree.h"


class Algoritmos {

private:
    
    // TODO atributo, puntero a la lista de barrios y bares
	barrio bBarrio,bTemp;
	via    vVia,bVTemp;
	bar    bBar,bBarTemp;

	//Listas
	ListaPI<barrio> barrios;
	ListaPI<via> vias;
	ListaPI<bar> bares;

	//Arbol con los bares
	BSTree<string> *bBares;

	ListaPI<bar> *baresOrdenada;

	//Bares con un determinado tipo comida
	//Cola <bar> barTipo[];
	Cola <bar> barTipo;    //Cola con los bares que tienen ese tipo de comida
	ListaPI <string> strTipos; //Tipos de comida existentes
	ListaPI <string> strDistritos; //Distritos que existen

	// carga los datos desde los ficheros de texto
	void cargarDatos();
    // ejecuta todos los algoritmos del proyecto
	void run ();

	void buscarBar(string calle);
	void buscarEmpiezaBar(string calle);
	void escribirCalleBar(string strTipo,string calle);
	void arbolAFicheroArbol (BSTree<string> *bts, ofstream &f);
	void arbolAFicheroNombre(BSTree<string> *bts, ofstream &f,string strNombre="",bool bEntero=false);
	void arbolAFicheroEmpiezaNombre(BSTree<string> *bts, string strNombre="",bool bEntero=false);
	void escribirBar(string strBar, ofstream &f,string strCalle="",bool bEntero=false);
	void escribirBaresLista(ofstream &f);

	void anadirBarOrdenado(string strNombre);
	/*
	 * Cuenta el número de nodos del árbol
	 */
	int numElementos(BSTree<string> *bst);
public:

	 Algoritmos();

	void arbolAFichero();

     // Algoritmo  1 Parte 1, mostrar vías de un barrio:
	 // Algoritmo  2 Parte 1:
	 // Algoritmo  3 Parte 1:
	 // Algoritmo  4 Parte 1:

	 ~Algoritmos();
    
};

#endif /* ALGORITMOS_H_ */
