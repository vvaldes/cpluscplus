/*
 * vector
 *
 *  Created on: 22 mar. 2020
 *      Author: root
 */

#ifndef VECTOR_H_
#define VECTOR_H_

//- fichero: vector.hpp ----------------------------------------------
/*
* Vector que aloja punteros a elementos automaticamente.
* Requiere que el elemento base disponga del metodo ’clone’
*/
template <class TIPO, unsigned tamano>
class Vector {
	unsigned _nelms;
	TIPO* _elm[tamano];

	Vector(const Vector&) {}; // prohibida la copia
	Vector& operator=(const Vector&) {}; // prohibida la asignacion
public:
	class Fuera_de_Rango{}; // excepcion
	class Lleno{}; // excepcion
	~Vector() throw();
	Vector() throw() : _nelms(0) {}
	unsigned size() const throw() { return _nelms; }
	const TIPO& operator[](unsigned i) const throw(Fuera_de_Rango);
	TIPO& operator[](unsigned i) throw(Fuera_de_Rango);
	void anadir(const TIPO& x, unsigned i = tamano) throw(Lleno);
	void borrar(unsigned i) throw(Fuera_de_Rango);
};


template <class TIPO, unsigned tamano>
Vector<TIPO,tamano>::~Vector() throw()
{
for (unsigned i = 0; i < _nelms; ++i) {
	delete _elm[i];
	}
}

template <class TIPO, unsigned tamano>
const TIPO&
Vector<TIPO,tamano>::operator[](unsigned i) const throw(Fuera_de_Rango)
{
	if (i >= _nelms) {
		throw Fuera_de_Rango();
	}
return *_elm[i];
}

template <class TIPO, unsigned tamano>
TIPO&
Vector<TIPO,tamano>::operator[](unsigned i) throw(Fuera_de_Rango)
{
	if (i >= _nelms) {
		throw Fuera_de_Rango();
	}
return *_elm[i];
}

template <class TIPO, unsigned tamano>
void Vector<TIPO,tamano>::anadir(const TIPO& x, unsigned i) throw(Lleno)
{
	if (_nelms == tamano) {
		throw Lleno();
	}
	if (i >= _nelms) {
		_elm[_nelms] = x.clone();
	} else {
		for (unsigned j = _nelms; j > i; --j) {
			_elm[j] = _elm[j-1];
		}
		_elm[i] = x.clone();
		}
		++_nelms;
}

template <class TIPO, unsigned tamano>
void Vector<TIPO,tamano>::borrar(unsigned i) throw(Fuera_de_Rango)
{
	if (i >= _nelms) {
		throw Fuera_de_Rango();
	}
		delete _elm[i];
		--_nelms;
	for (unsigned j = i; j < _nelms; ++j) {
		_elm[j] = _elm[j+1];
	}
}


#endif /* VECTOR_H_ */
