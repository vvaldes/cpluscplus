/*
 * barrio.h
 *
 *  Created on: 26 mar. 2020
 *      Author: Victor Valdes
 */

#ifndef BARRIO_H_
#define BARRIO_H_
#include <string>
#include <iostream>
#include "listapi.h"
#include "via.h"

using namespace std;

class barrio {
private:
  int iCodigoBarrio;  	//Codigo barrio
  string strNombre;   	//nombre barrio
  float fArea;        	//area barrio
  float fPerimetro;		//perimetro barrio
  string strDistrito;	//distrito barrio
  //ListaPI<via> lVias;
  ListaPI<via> *lVias;	//puntero de lista de vias
  int iNodes;

public:

    barrio() : iCodigoBarrio(0),strNombre(""),fArea(0.0),fPerimetro(0.0),strDistrito(""),lVias(NULL),iNodes(0) {}
    //barrio() : iCodigoBarrio(0),strNombre(""),fArea(0.0),fPerimetro(0.0),strDistrito(""),lVias() {}
	barrio(int iCodigo,string strNombreBarrio,float area,float fPerimetro1,string strDistri);
	//barrio(int iCodigo,string strNombreBarrio,float fPerimetro1,string strDistri);
	virtual ~barrio();
	barrio(const barrio &other);
	virtual barrio* clone() const { return new barrio(*this); }
	friend ostream& operator<<(ostream& sal, barrio& other);
	//barrio& operator=(const barrio& other) {iCodigoBarrio=other.iCodigoBarrio;strNombre=other.strNombre;fArea=other.fArea;fPerimetro=other.fPerimetro;strDistrito=other.fPerimetro;lVias=other->lVias;return *this;}
    bool anadirVia(via& x);
    //void borrarVia() {if (!lVias.estaVacia()) delete lVias;} //borra lista de vias

	//Métodos set de los atributos
	void setCodigoBarrio(int iCodigo) { iCodigoBarrio=iCodigo;}
	void setNombreBarrio(string strNombreBarrio=NULL) {strNombre=strNombreBarrio;}
	void setArea(float area=0) {fArea=area;}
	void setPerimetro(float fPerimetro1) {fPerimetro=fPerimetro1;}
	void setDistrito(string strDistri) {strDistrito=strDistri;}
	void setiNodes(int iNodes1) {iNodes=iNodes1;}
	void setVias(ListaPI<via> *lVias1) {lVias=lVias1;}


	//Métodos get de los atributos
	int getCodigoBarrio() { return iCodigoBarrio;}
	string getNombreBarrio() { return strNombre;}
	float getArea() { return fArea;}
	float getPerimetro() { return fPerimetro; }
	string getDistrito() { return strDistrito;}
	ListaPI<via> *getVia() {return lVias;}
	int getInodes() {return iNodes;}
	bool existeVia(int iCodigo);
	bool existeVia(via& v);
	//ListaPI<via> getVia() {return lVias;}
};

#endif /* BARRIO_H_ */
