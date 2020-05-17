/*
 * barrio.cpp
 *
 *  Created on: 26 mar. 2020
 *      Author: Victor Valdés
 */

#include "barrio.h"

/********************************************************************************************
  barrio(int iCodigo,string strNombreBarrio=NULL,float area=0,float fPerimetro1,string strDistri)
 Constructor inserta atributos de la clase
 Fecha:26/3/2020
 Autor:Victor Valdes
 *********************************************************************************************/
barrio::barrio(int iCodigo,string strNombreBarrio,float area,float fPerimetro1,string strDistri)
{
	iCodigoBarrio=iCodigo;
	strNombre=strNombreBarrio;
	fArea=area;
	fPerimetro=fPerimetro1;
	strDistrito=strDistri;
	lVias=NULL;
	iNodes=0;
}

/********************************************************************************************
  barrio(int iCodigo,string strNombreBarrio,float fPerimetro1,string strDistri)
 Constructor inserta atributos de la clase
 Fecha:26/3/2020
 Autor:Victor Valdes
 *********************************************************************************************/
/*barrio::barrio(int iCodigo,string strNombreBarrio,float fPerimetro1,string strDistri)
{
	iCodigoBarrio=iCodigo;
	strNombre=strNombreBarrio;
	fArea=0.0;
	fPerimetro=fPerimetro1;
	strDistrito=strDistri;
}
*/
/********************************************************************************************
  barrio::~barrio()
 Destructor
 Fecha:26/3/2020
 Autor:Victor Valdes
  Si existe puntero con vias en el barrio se destruye
 *********************************************************************************************/
barrio::~barrio() {
	// TODO Auto-generated destructor stub
	//lVias.~ListaPI();
	if (lVias)
		delete lVias;
}

/********************************************************************************************
  barrio::barrio(const barrio &other)
 Constructor inserta atributos de la clase
 Fecha:26/3/2020
 Autor:Victor Valdes
   Constructor a partir de otro
 ********************************************************************************************/
barrio::barrio(const barrio &other) {
	iCodigoBarrio=other.iCodigoBarrio;
	strNombre=other.strNombre;
	fArea=other.fArea;
	fPerimetro=other.fPerimetro;
	strDistrito=other.strDistrito;
	lVias=other.lVias;
	iNodes=other.iNodes;
}

/********************************************************************************************
bool barrio::anadirVia(via& x)
 Fecha:26/3/2020
 Autor:Victor Valdes
   Añadimos via a un barrio
 ENTRADA: objeto via
 SALIDA:  true si se añade.
 ********************************************************************************************/
bool barrio::anadirVia(via& x)
{
bool bSalida=false;

		//nuevo = new nodo<TIPO>(v, plista);
		if (existeVia(x)==false) {  //inserto vias sin repetir
			if (lVias==NULL)
				lVias= new ListaPI<via>();

			lVias->insertar(x);        //insertar via en la lista de vias
			iNodes++;
			bSalida=true;
		}

	return bSalida;
}

/********************************************************************************************
bool barrio::existeVia(int iCodigo)
 Fecha:26/3/2020
 Autor:Victor Valdes
   Añadimos via a un barrio
 ENTRADA: codigo via
 SALIDA:  true si existe.
 ********************************************************************************************/
bool barrio::existeVia(int iCodigo)
{
bool bSalida=false;
bool bSalir=false;
via  via1;

	if (lVias!=NULL) {
		lVias->moverInicio();
		while ((bSalir==false) && (lVias->finLista()==false)) {
			lVias->consultar(via1);
			if (via1.getCodigoVia()==iCodigo)
				bSalida=bSalir=true;
			lVias->avanzar();
		}
	}

return bSalida;
}

/********************************************************************************************
bool barrio::existeVia(via& via)
 Fecha:26/3/2020
 Autor:Victor Valdes
   Añadimos via a un barrio
 ENTRADA: objeto via
 SALIDA:  true si existe.
 ********************************************************************************************/
bool barrio::existeVia(via& via)
{
return existeVia(via.getCodigoVia());
}

/********************************************************************************************
ostream& operator<<(ostream& out,barrio& other)
 opertador de salida
 Fecha:26/3/2020
 Autor:Victor Valdes
   Añadimos via a un barrio
 ENTRADA: ostream y objeto barrio
 SALIDA:  ostream
 ********************************************************************************************/
ostream& operator<<(ostream& out,barrio& other)
{
via bVTemp;

  out<<"BARRIO \""<<other.strNombre<<"\":"<<endl;
  out<<"BARRIO:"<<other.strNombre<<" -"<< other.fArea<<" -"<<other.fPerimetro<<" codigo barrio:"<<other.iCodigoBarrio<<" distrito:"<<other.strDistrito<<endl;
  if (other.lVias!=NULL) {
	   ListaPI<via> *listaVia = other.getVia();
	   listaVia->moverInicio();
		while (listaVia->finLista()==false) {
			listaVia->consultar(bVTemp);
			cout<<"\t"<<bVTemp<<endl;
			listaVia->avanzar();
		}
  }
  return out;
}

