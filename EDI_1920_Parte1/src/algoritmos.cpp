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
int iOpccion,iMas,iCodigoBarrio,iCodigoBarrioMas;
string strNombre,strNombre1;
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
    cargarDatos();
    run();
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

}


