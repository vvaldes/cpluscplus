/*
 * ejemplo1.cpp
 *
 *  Created on: 21 mar. 2020
 *      Author: root
 */


#include "iostream"
#include "stdio.h"
#include "string"
#include "list"
#include "vector"
#include "fstream"

using namespace std;

int funcion(int valor)
{
    valor = valor + 10; //Se le suma 10
    return valor;
}

int funcionPunteros(int* valor)
{
    *valor = *valor + 10; //Se le suma 10 a la posición en memoria
    return *valor;
}

typedef int* AD_Enteros;

void leer(int n, int numeros[])
{
	cout << "Introduce " << n << " elementos " << endl;
	for (int i = 0; i < n; ++i) {
		cin >> numeros[i];
	}
}

float media(int n, const int numeros[])
{
float suma = 0.0;
	for (int i = 0; i < n; ++i) {
		suma += numeros[i];
	}
return suma / float(n);
}

const int MAX_CADENA = 10;
typedef char Cadena[MAX_CADENA];

void copiar_ficheros(const Cadena& salida, const Cadena& entrada)
{
	ifstream f_ent(entrada);

	if (!f_ent) { // error al abrir el fichero de entrada
	} else {
		ofstream f_sal(salida);
		if (! f_sal) { // error al abrir el fichero de salida
		} else {
			char ch;
			f_ent.get(ch);
			while (f_ent && f_sal) { // mientras no haya un error o EOF
				f_sal.put(ch);
				f_ent.get(ch);
			}
			if (!(f_ent.eof() && f_sal.good())) { // error
			}
		}
	}
//f_sal.close(); // no es necesario
//f_ent.close(); // no es necesario
}

template <class TIPO>
inline TIPO
maximo(TIPO x, TIPO y)
{
	return (x > y) ? x : y ;
}
template <class TIPO>
void
intercambio(TIPO& x, TIPO& y)
{
	TIPO aux = x;
	x = y;
	y = aux;
}


int main()
{
    int edades[] = {1,2,9,8,16,32,9,50,36,20,1,87};
    int limite = (sizeof(edades)/sizeof(edades[0]));
    for (int i = 0; i < limite; i++)
    {
            cout<<edades[i]<<endl;
    }

  /*  char titulos[5];
    char autores[5];
    cout << "Por favor ingrese la siguiente información de los Libros: \n";
    for(int i = 0; i < 5; i++)
    {
        cout << "\n******* Libro " << i + 1 <<"********:\n";
        cout << "Titulo: ";
        cin >> titulos[i];
        cout << "Autor: ";
        cin >> autores[i];
    }
    */

 //punteros
    char *apuntador = NULL; //Declaramos un puntero
    //Es recomendable inicializar un puntero en null, para detectar errores fácilmente

    char letra; //Declaramos una variable primitiva

    apuntador = &letra; //Asignamos al apuntador la dirección de memoria de la variable primitiva

    *apuntador = 'x'; //Modificamos la variable a través del apuntador

    cout << letra; //Muestra x por pantalla

    int numero = 10;

        cout << "Antes de funcion " << numero << "\n"; //10

        funcion(numero); //Se pasa por valor

        cout << "Despues de funcion " << numero << "\n"; //10

        cout << "Antes de funcionPunteros " << numero << "\n"; //10

        funcionPunteros(&numero); //Se envía la dirección de memoria y la función resuelve la referencia

        cout << "Despues de funcionPunteros " << numero << "\n"; //20 (10+10)

//punteros a strings
        string* titulos = NULL; //Se inicializa el puntero (inicia en null)
         string* autores = NULL; //Se inicializa el puntero (inicia en null)

         int tamanio ; //Se inicializa la variable

         cout << "Cuantos libros desea ingresar?";

         string entrada;


         getline(cin, entrada); //Se asigna el valor ingresado

         tamanio = stoi(entrada); //Se transforma la entrada en número

         titulos = new string[tamanio]; //Declaramos un arreglo del tamaño ingresado para los titulos
         autores = new string[tamanio]; //Declaramos un arreglo del tamaño ingresado para los autores

         cout << "Por favor ingrese la siguiente información de los Libros: \n";
         for(int i = 0; i < tamanio; i++)
         {
             cout << "\n******* Libro " << i + 1 << "********:\n";
             cout << "Titulo: ";
             //cin >> titulos[i]; //No funciona con espacios
             getline(cin, titulos[i]);
             cout << "Autor: ";
             //cin >> autores[i]; //No funciona con espacios
             getline(cin, autores[i]);
         }

         //visualizamos
         for(int i = 0; i < tamanio; i++)
        	 cout << "\n** Libro:" << titulos[i] << autores[i];

         //Liberamos la memoria de ambos punteros
         delete [] titulos;
         delete [] autores;
         titulos = NULL;
         autores = NULL;

/*
 //vectores iterator list
		  list<int> miLista; //Creamos
		  list<int>::iterator it;

		  for (int i=10; i<=50; i = i+10)
		  {
			  miLista.push_back(i);
		  }
		  //Se agrega un 10 20 30 40 50 a la lista

		  it = miLista.begin(); //Se estabelce el iterador al comienzo de la lista
		  it++; //Movemos el iterador una posición (ahora estamos en 20)

		  //Se inserta un 11 en la posición del 10 11 20 30 40 50
		  miLista.insert (it,11);

		  miLista.insert (it,3,18);
		  //En la actual posición del 20 insertamos un 18 tres veces
		  //10 11 18 18 18 20 30 40 50


		  //Creamos un vector que poseerá dos elementos con valor de 19
		  vector<int> myvector (2,19);

		  //Insertamos ese vector en la lista, enviando los iteradores del propio vector
		  miLista.insert (it,myvector.begin(),myvector.end());

		  //10 11 18 18 18 19 19 20 30 40 50


		  cout << "Mi lista contiene lo siguiente:";

		  for (it=miLista.begin(); it!=miLista.end(); it++)
		  {
			  cout << ' ' << *it; //Se muestra el valor al cual está aùntando el iterador
		  }
*/

        int nelm;

         AD_Enteros numeros; // agregado dinamico
         cout << "Introduce el numero de elementos ";
         cin >> nelm;
         numeros = new int[nelm];
         leer(nelm, numeros);
         cout << "Media: " << media(nelm, numeros) << endl;
         delete [] numeros;

         int x = 4;
         int y = maximo(x, 8);
         intercambio(x, y);

    return 0;
}

