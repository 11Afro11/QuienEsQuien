//Clase conjunto de Personas
//Esta clase define un conjuto de Personas y permite acceder a la información de cada uno de ellos
//ConjuntoPersonas.h
#ifndef CONJUNTOPERSONAS_H
#define CONJUNTOPERSONAS_H


#include <cstdlib>
#include "Persona.h"
using namespace std;

class ConjuntoPersonas{
	private:
		vector<Persona> per;
	public:
		ConjuntoPersonas(vector<Persona> v);
		ConjuntoPersonas(){

		}
		Persona get_Persona(int indice){
			if(indice >= 0  && indice <per.size()){
				return per[indice];
			}
		}
		void aniade_Persona(Persona p);
		//Estos métodos no son esenciales
		//////////////////////////////
		string get_name(int indice);
		string get_path(int indice);
		/////////////////////////////
		int get_size(){
			return per.size();
		}

		//Añadir operator [] const y no const
		Persona& operator [](int indice){
			return per[indice];
		}
		/*
		const Persona& operator[](int indice){
			return get_Persona(indice);
		}
		*/
		void borra_Persona(int indice);
		void del (Persona p);

};
ostream& operator << (ostream &flujo, ConjuntoPersonas &conj);
istream& operator >> (istream &flujo, ConjuntoPersonas &conj);
#endif