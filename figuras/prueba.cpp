/*
 * prueba.cpp
 *
 *  Created on: 22 mar. 2020
 *      Author: root
 */

#include "vector.h"
#include "figuras.h"
#include <iostream>


enum Opciones {
	FIN,
	Crear_Rectangulo,
	Crear_Cuadrado,
	Crear_Triangulo,
	Mover_Figura,
	Destruir_Figura
};

Opciones
menu()
{
	int op;
	cout << "0.- Fin" << endl;

	cout << "1.- Crear Rectangulo" << endl;
	cout << "2.- Crear Cuadrado" << endl;
	cout << "3.- Crear Triangulo" << endl;
	cout << "4.- Mover Figura" << endl;
	cout << "5.- Destruir Figura" << endl;
	cout << endl;
	cout << "Opcion ? " ;
	do {
		cin >> op;
	while (! cin) {
		cin.clear();
		cin.ignore(3000, '\n');
		cin >> op;
	}

	} while ((op < FIN)||(op > Destruir_Figura));
	return Opciones(op);
	}


	typedef Vector<Figura, 32> v_fig_32;

void dibujar_figuras(const v_fig_32& vect)
	{
	for (unsigned i = 0; i < vect.size(); ++i) {
		cout << i << ".- " ;
		cout << vect[i] ; // vect[i].dibujar(cout);
	}
}


int main()
{
try {
	Opciones opcion;
	v_fig_32 vect;
	do {
		try {
			int base, altura, x, y;
			opcion = menu();
			switch (opcion) {
			case Crear_Rectangulo:
				cout << "Introduce base y altura: " ;
				cin >> base >> altura ;
				cout << "Introduce x e y: " ;
				cin >> x >> y ;
				vect.anadir(Rectangulo(base, altura, x, y));
				break;

			case Crear_Cuadrado:
				cout << "Introduce lado: " ;
				cin >> base ;
				cout << "Introduce x e y: " ;
				cin >> x >> y ;
				vect.anadir(Cuadrado(base, x, y));
				break;
			case Crear_Triangulo:
				cout << "Introduce altura: " ;
				cin >> altura ;
				cout << "Introduce x e y: " ;
				cin >> x >> y ;
				vect.anadir(Triangulo(altura, x, y));
				break;
			case Mover_Figura:
				cout << "Introduce indice: " ;
				cin >> base ;
				cout << "Introduce x e y: " ;
				cin >> x >> y ;
				vect[base].mover(x, y);
				break;
			case Destruir_Figura:
				cout << "Introduce indice: " ;
				cin >> x ;
				vect.borrar(x);
				break;
			default:
				break;
			}
			dibujar_figuras(vect);
			} catch (v_fig_32::Fuera_de_Rango) {
				cerr << "Indice fuera de rango" << endl;
			} catch (v_fig_32::Lleno) {
				cerr << "Vector lleno" << endl;
			}
		} while (opcion != FIN);
	} catch ( ... ) {
		cerr << "Error inesperado" << endl;
	}
}
