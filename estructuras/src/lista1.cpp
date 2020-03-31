/*
 * lista1.cpp
 *
 *  Created on: 23 mar. 2020
 *      Author: root
 */


#include <iostream>
//#include "CCadena.h"
using namespace std;

#define ASCENDENTE 1
#define DESCENDENTE 0

template<class TIPO> class lista;

template<class TIPO>
class nodo {
   public:
    nodo(TIPO v, nodo<TIPO> *sig = NULL, nodo<TIPO> *ant = NULL) :
       valor(v), siguiente(sig), anterior(ant) {}

   private:
    TIPO valor;
    nodo<TIPO> *siguiente;
    nodo<TIPO> *anterior;

   friend class lista<TIPO>;
};

template<class TIPO>
class lista {
   public:
    lista() : plista(NULL) {}
    ~lista();

    void Insertar(TIPO v);
    void Borrar(TIPO v);
    bool ListaVacia() { return plista == NULL; }
    void Mostrar(int);
    void Siguiente();
    void Anterior();
    void Primero();
    void Ultimo();
    bool Actual() { return plista != NULL; }
    TIPO ValorActual() { return plista->valor; }

   private:
    nodo<TIPO> *plista;
};

template<class TIPO>
lista<TIPO>::~lista() {
   nodo<TIPO> *aux;

   Primero();
   while(plista) {
      aux = plista;
      plista = plista->siguiente;
      delete aux;
   }
}

template<class TIPO>
void lista<TIPO>::Insertar(TIPO v) {
   nodo<TIPO> *nuevo;

   Primero();
   // Si la lista está vacía
   if(ListaVacia() || plista->valor > v) {
      // Asignamos a lista un nuevo nodo de valor v y
      // cuyo siguiente elemento es la lista actual
      nuevo = new nodo<TIPO>(v, plista);
      if(!plista) plista = nuevo;
      else plista->anterior = nuevo;
   }
   else {
      // Buscar el nodo de valor menor a v
      // Avanzamos hasta el último elemento o hasta que el siguiente tenga
      // un valor mayor que v
      while(plista->siguiente && plista->siguiente->valor <= v) Siguiente();
      // Creamos un nuevo nodo después del nodo actual
      nuevo = new nodo<TIPO>(v, plista->siguiente, plista);
      plista->siguiente = nuevo;
      if(nuevo->siguiente) nuevo->siguiente->anterior = nuevo;
   }
}

template<class TIPO>
void lista<TIPO>::Borrar(TIPO v) {
   nodo<TIPO> *pnodo;

   pnodo = plista;
   while(pnodo && pnodo->valor < v) pnodo = pnodo->siguiente;
   while(pnodo && pnodo->valor > v) pnodo = pnodo->anterior;

   if(!pnodo || pnodo->valor != v) return;
   // Borrar el nodo

   if(pnodo->anterior) // no es el primer elemento
      pnodo->anterior->siguiente = pnodo->siguiente;
   if(pnodo->siguiente) // no el el último nodo
      pnodo->siguiente->anterior = pnodo->anterior;
}

template<class TIPO>
void lista<TIPO>::Mostrar(int orden) {
   nodo<TIPO> *pnodo;
   if(orden == ASCENDENTE) {
      Primero();
      pnodo = plista;
      while(pnodo) {
         cout << pnodo->valor << "-> ";
         pnodo = pnodo->siguiente;
      }
   }
   else {
      Ultimo();
      pnodo = plista;
      while(pnodo) {
         cout << pnodo->valor << "-> ";
         pnodo = pnodo->anterior;
      }
   }
   cout << endl;
}

template<class TIPO>
void lista<TIPO>::Siguiente() {
   if(plista) plista = plista->siguiente;
}

template<class TIPO>
void lista<TIPO>::Anterior() {
   if(plista) plista = plista->anterior;
}

template<class TIPO>
void lista<TIPO>::Primero() {
   while(plista && plista->anterior) plista = plista->anterior;
}

template<class TIPO>
void lista<TIPO>::Ultimo() {
   while(plista && plista->siguiente) plista = plista->siguiente;
}

int main() {
   lista<int> iLista;
   lista<float> fLista;
   lista<double> dLista;
   lista<char> cLista;
//   lista<Cadena> cadLista;

   // Prueba con <int>
   iLista.Insertar(20);
   iLista.Insertar(10);
   iLista.Insertar(40);
   iLista.Insertar(30);

   iLista.Mostrar(ASCENDENTE);
   iLista.Mostrar(DESCENDENTE);

   iLista.Primero();
   cout << "Primero: " << iLista.ValorActual() << endl;

   iLista.Ultimo();
   cout << "Ultimo: " << iLista.ValorActual() << endl;

   iLista.Borrar(10);
   iLista.Borrar(15);
   iLista.Borrar(45);
   iLista.Borrar(40);

   iLista.Mostrar(ASCENDENTE);
   iLista.Mostrar(DESCENDENTE);

   // Prueba con <float>
   fLista.Insertar(20.01);
   fLista.Insertar(10.02);
   fLista.Insertar(40.03);
   fLista.Insertar(30.04);

   fLista.Mostrar(ASCENDENTE);
   fLista.Mostrar(DESCENDENTE);

   fLista.Primero();
   cout << "Primero: " << fLista.ValorActual() << endl;

   fLista.Ultimo();
   cout << "Ultimo: " << fLista.ValorActual() << endl;

   fLista.Borrar(10.02);
   fLista.Borrar(15.05);
   fLista.Borrar(45.06);
   fLista.Borrar(40.03);

   fLista.Mostrar(ASCENDENTE);
   fLista.Mostrar(DESCENDENTE);

   // Prueba con <double>
   dLista.Insertar(0.0020);
   dLista.Insertar(0.0010);
   dLista.Insertar(0.0040);
   dLista.Insertar(0.0030);

   dLista.Mostrar(ASCENDENTE);
   dLista.Mostrar(DESCENDENTE);

   dLista.Primero();
   cout << "Primero: " << dLista.ValorActual() << endl;

   dLista.Ultimo();
   cout << "Ultimo: " << dLista.ValorActual() << endl;

   dLista.Borrar(0.0010);
   dLista.Borrar(0.0015);
   dLista.Borrar(0.0045);
   dLista.Borrar(0.0040);

   dLista.Mostrar(ASCENDENTE);
   dLista.Mostrar(DESCENDENTE);

   // Prueba con <char>
   cLista.Insertar('x');
   cLista.Insertar('y');
   cLista.Insertar('a');
   cLista.Insertar('b');

   cLista.Mostrar(ASCENDENTE);
   cLista.Mostrar(DESCENDENTE);

   cLista.Primero();
   cout << "Primero: " << cLista.ValorActual() << endl;

   cLista.Ultimo();
   cout << "Ultimo: " << cLista.ValorActual() << endl;

   cLista.Borrar('y');
   cLista.Borrar('m');
   cLista.Borrar('n');
   cLista.Borrar('a');

   cLista.Mostrar(ASCENDENTE);
   cLista.Mostrar(DESCENDENTE);

   // Prueba con <Cadena>
 /*  cadLista.Insertar("Hola");
   cadLista.Insertar("seguimos");
   cadLista.Insertar("estando");
   cadLista.Insertar("aquí");

   cadLista.Mostrar(ASCENDENTE);
   cadLista.Mostrar(DESCENDENTE);

   cadLista.Primero();
   cout << "Primero: " << cadLista.ValorActual() << endl;

   cadLista.Ultimo();
   cout << "Ultimo: " << cadLista.ValorActual() << endl;

   cadLista.Borrar("seguimos");
   cadLista.Borrar("adios");
   cadLista.Borrar("feos");
   cadLista.Borrar("estando");

   cadLista.Mostrar(ASCENDENTE);
   cadLista.Mostrar(DESCENDENTE);
*/
   cin.get();
   return 0;
}

