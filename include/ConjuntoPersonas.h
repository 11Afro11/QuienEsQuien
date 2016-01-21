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
		/**
		*@brief Constructor con parámetro.
		**/
		ConjuntoPersonas(vector<Persona> v);
		/**
		*@brief Constructor sin parámetro
		**/
		ConjuntoPersonas(){
		}
		/**
		*@brief Devuelve la persona que ocupa la posición indice
		*@param El índice del del personaje al que queremos acceder
		*@return Devuelve una persona
		**/
		Persona get_Persona(int indice){
			if(indice >= 0  && indice <per.size()){
				return per[indice];
			}
		}
		/**
		*@brief Añade una persona al vector de personas
		*@param Persona que deseamos añadir
		**/
		void aniade_Persona(Persona p);
		//Estos métodos no son esenciales
		//////////////////////////////
		/**
		*@brief Devuelve el nombre de la persona que ocupa el índice indicado en el vector.
		*@param Índice de la persona
		*@return Nombre de la persona
		**/
		string get_name(int indice);
		/**
		*@brief Devuelve el path de la foto del personaje pasado como índice
		*@param Índice de la persona
		*@return Path de la foto de la persona
		**/
		string get_path(int indice);
		/////////////////////////////
		/**
		*@brief Devuelve el tamaño del conjunto de preguntas
		*@return Entero con el tamaño de la pregunta
		**/

		int get_size(){
			return per.size();
		}

		//Añadir operator [] const y no const
		/**
		*@brief Devuelve la persona en el índice indicado
		/@param Índice de la persona
		*@return Persona en el índice indicado
		**/
		Persona& operator [](int indice){
			return per[indice];
		}
		/*
		const Persona& operator[](int indice){
			return get_Persona(indice);
		}
		*/
		/**
		*@brief Borra la persona que ocupa el índice pasado como parámetro
		*@param Índice de la pregunta
		**/
		void borra_Persona(int indice);
		/**
		*@brief Borra la persona que se le pasa como parámetro
		*@param Persona a borrar
		**/
		void del (Persona p);
		/**
		*@brief Sobrecarga del operador de entrada
		*@param &flujo: flujo de entrada
		*@param &conj: ConjuntoPersonas al que se redirige la entrada
		*@return flujo de entrada
		**/
		friend ostream& operator << (ostream &flujo, ConjuntoPersonas &conj);
		/**
		*@brief Sobrecarga del operador de salida
		*@param &flujo: flujo de salida
		*@param &conj: ConjuntoPersonas a imprimir
		*@return devuelve un flujo a  salida
		**/
		friend istream& operator >> (istream &flujo, ConjuntoPersonas &conj);

};

#endif