/*
 * via.h
 *
 *  Created on: 26 mar. 2020
 *      Author: root
 */

#ifndef VIA_H_
#define VIA_H_
#include <string>
#include <iostream>
using namespace std;

class via {
private:
	string strTipo;		//tipo via
	string strNombre;	//nombre via
	float fLongitud;	//logitud via
	int iCodigoVia;		//codigo via
	int iCodigoBarrio;	//barrio al que pertenece

public:
	via() : strTipo(""),strNombre(""),fLongitud(0.0),iCodigoVia(0),iCodigoBarrio(0) {}
	via(string strTipo1,string strNombre1,float fLongitud1,int iCodigoVia1,int iCodigoBarrio1);
	virtual ~via() {;}
	via(const via &other);
	virtual via* clone() const { return new via(*this); }
	friend ostream& operator<<(ostream& sal, const via& other);
	//via& operator=(const via& other) {strNombre=other.strNombre;strTipo=other.strTipo;fLongitud=other.fLongitud;iCodigoVia=other.iCodigoVia;iCodigoBarrio=other.iCodigoBarrio;return *this;}

	//metodos set
	void setTipo(string strTipo1) {strTipo=strTipo1;}
	void setNombre(string strNombre1) {strNombre=strNombre1;}
	void setLongitud(float fLongitud1) {fLongitud=fLongitud1;}
	void setCodigoVia(int iCodigoVia1) {iCodigoVia=iCodigoVia1;}
	void setCodigoBarrio(int iCodigoBarrio1) {iCodigoBarrio=iCodigoBarrio1;}

	//metodos get
	string getTipo() {return strTipo;}
	string getNombre() {return strNombre;}
	float getLongitud() {return fLongitud;}
	int getCodigoVia() {return iCodigoVia;}
	int getCodigoBarrio() {return iCodigoBarrio;}

};

#endif /* VIA_H_ */
