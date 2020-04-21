//============================================================================
// Name        : algoritmos.cpp
// Author      : Profesores de la asignatura EDI
// Version     : 2019/20
// Copyright   : Your copyright notice
// Description : Implementación de los algoritmos del proyecto
//============================================================================

#include "Algoritmos.h"

int main() {

	Algoritmos a;

	return 0;
}

Algoritmos::Algoritmos() {

	pBarrios = new Pila<Barrio *> ();
	cargarBarrios();
	run();
}
void Algoritmos::run() {
	Barrio * b = nullptr;
	mostrar();
    cout <<"____________ nº de elementos _________________"<<endl;
	cout <<"El nº de barrios son 78 y nos da "<< numElementos()<<endl;

	cout <<"____________ barrio del fondo _________________"<<endl;
	getFondo (b);
	cout << "El Barrio del fondo es Argentina y nos da:" <<endl;
	b->mostrar();
//	mostrar();

	cout <<"____________ Insertar barrio en el fondo _________________"<<endl;
	b = new Barrio ("XXXXXXX", 23.43, 12, 10, "Centro");
	insertarFondo(b);
	mostrar();

	cout <<"____________ barrio del fondo _________________"<<endl;
	getFondo (b);
	cout << "El Barrio del fondo es XXXXXXX y nos da:" <<endl;
	b->mostrar();
	cout <<"____________ barrio de un distrito _________________"<<endl;

	ListaPI<Barrio *> *lista = new ListaPI<Barrio *>;
	//string cadena="Centro";
	getListaBarrios("Centro",lista);
	mostrar(lista);// mostrar la lista devuelta
	delete lista;// eliminar la lista devuelta

	cout <<"____________ fichero barrio de un distrito _________________"<<endl;
	lista = new ListaPI<Barrio *>;
	escribirFichero("Centro",lista);
	delete lista;// eliminar la lista devuelta


	lista = new ListaPI<Barrio *>;
	escribirFichero("Sur",lista);
	delete lista;// eliminar la lista devuelta

	lista = new ListaPI<Barrio *>;
	escribirFichero("Norte",lista);
	delete lista;// eliminar la lista devuelta

	lista = new ListaPI<Barrio *>;
	escribirFichero("Oeste",lista);
	delete lista;// eliminar la lista devuelta

}


/****Métodos privados*****/

void Algoritmos::getListaBarrios(string nombreDistrito, ListaPI <Barrio *> *pB) {
	Barrio *b = NULL;

		if (!pBarrios->vacia()) {
			pBarrios->cima(b);

			pBarrios->desapilar();

			if (b->getDistrito()==nombreDistrito)  //Si igual distrito inserto ordenado en la lista de entrada
				insertarOrdenado(b,pB);

			getListaBarrios(nombreDistrito,pB); // llamada recursiva

			pBarrios->apilar(b); // apilo los datos para no perder la pila
		}
}
/*
void Algoritmos::getListaBarrios(string nombreDistrito, ListaPI <Barrio *> *pB) {
	Barrio *b = NULL;
	ifstream fEnt;
	string linea, barrio, distrito, area, perimetro, codigo;
	fEnt.open("Barrio.csv");
	if (fEnt.is_open()) {
		getline(fEnt, linea); // leo la cabecera
		//rdfs_label;om_area;om_perimetro;om_tieneCodigoBarrio;om_perteneceADistrito
		while (!fEnt.eof()) {
			getline(fEnt, barrio, ';');
			if (!fEnt.eof()) {
				getline(fEnt, area, ';');
				getline(fEnt, perimetro, ';');
				getline(fEnt, codigo, ';');
				getline(fEnt, distrito);
				if (distrito==nombreDistrito) {
					b = new Barrio(barrio, atof(area.c_str()),
						atof(perimetro.c_str()), atoi(codigo.c_str()),
						distrito);
					insertarOrdenado(b,pB);
				}

			}
		}

	} else
		cout << "ERROR: fichero Barrio.csv no encontrado" << endl;
}
*/

void Algoritmos::insertarOrdenado(Barrio *bb,ListaPI <Barrio *> *pB) {
	Barrio *b = NULL;
	bool bSalir=false;

	if ((bb!=NULL) and (pB!=NULL)) {
		pB->moverInicio();
		pB->consultar(b);
		string nombreBarrio=bb->getNombre();
		while((pB->finLista()==false) && (bSalir==false)) {
			string nombreBarriolista=b->getNombre();
			if (nombreBarriolista>nombreBarrio)
					bSalir=true;
			else {
				pB->avanzar();
				pB->consultar(b);
			}
		}
		//Insertamos via en la lista vias
		pB->insertar(bb);
	}
}

void Algoritmos::recorrerLista(ofstream *fEnt,ListaPI <Barrio *> *pB){
	Barrio *b = NULL;
	string cadena,nombre,distrito;

	if (pB->finLista()==false) {
		pB->consultar(b);
		nombre=b->getNombre();
		distrito=b->getDistrito();
		cadena=nombre + " " + distrito + "\n";

		//Escribimos
		fEnt->write(cadena.c_str(),cadena.length());
		//fEnt->out<<nombre <<" "<<distrito <<"\n";

		//Avanzamos y llamada recursiva
		pB->avanzar();
		recorrerLista(fEnt,pB);
	}
}

void Algoritmos::escribirFichero(string nombreDistrito,ListaPI <Barrio *> *pB) {
	ofstream *fEnt;

	//Cargamos lista
	getListaBarrios(nombreDistrito,pB);

	//Escribimos en fichero
	fEnt=new ofstream();
	fEnt->open(nombreDistrito,std::ios::out);

	if (fEnt->is_open()) {
		pB->moverInicio();
		recorrerLista(fEnt,pB);
	}
	fEnt->close();
	delete fEnt;
}

void Algoritmos::cargarBarrios(){
	Barrio *b;

	ifstream fEnt;
	string linea, barrio, distrito, area, perimetro, codigo;
	fEnt.open("Barrio.csv");
	if (fEnt.is_open()) {
		getline(fEnt, linea); // leo la cabecera
		//rdfs_label;om_area;om_perimetro;om_tieneCodigoBarrio;om_perteneceADistrito
		while (!fEnt.eof()) {
			getline(fEnt, barrio, ';');
			if (!fEnt.eof()) {
				getline(fEnt, area, ';');
				getline(fEnt, perimetro, ';');
				getline(fEnt, codigo, ';');
				getline(fEnt, distrito);
				b = new Barrio(barrio, atof(area.c_str()),
						atof(perimetro.c_str()), atoi(codigo.c_str()),
						distrito);
				insertar(b);

			}
		}

	} else
		cout << "ERROR: fichero Barrio.csv no encontrado" << endl;
}


void Algoritmos::mostrar(ListaPI <Barrio *> *pB) {
	Barrio *b;

	for (pB->moverInicio();!pB->finLista();pB->avanzar()) {
		pB->consultar(b);
		b->mostrar();
	}
}

void Algoritmos::insertar(Barrio *b) {
	pBarrios->apilar (b);

}


void Algoritmos::insertarFondo(Pila<Barrio*> *pB, Barrio *b) {
	Barrio *bb;
	if (!pB->vacia()) {
			pB->cima(bb);
			pB->desapilar();

			insertarFondo(pB,b);

			pB->apilar(bb);
	} else  //si pila vacia inserto
		pB->apilar(b);

}


void Algoritmos::insertarFondo(Barrio *b){
	insertarFondo(pBarrios, b);

}

void Algoritmos::mostrar (Pila <Barrio *> *pB){
	Barrio *b = NULL;

		if (!pB->vacia()) {
			pB->cima(b);
			// donde ponemos en mostrar el barrio
			// opción 1
			b->mostrar();
			pB->desapilar();

			mostrar(pB); // llamada recursiva
			// opcion 2
			//b->mostrar();
			pB->apilar(b); // apilo los datos para no perder la pila
		}
}

void Algoritmos::mostrar(){
	if (!pBarrios->vacia())
		mostrar(pBarrios);

}

int Algoritmos::numElementos(Pila<Barrio*> *pB) {
	Barrio *b = NULL;
	int cont = 0;
	if (!pB->vacia()) {
		pB->cima(b);
		pB->desapilar();

		cont = 1 + numElementos(pB); // llamada recursiva

		pB->apilar(b);

	}
	return cont;
}



int Algoritmos::numElementos() {
	int total = 0;
	if (!pBarrios->vacia())
		total = numElementos(pBarrios);
	return total;
}

void Algoritmos::getFondo(Pila<Barrio*> *pB, Barrio *&b) {
	Barrio *bb = NULL;

	if (!pB->vacia()) {
			pB->cima(b);
			bb=b;
			pB->desapilar();

			//b->mostrar();

			getFondo(pB,b);

			pB->apilar(bb);
	}
}

void Algoritmos::getFondo(Barrio *&b) {

	getFondo(pBarrios,b);
}





Algoritmos::~Algoritmos() {
	Barrio *b;

	if (pBarrios != NULL) {

		while (!pBarrios->vacia()) {
			pBarrios->cima(b);
			pBarrios->desapilar();
			delete b;
		}
		delete pBarrios;

	}
}


