//Clase conjunto de personas
//Esta clase define un conjuto de personas y permite acceder a la información de cada uno de ellos
//conjuntopersonas.h
#ifndef CONJUNTOPERSONAS_H
#define CONJUNTOPERSONAS_H


#include <cstdlib>
#include "personas.h"
using namespace std;

class conjuntopersonas{
	private:
		vector<persona> per;
	public:
		conjuntopersonas(vector<persona> v);
		conjuntopersonas(){

		}
		persona get_persona(int indice){
			if(indice >= 0  && indice <per.size()){
				return per[indice];
			}
		}
		void aniade_persona(persona p);
		//Estos métodos no son esenciales
		//////////////////////////////
		string get_name(int indice);
		string get_path(int indice);
		/////////////////////////////
		int get_size(){
			return per.size();
		}

		void borra_persona(int indice);

};
ostream& operator << (ostream &flujo, conjuntopersonas &conj);
istream& operator >> (istream &flujo, conjuntopersonas &conj);
#endif