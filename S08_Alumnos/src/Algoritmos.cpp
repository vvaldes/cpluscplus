//============================================================================
// Name        : algoritmos.h
// Author      : Profesores de la asignatura EDI
// Version     : 2019/20
// Copyright   : Your copyright notice
// Description : implementación algoritmos del proyecto
//============================================================================



#include "Algoritmos.h"
int main(){
	Algoritmos a;
}

/****Métodos privados*****/

void Algoritmos::cargarVias() {

	int i;
	string cad[5];
	Via *v;
	ifstream f("Via.csv");
	if (f.is_open()) {
		getline(f, cad[0]); // leer cabecera
		while (!f.eof()) {
			for (i = 0; i < 4; i++)
				getline(f, cad[i], ';');
			getline(f, cad[4]);
			if (!f.eof()) {

				v = new Via(cad[0], cad[1], atof(cad[2].c_str()),
									atoi(cad[3].c_str()), atoi(cad[4].c_str()));

				// Carga las vias leídas del fichero de texto via.csv en la cola
				// simplemente invocamos el método encolar
				colaVias->encolar(v);
			}
		}
		f.close();
	} else
		cout << "ERROR: no existe el fichero vias";


}


/******Métodos públicos****/

Algoritmos::Algoritmos() {
	colaVias= new Cola <Via *>;
	cargarVias();
	run();

	
}


void Algoritmos::run() {
	// método para llamar a los métodos que queremos probar, mostrar, contar ...
	//mostrar();

	cout << "Prueba del contar el nº de elementos de la cola"<<endl;
	cout << "Nº Vías: "<< numElementos()<<endl;
	cout << "Nº Vías: "<< numElementosRecursivo()<<endl;
	if (numElementos() != 1227)
		 cout << "Error al contar el nº de vías iterativo"<< endl;

	if (numElementosRecursivo() != 1227)
			 cout << "Error al contar el nº de vías recursivo"<< endl;

	mostrar();
	mostrarRecursivo(); //Al desencolar y encolar da la vuelta a la cola
	mostrar();

/*
	Via *v = new Via ("CALLE","AAAAA",0,0,0);
	int pos = 3;
	if (pos > 0 && pos < numElementos()){
		insertarEnPos(pos,v);
		mostrar();
	}
	else cout << "Error la posición no cumple la precondición"<< endl;
*/



	Cola<Via *> *c = new Cola<Via *>;
	viasEmpiezanPor("Santa", c);
	cout << "Vías que empiezan por Santa"<< endl;
	mostrar(c);
	cout << endl;
	delete c;

	c = new Cola<Via *>;
	viasEmpiezanPor("Gr", c);
	cout << "Vías que empiezan por Gr"<< endl;
	mostrar(c);
	delete c;

}

void Algoritmos::mostrar() {
	Via * v;
	int cont = 1; // Rol contador, incindica el nº de vías de la cola.

	// utilizamos una cola auxiliar para no perder los datos de la cola al mostrarlos
	Cola <Via * > *cAux = new Cola <Via *>;

	// el recorrido de una cola provoca que se vacie, el bucle
	// utilizado es mientra las cola no esté vacía

	while (! colaVias->vacia()){
		colaVias->primero(v);   // obtengo el dato que está al frente de la cola

		cout << cont<<" ";
		cont ++;
		v->mostrar();

		colaVias->desencolar(); // desencolo el dato procesado, con el objetivo de
		                        // avanzar en la cola
		                        // desencolar elimina el nodo de la cola, no el dato.

		cAux->encolar(v);       // para no perder el dato, lo meto en la cola auxiliar

	}

    // una vez terminado este bucle la cola origina, nuestro atributo, queda vacía
	// todos los datos están en la auxiliar, por lo tanto los tengo que pasar
	// de la cola auxiliar a la original
	while (!cAux->vacia()){
		cAux->primero(v);
		colaVias -> encolar(v);
		cAux->desencolar();
	}
	// Al terminar este bucle la cola auxiliar está vacía y todos los datos
	// estan en la original, por lo tanto elimino la cola auxiliar
    delete cAux;
}


void Algoritmos::mostrar(Cola<Via*> *c) {
	// TODO método para mostrar la cola de forma recursiva sin
	// peder los datos
	// Método recursivo para contar el nº de vías de la cola
	Via *v;
	int cont = 1; // Rol contador, incindica el nº de vías de la cola.

	if (!c->vacia()){
		c->primero(v);
		c->desencolar();

		//Muestra información via
		cout << cont<<" ";
		v->mostrar();

		mostrar(c); 		   // llamada recursiva
		c->encolar(v);         // cuando termina la recusividad se encolan
		                       // los datos ¿En qué orden quedan?
	}else
		return;
}

void Algoritmos::mostrarRecursivo() {
	if (!colaVias->vacia())
		mostrar(colaVias);
}

int Algoritmos::numElementos() {
    // TODO método para contar el nº de elementos de la cola
	// de forma iterativa

	Via * v;
	int cont = 0; // Rol contador, incindica el nº de vías de la cola.

	// utilizamos una cola auxiliar para no perder los datos de la cola al mostrarlos
	Cola <Via * > *cAux = new Cola <Via *>;

	// el recorrido de una cola provoca que se vacie, el bucle
	// utilizado es mientra las cola no esté vacía

	while (! colaVias->vacia()){
		colaVias->primero(v);   // obtengo el dato que está al frente de la cola
		cont ++;
		colaVias->desencolar(); // desencolo el dato procesado, con el objetivo de
		                        // avanzar en la cola
		                        // desencolar elimina el nodo de la cola, no el dato.

		cAux->encolar(v);       // para no perder el dato, lo meto en la cola auxiliar

	}

    // una vez terminado este bucle la cola origina, nuestro atributo, queda vacía
	// todos los datos están en la auxiliar, por lo tanto los tengo que pasar
	// de la cola auxiliar a la original
	while (!cAux->vacia()){
		cAux->primero(v);
		colaVias -> encolar(v);
		cAux->desencolar();
	}
	// Al terminar este bucle la cola auxiliar está vacía y todos los datos
	// estan en la original, por lo tanto elimino la cola auxiliar
    delete cAux;

	return cont;
}


int Algoritmos::contar(Cola<Via*> *c) {

	// Método recursivo para contar el nº de vías de la cola
	Via *v;
	int cont;
	if (!c->vacia()){
		c->primero(v);
		c->desencolar();
		cont = 1 + contar(c);  // llamada recursiva
		c->encolar(v);         // cuando termina la recusividad se encolan
		                       // los datos ¿En qué orden quedan?
	}else cont = 0;

	return cont;
}

int Algoritmos::numElementosRecursivo() {
	// método recursivo que no depende la ED
	// tan solo sirve para que se pueda invocar desde fuera de la clase.
	int cont = 0;
	if (!colaVias->vacia())
		cont =  contar(colaVias);
	return cont;
}


void Algoritmos::insertarEnPos(int pos, Via *v) {
	// TODO hacer
}



void Algoritmos::viasEmpiezanPor(string raiz, Cola<Via*> *&cVias) {

 // TODO hacer
	// Método recursivo para buscar las vias que coinciden con raiz
	Via *v;
	int i;

	if (!colaVias->vacia()){
		colaVias->primero(v);
		colaVias->desencolar();

		i=v->getNombre().find(raiz,0);
		if (i==0) //desde el principio
			cVias->encolar(v);

		//Muestra información via
		//cout << cont<<" ";
		//v->mostrar();

		viasEmpiezanPor(raiz,cVias); 		   // llamada recursiva
		colaVias->encolar(v);         // cuando termina la recusividad se encolan
		                       // los datos ¿En qué orden quedan?
	}else
		return;

}



Algoritmos::~Algoritmos() {

	// recorre la cola, libera los recurso asociados a los datos, vías, y
	// a los nodos de la cola donde se coleccionan
	Via *v;
	while (!colaVias->vacia()){
		colaVias->primero(v);
		delete v;
		colaVias->desencolar();
	}
	delete colaVias;

}




