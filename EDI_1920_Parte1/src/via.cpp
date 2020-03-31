/*
 * via.cpp
 *
 *  Created on: 26 mar. 2020
 *      Author: root
 */

#include "via.h"


/********************************************************************************************
  via(string strTipo1,string strNombre1,float fLongitud1,int iCodigoVia1,int iCodigoBarrio1)
 Constructor inserta atributos de la clase
 Fecha:26/3/2020
 Autor:Victor Valdes
 *********************************************************************************************/
via::via(string strTipo1,string strNombre1,float fLongitud1,int iCodigoVia1,int iCodigoBarrio1)
{
	strTipo=strTipo1;
	strNombre=strNombre1;
	fLongitud=fLongitud1;
	iCodigoVia=iCodigoVia1;
	iCodigoBarrio=iCodigoBarrio1;

}


/********************************************************************************************
  via::via(const via &other)
 Constructor inserta atributos de la clase
 Fecha:26/3/2020
 Autor:Victor Valdes
 *********************************************************************************************/
via::via(const via &other) {
	strTipo=other.strTipo;
	strNombre=other.strNombre;
	fLongitud=other.fLongitud;
	iCodigoVia=other.iCodigoVia;
	iCodigoBarrio=other.iCodigoBarrio;
}

/********************************************************************************************
  ostream& operator<<(ostream& out, const via& other)
 Constructor inserta atributos de la clase
 Fecha:26/3/2020
 Autor:Victor Valdes
 ENTRADA:ostream y via
 SALIDA: ostream
 *********************************************************************************************/
ostream& operator<<(ostream& out, const via& other)
{
  out<<other.strNombre<<" long.:"<< other.fLongitud<<" código barrio:"<<other.iCodigoBarrio<< " código via:"<<other.iCodigoVia;
  return out;
}


