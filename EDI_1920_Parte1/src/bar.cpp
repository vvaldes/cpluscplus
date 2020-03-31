/*
 * bar.cpp
 *
 *  Created on: 26 mar. 2020
 *      Author: Victor Valdes
 */
#include "bar.h"
/********************************************************************************************
  bar(string strNombre1,int iCapacidad1,bool bComida1,string strTipoComida1,long strTelefono1,unsigned int iCodigoPostal1,int iCodigoVia1,int iPortal1,string strHoraApertura1,string strHoraCierre1)
 Constructor inserta atributos de la clase
 Fecha:26/3/2020
 Autor:Victor Valdes
 *********************************************************************************************/
bar::bar(string strNombre1,int iCapacidad1,string strComida1,string strTipoComida1,string strTelefono1,unsigned int iCodigoPostal1,int iCodigoVia1,int iPortal1,string strHoraApertura1,string strHoraCierre1)
{
	strNombre=strNombre1;
	iCapacidad=iCapacidad1;
	setComida(strComida1);        //transforma string en boolean
	strTipoComida=strTipoComida1;
	strTelefono=strTelefono1;
	iCodigoPostal=iCodigoPostal1;
	iCodigoVia=iCodigoVia1;
	iPortal=iPortal1;
	strHoraApertura=strHoraApertura1;
	strHoraCierre=strHoraCierre1;

}


/********************************************************************************************
  bar::bar(const bar &other)
 Constructor inserta atributos de la clase
 Fecha:26/3/2020
 Autor:Victor Valdes
 *********************************************************************************************/
bar::bar(const bar &other)
{
	strNombre=other.strNombre;
	iCapacidad=other.iCapacidad;
	bComida=other.bComida;
	strTipoComida=other.strTipoComida;
	strTelefono=other.strTelefono;
	iCodigoPostal=other.iCodigoPostal;
	iCodigoVia=other.iCodigoVia;
	iPortal=other.iPortal;
	strHoraApertura=other.strHoraApertura;
	strHoraCierre=other.strHoraCierre;

}

/********************************************************************************************
ostream& operator<<(ostream& out, const bar& other)
 Constructor inserta atributos de la clase
 Fecha:26/3/2020
 Autor:Victor Valdes
 ENTRADA:ostream y bar
 SALIDA: ostream
 *********************************************************************************************/
ostream& operator<<(ostream& out, const bar& other)
{
  out<<"\""<<other.strNombre<<"\" Comida Rápida:"<< ((other.bComida) ? "SI":"NO")<<" tipo comida:"<<other.strTipoComida<<" Capacidad:"<<other.iCapacidad;
  return out;
}



