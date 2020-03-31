
#include <iostream>
#include "ccadena.h"

using namespace std;

template<class TIPO> class pila;

template<class TIPO>
class nodo {
   public:
      nodo(TIPO v, nodo<TIPO> *sig = NULL) {
         valor = v;
         siguiente = sig;
      }

   private:
      TIPO valor;
      nodo<TIPO> *siguiente;

      friend class pila<TIPO>;
};

template<class TIPO>
class pila {
   public:
      pila() : ultimo(NULL) {}
      ~pila();

      void Push(TIPO v);
      TIPO Pop();

   private:
      nodo<TIPO> *ultimo;
};

template<class TIPO>
pila<TIPO>::~pila() {
   while(ultimo) Pop();
}

template<class TIPO>
void pila<TIPO>::Push(TIPO v) {
   nodo<TIPO> *nuevo;

   /* Crear un nodo nuevo */
   nuevo = new nodo<TIPO>(v, ultimo);
   /* Ahora, el comienzo de nuestra pila es en nuevo nodo */
   ultimo = nuevo;
}

template<class TIPO>
TIPO pila<TIPO>::Pop() {
    nodo<TIPO> *Nodo; /* variable auxiliar para manipular nodo */
    TIPO v;      /* variable auxiliar para retorno */

    if(!ultimo) return 0; /* Si no hay nodos en la pila retornamos 0 */
    /* Nodo apunta al primer elemento de la pila */
    Nodo = ultimo;
    /* Asignamos a pila toda la pila menos el primer elemento */
    ultimo = Nodo->siguiente;
    /* Guardamos el valor de retorno */
    v = Nodo->valor;
    /* Borrar el nodo */
    delete Nodo;
    return v;
}
/*
int main() {
   pila<int> iPila;
   pila<float> fPila;
   pila<double> dPila;
   pila<char> cPila;
   pila<Cadena> sPila;

   // Prueba con <int>
   iPila.Push(20);
   iPila.Push(10);
   cout << iPila.Pop() << ",";
   iPila.Push(40);
   iPila.Push(30);

   cout << iPila.Pop() << ",";
   cout << iPila.Pop() << ",";
   iPila.Push(90);
   cout << iPila.Pop() << ",";
   cout << iPila.Pop() << endl;


   // Prueba con <float>
   fPila.Push(20.01);
   fPila.Push(10.02);
   cout << fPila.Pop() << ",";
   fPila.Push(40.03);
   fPila.Push(30.04);

   cout << fPila.Pop() << ",";
   cout << fPila.Pop() << ",";
   fPila.Push(90.05);
   cout << fPila.Pop() << ",";
   cout << fPila.Pop() << endl;

   // Prueba con <double>
   dPila.Push(0.0020);
   dPila.Push(0.0010);
   cout << dPila.Pop() << ",";
   dPila.Push(0.0040);
   dPila.Push(0.0030);

   cout << dPila.Pop() << ",";
   cout << dPila.Pop() << ",";
   dPila.Push(0.0090);
   cout << dPila.Pop() << ",";
   cout << dPila.Pop() << endl;

   // Prueba con <Cadena>
   cPila.Push('x');
   cPila.Push('y');
   cout << cPila.Pop() << ",";
   cPila.Push('a');
   cPila.Push('b');

   cout << cPila.Pop() << ",";
   cout << cPila.Pop() << ",";
   cPila.Push('m');
   cout << cPila.Pop() << ",";
   cout << cPila.Pop() << endl;

   // Prueba con <char *>
   sPila.Push("Hola");
   sPila.Push("somos");
   cout << sPila.Pop() << ",";
   sPila.Push("programadores");
   sPila.Push("buenos");

   cout << sPila.Pop() << ",";
   cout << sPila.Pop() << ",";
   sPila.Push("!!!!");
   cout << sPila.Pop() << ",";
   cout << sPila.Pop() << endl;

   return 0;
}
*/
