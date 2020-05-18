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

	ListaPI<bar> *baresOrdenada; //Lista ordenada de bares por capacidad

	//Bares con un determinado tipo comida
	//Cola <bar> barTipo[];
	Cola <bar> barTipo;    //Cola con los bares que tienen ese tipo de comida
	ListaPI <string> strTipos; //Tipos de comida existentes
	ListaPI <string> strDistritos; //Distritos que existen

	// carga los datos desde los ficheros de texto
	void cargarDatos();
    // ejecuta todos los algoritmos del proyecto
	void run ();

	void parte1();  //olgoritmos parte1
	void parte2();  //olgoritmos parte2

	void buscarBar(string calle);						//Busca bar a partir del nombre
	void buscarEmpiezaBar(string calle);				//Busca los bares que empiezan por ese nombre
	void escribirCalleBar(string strTipo,string calle);	//Escribe a partir del tipo comida y nombre
	void arbolAFicheroArbol (BSTree<string> *bts, ofstream &f);	//Escribe fichero a partir del arbol invertido
	void arbolAFicheroNombre(BSTree<string> *bts, ofstream &f,string strNombre="",bool bEntero=false); //Escribe fichero a partir del arbol orden inverso
	void arbolAFicheroEmpiezaNombre(BSTree<string> *bts, string strNombre="",bool bEntero=false); //Escribe fichero con los bares que empiezan por nombre
	void arbolAFicheroCapacidad(BSTree<string> *bts,ofstream &f,string strtipo,int capacidad ); //Escribe a partir del tipo comida y nombre del bar
	void escribirBar(string strBar, ofstream &f,string strCalle="",bool bEntero=false);		//Escribe a partir del nombre del bar y la calle
	void escribirBaresLista(ofstream &f);				//Escribe lista de los bares
	void escribirBarTipoCapacidad(string strTipo,int capacidad);	//Escribe bar a partir tipo comida y capacidad
	bar *nodoBar(string strNombre, string tipo,int capacidad);		//Retorna puntero a un barrio a partir nombre y tipo
	void barrioMasBares();									//Escribe el barrio que tiene más bares
	int baresVias(ListaPI<via> *pVia);						//Retorna el nº de bares que tiene 1 via
	void baresBarrios(barrio *pBar,ofstream &f);			//Escribe los bares de 1 barrio, recorriendo la lista de vias
	void anadirBarOrdenado(string strNombre);				//Añade bar ordenado a nº de capacidad
	/*
	 * Cuenta el número de nodos del árbol
	 */
	int numElementos(BSTree<string> *bst);					//Cuenta el nº de nodos del arbol
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
