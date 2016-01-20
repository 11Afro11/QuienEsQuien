#include "Pregunta.h"
#include <iostream>
#include <sstream>
using namespace std;

/*#ifndef Pregunta
#define Pregunta

class Pregunta{
private:
	string pregunta;
	int num;
	string *respuestas;
*/
	

	void Pregunta::Copia(const Pregunta &otra_pregunta){
		pregunta = otra_pregunta.pregunta;
	}
//private:
	Pregunta::Pregunta(){ 
		pregunta = "";
	}

/*	Pregunta::Pregunta(string ask, int num_resp, string* resp){
		pregunta = ask;
		num = num_resp;
		// Reserva(num_resp);
		for(int i = 0; i < num; i++){
			respuestas.push_back(resp[i]);
		}
	}*/

	Pregunta::Pregunta(const Pregunta &otra_pregunta){
		Copia(otra_pregunta);
	}

/*	Pregunta :: ~Pregunta(){
		Borra();
	}*/

	string Pregunta::getPregunta()const{
		return pregunta;
	}

	void Pregunta::setPregunta(string ask){
		pregunta = ask;
	}



	Pregunta & Pregunta::operator = (const Pregunta & otra)
	{
	    if (this != &otra) { // Evitar autoasignación
	
	        // Libera la memoria ocupada
	
	        // Copia el contenido de la matriz y los campos privados
	        Copia(otra);
	    }
	    return (*this);  // Objeto implicito: parte
	                     // izquierda de la asignación
	}

	bool Pregunta::operator == (const Pregunta &otra)const{
		if(pregunta != otra.pregunta){
			return false;
		}/*

		for(int i = 0; i < num; i++){
			for(int j = 0; j < num; j++){
				if(respuestas[i] != otra.respuestas[j]){
					return false;
				}
			}
		}*/
		return true;
	}

	istream & operator >> (istream & is, Pregunta & una_pregunta){
		string texto;
		getline(is, texto);
		una_pregunta.setPregunta(texto);
		return is;
	}

	ostream & operator << (ostream & os, const Pregunta & una_pregunta){
		os << una_pregunta.getPregunta()<<endl;
	}

