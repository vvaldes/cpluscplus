//============================================================================
// Name        : algoritmos.cpp
// Author      : Profesores de la asignatura EDI
// Version     : 2019/20
// Copyright   : Your copyright notice
// Description : Implementación de los algoritmos del proyecto
//============================================================================

#include "Algoritmos.h"
#include <iostream>
#include <fstream>
using namespace std;
int main(){
	Algoritmos a;
}
void Algoritmos::run() {

	insertar (8);
	insertar (3);
	insertar (1);
	insertar (6);
	insertar (4);
	insertar (7);
	insertar (10);
	insertar (14);
	insertar (13);

	recorridoInOrden  (); // Salida esperada: 1 3 4 6 7 8 10 13 14
	recorridoPreOrden (); // Salida esperada: 8 3 1 6 4 7 10 14 13
	recorridoPostOrden(); // Salida esperada: 1 4 7 6 3 13 14 10 8



    cout <<endl;

	cout << "El numero de nodos es 9 y nos da: " << numElementos() << endl;
	cout << "La suma de nodos es: 66  y nos da: " << suma() << endl;
	cout << "El numero de enlaces vacios es: 10 y nos da " << contarEnlacesVacios() << endl;

	cout << "El numero de hojas es: 4 y nos da " << contarHojas() << endl;




	arbolAFichero();

}


Algoritmos::Algoritmos() {

	abb = new BSTree<int> ();
	run();

}


/*    METODOS PRIVADOS    */

void Algoritmos::inOrden (BSTree<int> *bst) {

    BSTree<int> *aux;

    if (! bst->empty()) {

    	aux = bst->left();
        if (aux != NULL) {
            inOrden(aux);
        }

        cout << bst->root() << " ";// tratamiento de la raiz

        aux = bst->right();
        if (aux != NULL) {
            inOrden(aux);
        }

    }
}


void Algoritmos::preOrden (BSTree<int> *bst) {

    BSTree<int> *aux;

    if (! bst->empty()) {

		cout << bst->root() << " ";// tratamiento de la raiz

    	aux = bst->left();   // Tratamiento arbol izquierda
        if (aux != NULL) {
            preOrden(aux);
        }


        aux = bst->right();    // Tratamiento arbol derecha
        if (aux != NULL) {
            preOrden(aux);
        }


    }

}


void Algoritmos::postOrden (BSTree<int> *bst) {
    BSTree<int> *aux;

    if (! bst->empty()) {

    	aux = bst->left();   // Tratamiento arbol izquierda
        if (aux != NULL) {
            postOrden(aux);
        }


        aux = bst->right();    // Tratamiento arbol derecha
        if (aux != NULL) {
            postOrden(aux);
        }

		cout << bst->root() << " ";// tratamiento de la raiz

    }

}


/*    IMPLEMENTACION    */



void  Algoritmos::insertar (int num) {
	abb->insert(num);
}


void Algoritmos::recorridoInOrden () {

    if (! abb->empty()) {
    	cout << endl << "Recorrido IN orden." << endl;
    	this->inOrden(abb);
    }
}


void Algoritmos::recorridoPreOrden () {

    if (! abb->empty()) {
    	cout << endl << "Recorrido PRE orden." << endl;
    	this->preOrden(abb);
    }
}


void Algoritmos::recorridoPostOrden () {

    if (! abb->empty()) {
    	cout << endl << "Recorrido POST orden." << endl;
    	this->postOrden(abb);
    }
}



int Algoritmos::numElementos(BSTree<int> *bst) {


	int cuantos = 0;

	if (bst !=NULL) {
		cuantos = 1 + numElementos(bst->left()) + numElementos (bst->right());

	}
	return cuantos;

}

int Algoritmos::numElementos() {

	int n = 0;

	if (!abb->empty()) {

		n = this->numElementos(abb);
	}

	return n;

}


/********************************************
 * ******** suma los elementos del árbol
 **********************************************/

int Algoritmos::suma(BSTree<int> *bst) {


	int total = 0;

	if (bst !=NULL) {
		total =  bst->root() + suma(bst->left()) + suma (bst->right());

	}
	return total;


}

int Algoritmos::suma() {
	int n = 0;

	if (!abb->empty()) {

		n = this->suma(abb);
	}

	return n;



}





/********************************************************
 **************  Cuenta el número de enlaces vacios
 ******************************************************/
int Algoritmos::contarEnlacesVacios(BSTree<int> *bst) {


	int cuantos = 0;

	if (bst !=NULL) {
		 cuantos=contarEnlacesVacios(bst->left()) + contarEnlacesVacios(bst->right());
		
	} else
	{
		cuantos +=1;
	}
	
	return cuantos;


}

int Algoritmos::contarEnlacesVacios() {
	int n = 0;

	if (!abb->empty()) {

		n = this->contarEnlacesVacios(abb);
	}

	return n;



}


/************************************************
 * ********Cuenta el número de hojas
 ************************************************/

int Algoritmos::contarHojas(BSTree<int> *bst) {

	if (bst ==NULL) 
		return 0;
	if ((bst->left()==NULL) && (bst->right()==NULL))
		 return 1;
	else
		return contarHojas(bst->left()) + contarHojas(bst->right());
}


int Algoritmos::contarHojas() {
	int n = 0;

	if (!abb->empty()) {

		n = this->contarHojas(abb);
	}

	return n;

}


void Algoritmos::arbolAFichero(BSTree<int> *bts, ofstream &f) {
    BSTree<int> *aux;

    if (! bts->empty()) {

    	aux = bts->left();
        if (aux != NULL) {
            arbolAFichero(aux,f);
        }

        f << bts->root() << " ";// tratamiento de la raiz

        aux = bts->right();
        if (aux != NULL) {
            arbolAFichero(aux,f);
        }

    }
}

void Algoritmos::arbolAFichero() {

ofstream fichero("Datos.txt");

	if (!fichero.is_open()) 
			cout<<"El fichero Datos.txt, no se puede abrir"<<endl;
	else
		if (!abb->empty()) {
			arbolAFichero(abb,fichero);
			fichero.close();	
		}

}

Algoritmos::~Algoritmos() {
	delete abb;

}

