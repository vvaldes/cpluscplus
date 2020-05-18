//============================================================================
// Name        : algoritmos.cpp
// Author      : Profesores de la asignatura EDI
// Version     : 2019/20
// Copyright   : Your copyright notice
// Description : Implementación de los algoritmos del proyecto
//============================================================================


#include <fstream>
#include <iostream>
#include <string>
#include <sstream>



#include "algoritmos.h"


using namespace std;

//#ifndef DEBUG
//#define DEBUG
//#endif

// MAIN function
/********************************************************************************************
  int main ()
   metodo main del programa, punto de entrada de ejecución
 Fecha:26/3/2020
 Autor:Victor Valdes
 *********************************************************************************************/
int main () {

    Algoritmos Algoritmos;  //constructor
}


// ******************** PRIVATE OPERATIONS ********************
/********************************************************************************************
  void Algoritmos::run()
   Ejecución con todos los algoritmos pedidos
 Fecha:26/3/2020
 Autor:Victor Valdes
 *********************************************************************************************/
void Algoritmos::run() {

	parte2();

//	parte1();
}

/********************************************************************************************
void Algoritmos::parte2() {
   Ejecución con todos los algoritmos pedidos
 Fecha:18/5/2020
 Autor:Victor Valdes
 *********************************************************************************************/
void Algoritmos::parte2() {
	int iOpccion;
	string strNombre,strNombre1,strTipo;


		//PARTE 2
	    cout<<"ALGORITMO 1. recorrido iterativo sobre el árbol de bares.Bares en orden alfabético inverso."<<endl;
	    this->arbolAFichero();

	    cout<<"ALGORITMO 2 Bares de una determinada vía (tipo de vía + nombre de la vía)"<<endl;
	    cout<<"Dame el nombre tipo de la vía:"<<endl;
	    getline(cin >> ws,strTipo);
	    cout<<"Dame el nombre de la calle:"<<endl;
	    getline(cin >> ws,strNombre);
	    //strTipo="Calle";
	    //strNombre="Pizarro";
	    escribirCalleBar(strTipo,strNombre);


	    cout<<"ALGORITMO 3 Buscar y mostrar un bar junto con el nombre de la vía donde."<<endl;
	    cout<<"Dame el nombre del bar:"<<endl;
	    getline(cin >> ws,strNombre);
	    //strNombre="Puerta de Mérida";
	    buscarBar(strNombre);


	    cout<<"ALGORITMO 4 Bares cuyos nombres comienzan por una determinada raíz,ordenados por capacidad."<<endl;
	    cout<<"Dame el nombre del bar:"<<endl;
	    getline(cin >> ws,strNombre);
	    //strNombre="Bur";
	    buscarEmpiezaBar(strNombre);

	    cout<<"ALGORITMO 6 Lista de bares que sirvan un determinado tipo de comida y cuya capacidad sea superior a una dada"<<endl;
	    cout<<"Dame el tipo de comida:"<<endl;
	    getline(cin >> ws,strNombre);
	    cout<<"Dame a partir de que capacidad:"<<endl;
	    cin>>iOpccion;
	    //iOpccion=40;
	    //strNombre="TAPAS";
	    escribirBarTipoCapacidad(strNombre,iOpccion);


	    cout<<"ALGORITMO 7 Barrio con más bares:"<<endl;
	    barrioMasBares();
}

/********************************************************************************************
void Algoritmos::parte1() {
   Ejecución con todos los algoritmos pedidos en la parte 1
 Fecha:18/5/2020
 Autor:Victor Valdes
 *********************************************************************************************/
void Algoritmos::parte1() {
	int iOpccion,iMas,iCodigoBarrio,iCodigoBarrioMas;
	string strNombre,strNombre1,strTipo;
	bool bSalir=false;

	// TODO invovar a todos los algoritmos para que se ejecuten secuencialemente

    // Algoritmo 1 Parte 1
    cout<<"Dame el codigo  del barrio del que quieres ver las vias que contiene:"<<endl;
    //getline(cin >> ws,strNombre);
    cin>>iOpccion;

	barrios.moverInicio();
	barrios.consultar(bTemp);
	while((barrios.finLista()==false) && (bSalir==false)) {
		if (bTemp.getCodigoBarrio() == iOpccion)
				bSalir=true;
		else {
			barrios.avanzar();
			barrios.consultar(bTemp);
		}
	}
	//Visualizamos vias de un barrio
	cout<<"ALGORITMO 1:VIAS DE UN BARRIO"<<endl;
	cout<<bTemp<<endl;
	cout<<"Nº de vías:"<<bTemp.getInodes()<<endl;

    // Algoritmo 2 Parte 1
	//Via más larga
	float lMas=0;
	for (vias.moverInicio();vias.finLista()==false;vias.avanzar()) {
		vias.consultar(vVia);
		if (vVia.getLongitud()>lMas) {
			bVTemp=vVia;
			lMas=vVia.getLongitud();
		}
	}
	cout<<endl<<"ALGORITMO 2:VIA MAS LARGA"<<endl;
	cout<<bVTemp<<endl;

    // Algoritmo 3 Parte 1
    cout<<"Dame el tipo comida, para visualizar los bares que lo sirven:"<<endl;
    getline(cin >> ws,strNombre1);
	cout<<endl<<"ALGORITMO 3: COLA DE BARES POR TIPO DE COMIDA"<<endl;
	//Comprovamos tipos de comida que existen
    for (bares.moverInicio(),iOpccion=0;bares.finLista()==false;bares.avanzar()) {
    	bares.consultar(bBar);
    	for (strTipos.moverInicio(),bSalir=false;strTipos.finLista()==false;strTipos.avanzar()) {
    		strTipos.consultar(strNombre);
    		if (strNombre1==bBar.getTipoComida())
    			bSalir=true;
    	}
    	if (bSalir==false) { //añadimos tipo de comida
    		strTipos.insertar(bBar.getTipoComida());
    		iOpccion++;
    	}
    }

    //Añadimos dinamicamente listas por tipos de comidas
    for (bares.moverInicio();bares.finLista()==false;bares.avanzar()) {
    	bares.consultar(bBar);
    	if (bBar.getTipoComida()==strNombre1) {
    		barTipo.encolar(bBar);
    		//cout<<"inserto:"<<bBar;
    	}
    }

    if (barTipo.vacia())
    	cout<<"No existen bares con éste tipo de comida"<<endl;
    else {
    	barTipo.primero(bBar);
		cout<<"TIPO:"<<bBar.getTipoComida()<<endl;
    	while (barTipo.vacia()==false) {
    		barTipo.primero(bBar);
    		cout<<bBar<<endl;
    		barTipo.desencolar();
    	}
    }

    // Algoritmo 4 Parte 1
    cout<<"ALGORITMO 4: DISTRITO CON MAS BARRIOS"<<endl;
	//Comprovamos distritos que existen
    for (barrios.moverInicio(),iOpccion=0;barrios.finLista()==false;barrios.avanzar()) {
    	barrios.consultar(bBarrio);
    	for (strDistritos.moverInicio(),bSalir=false;strDistritos.finLista()==false;strDistritos.avanzar()) {
    		strDistritos.consultar(strNombre);
    		if (strNombre==bBarrio.getDistrito())
    			bSalir=true;
    	}
    	if (bSalir==false) { //añadimos tipo de comida
    		strDistritos.insertar(bBarrio.getDistrito());
    		iOpccion++;
    	}
    }

    //Recorremos por cada distrito y vemos la cantidad de barrios que existen en ese barrio
	for (strDistritos.moverInicio(),iMas=iCodigoBarrio=iCodigoBarrioMas=0;strDistritos.finLista()==false;strDistritos.avanzar()) {
	    for (barrios.moverInicio(),iOpccion=0;barrios.finLista()==false;barrios.avanzar()) {
	    	strDistritos.consultar(strNombre);
	    	barrios.consultar(bBarrio);
	    	if (strNombre==bBarrio.getDistrito()) {
	    		++iOpccion;
	    		iCodigoBarrio=bBarrio.getCodigoBarrio();
	    	}
	    }
	    if (iOpccion>iMas) {
	    	iMas=iOpccion;
	    	iCodigoBarrioMas=iCodigoBarrio;
	    }

	}

	//Visualizamos barrio
    for (barrios.moverInicio();barrios.finLista()==false;barrios.avanzar()) {
    	barrios.consultar(bBarrio);
    	if (bBarrio.getCodigoBarrio()==iCodigoBarrioMas)
    		cout<<"Distrito:"<<bBarrio.getDistrito()<<" con:"<<iMas<<" barrios"<<endl;
    }
}
/********************************************************************************************
void Algoritmos::cargarDatos()
   Carga los datos de los ficheros .csv y los almacena en listas dinámicas
 Fecha:26/3/2020
 Autor:Victor Valdes
 Explicación:
    Carga fichero via.csv y lo inserta en lista vias
    Carga fichero barrios.csv y lo inserta en lista barrios
    	Si en el barrio existen vias, inserto vias en lista dinámica de vias perteneciente a cada barrio
    Carga fichero bar.csv  y lo inserta en lista bares
Modifica:
	//Listas
	ListaPI<barrio> barrios;
	ListaPI<via> vias;
	ListaPI<bar> bares;

	Modifica :
	//Arbol con los bares
	BSTree<string> *bBares;
 *********************************************************************************************/
void Algoritmos::cargarDatos() {
	// TODO realizar la lectura del fichero de barrios y después el de vías
    float a;
    bool bSalir=false;
	string strLinea,word;

    //Lectura de las vias e insercción
        ifstream inFileVia1("Via.csv");
        if (inFileVia1.is_open()) {
        	getline(inFileVia1,strLinea); //Descrimino cabecera con nombres campos
    		while (getline(inFileVia1,strLinea))
    		{
    			stringstream strstr(strLinea);
    			for (int iContador=0;getline(strstr,word,';');iContador++)
    			{
    				 //como le vamos ir agregando los datos
    				 switch (iContador) {
    				 case 0: //tipo
    					 vVia.setTipo(word);
    					 break;
    				 case 1: //nombre
    					 vVia.setNombre(word);
    					 break;
    				 case 2: //longitud
    					 if (word.length())
    						  a=stof(word);
    					 else a=0.0;
    					 vVia.setLongitud(a);
    					 break;
    				 case 3: //codigo via
    					 vVia.setCodigoVia(stoi(word));
    					 break;
    				 case 4: //codigo barrio
    					 vVia.setCodigoBarrio(stoi(word));
    					 break;
    				 default: //error
    					 cout<< "Error lectura erronea";
    				 }

    			}
#ifdef DEBUG
    			cout<<vVia<<endl;
#endif
    			//insertamos via en orden ASCENDENTE dentro de la lista de vias
    			vias.moverInicio();
    			vias.consultar(bVTemp);
    			bSalir=false;
    			while((vias.finLista()==false) && (bSalir==false)) {
    				if (bVTemp.getCodigoVia() > vVia.getCodigoVia())
    						bSalir=true;
    				else {
    					vias.avanzar();
    					vias.consultar(bVTemp);
    				}
    			}
    			//Insertamos via en la lista vias
    			vias.insertar(vVia);
    		}
        }
        //cerramos fichero via
        inFileVia1.close();


	//Lectura e insercción en lista de los barrios
    ifstream inFileBarrio("Barrio.csv");
    if (inFileBarrio.is_open()) {
    	getline(inFileBarrio,strLinea); //Descrimino cabecera con nombres campos
		while (getline(inFileBarrio,strLinea))
		{
			stringstream strstr(strLinea);
			for (int iContador=0;getline(strstr,word,';');iContador++)
			{
				 //como le vamos ir agregando los datos
				 switch (iContador) {
				 case 0: //nombre
					 bBarrio.setNombreBarrio(word);
					 break;
				 case 1: //area
					 if (word.length()) {
						 a=stof(word);
						 bBarrio.setArea(a);
					 } else bBarrio.setArea(0);
					 break;
				 case 2: //perimetro
					 bBarrio.setPerimetro(stof(word));
					 break;
				 case 3: //codigo barrio
					 bBarrio.setCodigoBarrio(stoi(word));
					 break;
				 case 4: //distrito
					 bBarrio.setDistrito(word);
					 break;
				 default: //error
					 cout<< "Error lectura erronea";
				 }

			}
			bBarrio.setVias(NULL);
			bBarrio.setiNodes(0);
#ifdef DEBUG
			cout<<bBarrio<<endl;
#endif

			//Buscamos vias que tienen estan en ese barrio
			vias.moverInicio();
			vias.consultar(vVia);
			bSalir=false;
			while (vias.finLista()==false) {
				if (bBarrio.getCodigoBarrio()==vVia.getCodigoBarrio())
					bBarrio.anadirVia(vVia);  //si se añade porque no existe
					//		bSalir=true;

				vias.avanzar();
				vias.consultar(vVia);
			}
			if (bBarrio.getVia())
				bBarrio.getVia()->moverFinal();
			vias.moverFinal();


			//Insertamos en lista ordenadamente por codigo barrio de MENOR A MAYOR
			barrios.moverInicio();
			barrios.consultar(bTemp);
			bSalir=false;
			while((barrios.finLista()==false) && (bSalir==false)) {
				if (bTemp.getCodigoBarrio() > bBarrio.getCodigoBarrio())
						bSalir=true;
				else {
					barrios.avanzar();
					barrios.consultar(bTemp);
				}
			}

			//insertamos en lista por orden
			barrios.insertar(bBarrio);
		}
    //cerramos fichero barrio
    inFileBarrio.close();
    }

        //Lectura de las vias e insercción
            ifstream inBares("Bar.csv");
            if (inBares.is_open()) {
            	getline(inBares,strLinea); //Descrimino cabecera con nombres campos
        		while (getline(inBares,strLinea))
        		{
        			stringstream strstr(strLinea);
        			for (int iContador=0;getline(strstr,word,';');iContador++)
        			{
        				 //como le vamos ir agregando los datos
        				 switch (iContador) {
        				 case 0: //nombre
        					 bBar.setNombre(word);
        					 break;
        				 case 1: //capacidad
        					 bBar.setCapacidad(stoi(word));
        					 break;
        				 case 2: //sirve comida
        					 bBar.setComida(word);
        					 break;
        				 case 3: //tipo comida
        					 bBar.setTipoComida(word);
        					 break;
        				 case 4: //telefono
        					 bBar.setTelefono(word);
        					 break;
        				 case 5: //codigo postal
        					 bBar.setCodigoPostal(stoi(word));
        					 break;
        				 case 6: //codigo via
        					 bBar.setCodigoVia(stoi(word));
        					 break;
        				 case 7: //portal OPCIONAL
        					 if (word.length())
        						  bBar.setPortal(stoi(word));
        					 else bBar.setPortal(0);
        					 break;
        				 case 8: //hora apertura
        					 bBar.setHoraApertura(word);
        					 break;
        				 case 9: //hora cierre
        					 bBar.setHoraCierre(word);
        					 break;
        				 default: //error
        					 cout<< "Error lectura erronea";
        				 }

        			}
#ifdef DEBUG
        			cout<<bBar<<endl;
#endif

        			//insertamos bar en orden ASCENDENTE dentro lista por orden de via
        			bares.moverInicio();
        			bares.consultar(bBarTemp);
        			bSalir=false;
        			while((bares.finLista()==false) && (bSalir==false)) {
        				if (bBarTemp.getCodigoVia() > bBar.getCodigoVia())
        						bSalir=true;
        				else {
        					bares.avanzar();
        					bares.consultar(bBarTemp);
        				}
        			}
        			//Insertamos bar en orden de via
        			bares.insertar(bBar);

        			//Insertamos también en arbol binario por orden de nombre campo
        			bBares->insert(bBar.getNombre());
        		}
            }

			//cerramos fichero bares
            inBares.close();
}





// ******************** PUBLIC INTERFACE ********************

/********************************************************************************************
 Algoritmos::Algoritmos()
   Constructor
 Fecha:26/3/2020
 Autor:Victor Valdes
   Carga datos ficheros y ejecuta programa
 *********************************************************************************************/
Algoritmos::Algoritmos() {
    
    cout << "Programming Project v1.00 (EDI)." << endl;
    cout << "           Author: Victor Valdes Cobos." << endl;
    cout << "           Date:   April 5th, 2020." << endl;
    


    // TODO reserva de memoria para los atributos
    bBares = new BSTree<string> ();
    baresOrdenada=new ListaPI<bar> ();

    cargarDatos();
    run();
}

/********************************************************************************************
void Algoritmos::escribirBar(string strBar, ofstream &f,string strCalle,bool bEntero) {
   Escribe en fichero información del bar a partir del nombre del bar
   Entrada:
   string strBar: Nombre del bar
   ofstream &f: ofstream del fichero ya abierto
   string strCalle: calle
   bool bEntero: listado completo o no
 Fecha:18/5/2020
 Autor:Victor Valdes
 *********************************************************************************************/

void Algoritmos::escribirBar(string strBar, ofstream &f,string strCalle,bool bEntero) {
	string siNo;

    for (bares.moverInicio();bares.finLista()==false;bares.avanzar()) {
    	bares.consultar(bBar);
    	if (bBar.getNombre()==strBar) {
    		siNo=(bBar.getComida()) ? " SI ":" NO ";
    		//f<<"\t\t\tPax: "<<bBar.getCapacidad()<<"\t"<<siNo<<"\t"<<bBar.getTipoComida();
    		if (bEntero)
    			f<<",capacidad "<<bBar.getCapacidad()<<", sirve comida "<<siNo<<", tipo comida "<<bBar.getTipoComida()<<", "<<strCalle<<endl;
    		else
    			f<<"  Pax: "<<bBar.getCapacidad()<<"\t"<<siNo<<"\t"<<bBar.getTipoComida();
    	}

    	//(bBar.getComida()) ? " SI ":" NO " <<
    }

}

/********************************************************************************************
int Algoritmos::numElementos(BSTree<string> *bst) {
   Retorna el nº de elementos del arbol
   Entrada: arbol
 Fecha:18/5/2020
 Autor:Victor Valdes
 *********************************************************************************************/
int Algoritmos::numElementos(BSTree<string> *bst) {


	int cuantos = 0;

	if (bst !=NULL) {
		cuantos = 1 + numElementos(bst->left()) + numElementos (bst->right());

	}
	return cuantos;

}
/********************************************************************************************
void Algoritmos::arbolAFicheroArbol(BSTree<string> *bts, ofstream &f) {
   Escribe en fichero ya abierto el arbol en recorrido contrario a inorden.
   Entrada:
		BSTree<string> *bts: arbol
		ofstream &f: fichero
 Fecha:18/5/2020
 Autor:Victor Valdes
 *********************************************************************************************/
//RECORRIDO INVERSO DERECHO CENTRO Y POR ULTIMO IZQUIERDO
void Algoritmos::arbolAFicheroArbol(BSTree<string> *bts, ofstream &f) {
    BSTree<string> *aux;

    if (! bts->empty()) {

    	aux = bts->right();
        if (aux != NULL) {
            arbolAFicheroArbol(aux,f);
        }

        f << bts->root().substr(0,20); //nombre
        escribirBar(bts->root(),f); //información bar
        f <<  endl;

        aux = bts->left();
        if (aux != NULL) {
            arbolAFicheroArbol(aux,f);
        }

    }
}

/********************************************************************************************
void Algoritmos::arbolAFicheroNombre(BSTree<string> *bts, ofstream &f,string strNombre,bool bEntero) {
   Escribe en fichero ya abierto informacion de un bar
   Entrada:
		BSTree<string> *bts: arbol
		ofstream &f: fichero
		string strNombre: nombre del bar
		bool bEntero: listado completo o no
 Fecha:18/5/2020
 Autor:Victor Valdes
 *********************************************************************************************/
void Algoritmos::arbolAFicheroNombre(BSTree<string> *bts, ofstream &f,string strNombre,bool bEntero) {
    BSTree<string> *aux;

    if (! bts->empty()) {

    	aux = bts->right();
        if (aux != NULL) {
            arbolAFicheroNombre(aux,f,strNombre,bEntero);
        }

        if (bts->root()==strNombre) {
        	f << bts->root().substr(0,14); //nombre
        	escribirBar(bts->root(),f,strNombre,bEntero); //información bar
        	f <<  endl;
        }

        aux = bts->left();
        if (aux != NULL) {
            arbolAFicheroNombre(aux,f,strNombre,bEntero);
        }

    }
}

/********************************************************************************************
void Algoritmos::anadirBarOrdenado(string strNombre){
   Genera lista ordenada de bares por capacidad
   Entrada:
   strNombre: nombre bar
	Modifica:
	ListaPI<bar> *baresOrdenada;  //lista ordenada por capacidad de bares
 Fecha:18/5/2020
 Autor:Victor Valdes
 *********************************************************************************************/
void Algoritmos::anadirBarOrdenado(string strNombre){
	bool bSalir=false;

	for (bares.moverInicio();((bares.finLista()==false) && (bSalir==false));bares.avanzar()) {
			bares.consultar(bBar);
			if (bBar.getNombre()==strNombre) {
				//Insertamos en lista por orden de capacidad
    			//insertamos bar en orden ASCENDENTE dentro lista por orden de via
				baresOrdenada->moverInicio();
				baresOrdenada->consultar(bBarTemp);
    			bSalir=false;
    			while((baresOrdenada->finLista()==false) && (bSalir==false)) {
    				if (bBarTemp.getCapacidad() < bBar.getCapacidad())
    						bSalir=true; //Si encontrado lugar , se inserta y se sale
    				else {
    					baresOrdenada->avanzar();
    					baresOrdenada->consultar(bBarTemp);
    				}
    			}
    			//Insertamos bar en orden de capacidad
    			baresOrdenada->insertar(bBar);
			}
	}

}

/********************************************************************************************
void Algoritmos::arbolAFicheroEmpiezaNombre(BSTree<string> *bts, string strNombre,bool bEntero) {
   Genera lista ordenada de bares por capacidad
   Entrada:
   BSTree<string> *bts:arbol bares
   string strNombre: nombre subcadena de un bar
   bool bEntero: listado entero o no
	Modifica:
	ListaPI<bar> *baresOrdenada;  //lista ordenada por capacidad de bares
 Fecha:18/5/2020
 Autor:Victor Valdes
 *********************************************************************************************/

void Algoritmos::arbolAFicheroEmpiezaNombre(BSTree<string> *bts, string strNombre,bool bEntero) {
    BSTree<string> *aux;
    string cadena;
    int i;

    if (! bts->empty()) {

    	aux = bts->right();
        if (aux != NULL) {
        	arbolAFicheroEmpiezaNombre(aux,strNombre,bEntero);
        }

        cadena=bts->root();
        i=cadena.find(strNombre,0);
        if (i!=-1)  //Si empieza por esa subcadena
        	if (i==0)
        		anadirBarOrdenado(cadena);


        aux = bts->left();
        if (aux != NULL) {
        	arbolAFicheroEmpiezaNombre(aux,strNombre,bEntero);
        }

    }
}

/********************************************************************************************
void Algoritmos::arbolAFichero() {
   recorrido iterativo sobre el árbol de bares.Bares en orden alfabético inverso
   Entrada:
   Modifica: Datos.txt
 Fecha:18/5/2020
 Autor:Victor Valdes
 *********************************************************************************************/
void Algoritmos::arbolAFichero() {

ofstream fichero("Datos.txt");

	if (!fichero.is_open())
			cout<<"El fichero Datos.txt, no se puede abrir"<<endl;
	else
		if (!bBares->empty()) {
			fichero<<"ALGORITMO 1. recorrido iterativo sobre el árbol de bares.Bares en orden alfabético inverso."<<endl;
			arbolAFicheroArbol(bBares,fichero);
			fichero<<"Total bares del árbol en recorrido iterativo:" << numElementos(bBares)<<endl;
			fichero.close();
		}

}

/********************************************************************************************
void Algoritmos::escribirCalleBar(string strTipo,string calle) {
   ALGORITMO 2 Bares de una determinada vía (tipo de vía + nombre de la vía
   Entrada:
   string strTipo: tipo via
   string calle: nombre de la calle
   Modifica: Datos.txt
 Fecha:18/5/2020
 Autor:Victor Valdes
 *********************************************************************************************/

void Algoritmos::escribirCalleBar(string strTipo,string calle) {
string siNo;

	for (vias.moverInicio();vias.finLista()==false;vias.avanzar()) {
		vias.consultar(vVia);
		if ((vVia.getNombre()==calle) && (vVia.getTipo()==strTipo)) {
			ofstream fichero("Datos.txt",std::ofstream::out | std::ofstream::app);
			fichero<<endl<<"ALGORITMO 2 Bares de una determinada vía (tipo de vía + nombre de la vía)"<<endl;

			//Recorremos todos los vares de esta via
			fichero<<strTipo<<" "<<vVia.getNombre()<<endl;
			for (bares.moverInicio();bares.finLista()==false;bares.avanzar()) {
					bares.consultar(bBar);
					if (bBar.getCodigoVia()==vVia.getCodigoVia()) {
						siNo=(bBar.getComida()) ? "SI":"NO";
						fichero<<bBar.getNombre()<<"\t\tPax "<<bBar.getCapacidad()<<"\t"<<siNo<<"\t" <<bBar.getTipoComida()<<endl;
					}
			}
			fichero<<endl;
			fichero.close();
		}
	}

}

/********************************************************************************************
void Algoritmos::buscarBar(string strNombre) {
   ALGORITMO 3 Buscar y mostrar un bar junto con el nombre de la vía donde.
   Entrada:
   string strNombre: nombre
   Modifica: Datos.txt
 Fecha:18/5/2020
 Autor:Victor Valdes
 *********************************************************************************************/

void Algoritmos::buscarBar(string strNombre) {

ofstream fichero("Datos.txt",std::ofstream::out | std::ofstream::app);

	if (!fichero.is_open())
			cout<<"El fichero Datos.txt, no se puede abrir"<<endl;
	else
		if (!bBares->empty()) {
			fichero<<"ALGORITMO 3 Buscar y mostrar un bar junto con el nombre de la vía donde."<<endl;
			arbolAFicheroNombre(bBares,fichero,strNombre,true);
			fichero.close();
		}

}

/********************************************************************************************
void Algoritmos::escribirBaresLista(ofstream &f) {
   Escribe en fichero ya abierto la lista de los bares ordenada por capacidad
   Entrada:
   ofstream &f: fichero abierto
   Modifica: Datos.txt
 Fecha:18/5/2020
 Autor:Victor Valdes
 *********************************************************************************************/

void Algoritmos::escribirBaresLista(ofstream &f) {

	if (baresOrdenada!=NULL) {
		baresOrdenada->moverInicio();
		while (baresOrdenada->finLista()==false) {
			baresOrdenada->consultar(bBar);
			f<<bBar.getNombre()<<" pax:"<<bBar.getCapacidad()<<endl;
			baresOrdenada->avanzar();
		}
		f<<endl;
	}
}


/********************************************************************************************
void Algoritmos::buscarEmpiezaBar(string strNombre) {
   ALGORITMO 4 Bares cuyos nombres comienzan por una determinada raíz, ordenados por capacidad
   Entrada:
   string strNombre: cadena por donde empieza el nombre del bar
   Modifica: Datos.txt
 Fecha:18/5/2020
 Autor:Victor Valdes
 *********************************************************************************************/
void Algoritmos::buscarEmpiezaBar(string strNombre) {

ofstream fichero("Datos.txt",std::ofstream::out | std::ofstream::app);

	if (!fichero.is_open())
			cout<<"El fichero Datos.txt, no se puede abrir"<<endl;
	else
		if (!bBares->empty()) {
			fichero<<"ALGORITMO 4 Bares cuyos nombres comienzan por una determinada raíz, ordenados por capacidad."<<endl;
			//Generamos estructura lista ordenada
			arbolAFicheroEmpiezaNombre(bBares,strNombre,false);
			//Escribimos lista en fichero
			escribirBaresLista(fichero);
			fichero.close();
		}

}


/********************************************************************************************
bar *Algoritmos::nodoBar(string strNombre, string strTipo,int capacidad){
   Retorna un puntero a la clase bar que coincide con su nombre , tipo
   Entrada:
	string strNombre: nombre bar
	string strTipo: tipo comida
	int capacidad:capacidad bar
   Salida:
    Puntero clase bar
   Modifica: Datos.txt

 Fecha:18/5/2020
 Autor:Victor Valdes
 *********************************************************************************************/

bar *Algoritmos::nodoBar(string strNombre, string strTipo,int capacidad){

	for (bares.moverInicio();bares.finLista()==false;bares.avanzar()) {
			bares.consultar(bBar);
			if ((bBar.getTipoComida()==strTipo) && (bBar.getNombre()==strNombre) && (bBar.getCapacidad()>=capacidad))
				return &bBar;

	}
return NULL;
}


/********************************************************************************************
void Algoritmos::arbolAFicheroCapacidad(BSTree<string> *bts, ofstream &f,string strTipo,int capacidad) {
   Recorre el arbol de bares y escribe información del bar
   Entrada:
	BSTree<string> *bts:arbol bares
	ofstream &f: fichero ya abierto
	string strTipo: tipo comida
	int capacida: mayores que dicha capacidad
 Salida:
 Modifica: Datos.txt
 Fecha:18/5/2020
 Autor:Victor Valdes
 *********************************************************************************************/
void Algoritmos::arbolAFicheroCapacidad(BSTree<string> *bts, ofstream &f,string strTipo,int capacidad) {
    BSTree<string> *aux;
    string cadena;
    bar *pBar=NULL;

    if (! bts->empty()) {

    	aux = bts->left();
        if (aux != NULL) {
        	arbolAFicheroCapacidad(aux,f,strTipo,capacidad);
        	//arbolAFicheroEmpiezaNombre(aux,strNombre,bEntero);
        }

        cadena=bts->root();
        pBar=nodoBar(cadena,strTipo,capacidad);
        if (pBar!=NULL)
        	f<<pBar->getNombre()<<" pax:"<<pBar->getCapacidad()<<" "<<pBar->getTipoComida()<<endl;

        aux = bts->right();
        if (aux != NULL) {
        	arbolAFicheroCapacidad(aux,f,strTipo,capacidad);
        }

    }
}

/********************************************************************************************
void Algoritmos::escribirBarTipoCapacidad(string strTipo,int capacidad) {
   ALGORITMO 6 Lista de bares que sirvan un determinado tipo de comida y cuya capacidad sea superior a una dada.
   Entrada:
	string strTipo: tipo comida
	int capacidad: mayores que dicha capacidad
 Salida:
 Modifica: Datos.txt
 Fecha:18/5/2020
 Autor:Victor Valdes
 *********************************************************************************************/
void Algoritmos::escribirBarTipoCapacidad(string strTipo,int capacidad) {

	ofstream fichero("Datos.txt",std::ofstream::out | std::ofstream::app);

		if (!fichero.is_open())
				cout<<"El fichero Datos.txt, no se puede abrir"<<endl;
		else
			if (!bBares->empty()) {
				fichero<<"ALGORITMO 6 Lista de bares que sirvan un determinado tipo de comida y cuya capacidad sea superior a una dada."<<endl;
				//escribirBaresLista(fichero);
				arbolAFicheroCapacidad(bBares,fichero,strTipo,capacidad);
				fichero<<endl;
				fichero.close();
			}
}

/********************************************************************************************
int Algoritmos::baresVias(ListaPI<via> *pVia) {
   Retorna los bares que tiene una lista de vias;
   Entrada:
	ListaPI<via> *pVia: Lista de vias que tiene el barrio
 Salida:
 	 int: nº de vias;
 Fecha:18/5/2020
 Autor:Victor Valdes
 *********************************************************************************************/
int Algoritmos::baresVias(ListaPI<via> *pVia) {
	ListaPI<via> *lVias=pVia;	//puntero de lista de vias
	via via1;
	int nBares=1;

	if (lVias!=NULL) {
		lVias->moverInicio();
		while (lVias->finLista()==false) {
			lVias->consultar(via1);

			for (bares.moverInicio();bares.finLista()==false;bares.avanzar()) {
					bares.consultar(bBar);
					if (bBar.getCodigoVia()==via1.getCodigoVia())
							nBares++;
			}

			lVias->avanzar();
		}
	}

	return nBares;
}

/********************************************************************************************
void Algoritmos::baresBarrios(barrio *pBar,ofstream &f) {
   A partir de un barrio , recorremos sus vias par ver los bares que contiene
   Entrada:
	barrio *pBar: Puntero al barrio
	ofstream &f: fichero
 Salida:
 Modifica: fichero Datos.txt

 Fecha:18/5/2020
 Autor:Victor Valdes
 *********************************************************************************************/

void Algoritmos::baresBarrios(barrio *pBar,ofstream &f) {
	via via1;
	ListaPI<via> *lVias=NULL;
	string siNo;

	if (pBar!=NULL) {
		lVias=pBar->getVia();
		if (lVias!=NULL) {
			lVias->moverInicio();
			while (lVias->finLista()==false) {
				lVias->consultar(via1);

				for (bares.moverInicio();bares.finLista()==false;bares.avanzar()) {
						bares.consultar(bBar);
						if (bBar.getCodigoVia()==via1.getCodigoVia()) {
							siNo=bBar.getComida() ? "SI":"NO";
							f<<bBar.getNombre()<<" Pax:"<<bBar.getCapacidad()<<" "<<siNo<<bBar.getTipoComida()<<endl;
						}
				}
				lVias->avanzar();
			}
		}
		f<<endl;
	}
}


/********************************************************************************************
void Algoritmos::barrioMasBares() {
   Busca el barrio que más bares tiene
   Entrada:
 Salida:
 Modifica: ficheros Datos.txt y calleMasBares.txt
 Fecha:18/5/2020
 Autor:Victor Valdes
 *********************************************************************************************/
void Algoritmos::barrioMasBares() {
	int iBares=0;
	int iBares1=0;
	ListaPI<via> *pVia,*pViaMas;
	barrio barrioMas;

	ofstream fichero1("Datos.txt",std::ofstream::out | std::ofstream::app);
	ofstream fichero("calleMasBares.txt");

//		if ((!fichero.is_open()) !! (!fichero1.is_open()))
//				cout<<"El fichero calleMasBares.txt o Datos.txt, no se puede abrir"<<endl;
//		else
		if (fichero.is_open())
			if (fichero1.is_open())
			if (!bBares->empty()) {
				fichero<<"ALGORITMO 7 Barrio con más bares:";
				fichero1<<"ALGORITMO 7 Barrio con más bares:";

				barrios.moverInicio();
				barrios.consultar(bTemp);
				while (barrios.finLista()==false) {
					pVia=bTemp.getVia();
					if (pVia) {
						iBares1=baresVias(pVia);
						if (iBares1>iBares) { //Si es el que más tiene almaceno barrio
							pViaMas=pVia;
							iBares=iBares1;
							barrioMas=bTemp;
						}
					}
					barrios.avanzar();
					barrios.consultar(bTemp);
				}


				if (iBares) {
					fichero<<barrioMas.getNombreBarrio()<<" nº de bares:"<<iBares<<endl;
					fichero1<<barrioMas.getNombreBarrio()<<" nº de bares:"<<iBares<<endl;

					//Escribimos los bares
					baresBarrios(&barrioMas,fichero);
				}
				fichero<<endl;
				fichero1<<endl;

				fichero.close();
				fichero1.close();
			}
}



/********************************************************************************************
  Algoritmos::~Algoritmos()
   metodo main del programa, punto de entrada de ejecución
 Fecha:26/3/2020
 Autor:Victor Valdes
   Libera memoria de listas de barrios,vias y bares
 *********************************************************************************************/
Algoritmos::~Algoritmos() {

    //  TODO liberar memoria
	barrios.~ListaPI();
	vias.~ListaPI();
	bares.~ListaPI();

	if (bBares!=NULL)
		delete bBares;
    if (baresOrdenada!=NULL)
    	delete baresOrdenada;


}


