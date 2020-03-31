/*
 * bar.h
 *
 *  Created on: 26 mar. 2020
 *      Author: root
 */

#ifndef BAR_H_
#define BAR_H_
#include <string>
#include <iostream>
using namespace std;

class bar {
private:
	string strNombre;				//nombre
	int iCapacidad;					//capacidad
	bool bComida;					//comida rapida true o false
	string strTipoComida;			//tipo comida
	string strTelefono;				//telefono
	unsigned int iCodigoPostal;		//codigo postal
	int iCodigoVia;					//codigo via
	int iPortal;					//portal
	string strHoraApertura;			//hora apertura
	string strHoraCierre;			//hora cierre

public:
	bar() : strNombre(""),iCapacidad(0),bComida(false),strTipoComida(""),strTelefono(""),iCodigoPostal(0),iCodigoVia(0),iPortal(0),strHoraApertura(""),strHoraCierre("") {}
	bar(string strNombre1,int iCapacidad1,string strComida1,string strTipoComida1,string strTelefono1,unsigned int iCodigoPostal1,int iCodigoVia1,int iPortal1,string strHoraApertura1,string strHoraCierre1);
	virtual ~bar() {;}
	bar(const bar &other);
	virtual bar* clone() const { return new bar(*this); }
	friend ostream& operator<<(ostream& sal, const bar& other);
	bar& operator=(const bar& other) {strNombre=other.strNombre;iCapacidad=other.iCapacidad;bComida=other.bComida;strTipoComida=other.strTipoComida;strTelefono=other.strTelefono;iCodigoPostal=other.iCodigoPostal;iCodigoVia=other.iCodigoVia;iPortal=other.iPortal;strHoraApertura=other.strHoraApertura;strHoraCierre=other.strHoraCierre;return *this;}

	//metodos set
	void setNombre(string strNombre1) {strNombre=strNombre1;}
	void setCapacidad(int iCapacidad1) {iCapacidad=iCapacidad1;}
	void setComida(bool bComida1) {bComida=bComida1;}
	void setComida(string strComida1) { (strComida1=="SI") ? bComida=true:bComida=false;}
	void setTipoComida(string strTipoComida1) {strTipoComida=strTipoComida1;}
	void setTelefono(string strTelefono1) {strTelefono=strTelefono1;}
	void setCodigoPostal(unsigned int iCodigoPostal1) {iCodigoPostal=iCodigoPostal1;}
	void setCodigoVia(int iCodigoVia1) {iCodigoVia=iCodigoVia1;}
	void setPortal(int iPortal1) {iPortal=iPortal1;}
	void setHoraApertura(string strHoraApertura1) {strHoraApertura=strHoraApertura1;}
	void setHoraCierre(string strHoraCierre1) {strHoraCierre=strHoraCierre1;}

	//medodos get
	string getNombre() {return strNombre;}
	int getCapacidad() {return iCapacidad;}
	bool getComida() {return bComida;}
	string getTipoComida() {return strTipoComida;}
	string getTelefono() {return strTelefono;}
	unsigned int  getCodigoPostal() {return iCodigoPostal;}
	int getCodigoVia() {return iCodigoVia;}
	int getPortal() {return iPortal;}
	string getHoraApertura() {return strHoraApertura;}
	string getHoraCierre() {return strHoraCierre;}

};

#endif /* BAR_H_ */
