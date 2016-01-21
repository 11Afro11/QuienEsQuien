//Definición de la clase Persona
//Personas.h
#ifndef PERSONAS_H
#define PERSONAS_H
#include <string>
#include <vector>
#include <iostream>
#include "QuitaComentarios.h"
using namespace std;

class Persona{
	private:
		string name;
		vector<int> info;
		string path_imagen;
	public:
		/*
		*@brief constructor de Persona
		*@param Los parámetros de este constructor son todos 
		*los atributos privados de la clase Persona
		*/
		Persona(vector<int> v, string n, string path){
			if(v.size() == 17){
				info = v;
				name = n;
				path_imagen = path;
			}
		}
		Persona(){
		}
		/*
		/@brief A continuación se define un método que responde a las reguntas
		*que se hacen acerca de la Persona.
		*@param Se le pasa como parámetro la pregunta, codificada con un número.
		*@return Devuelve verdadero o falso según si encaja el Personaje con la 
		*pregunta hecha.
		*/
		int get_info(int codigo){
			if(codigo <= 16 && codigo >= 0){
				return info[codigo];
			}
		}
		/**
		*@brief Devuelve el nombre de la persona
		*@return string con el nombre de la persona
		**/
		string get_name(){
			return name;
		}
		/**
		*@brief Devuelve el path de la foto del personaje
		*@return string con el path de la foto 
		**/
		string get_path(){
			return path_imagen;
		}
		/**
		*@brief Inicializa el nombre de la persona
		*@param string con el nombre
		**/		
		void set_name(string n){
			name = n;
		}
		/**
		*@brief inicializa el path de la persona
		*@param string con el path
		**/
		void set_path(string p){
			path_imagen = p;
		}
		/**
		*@brief inicializa el info de la persona
		*@param vector<int> con la info
		**/
		void set_info(vector<int> v){
			info = v;
		}
		/**
		*@brief Devuelve el elemento i en el vector
		*@param Indice del vector
		*@return entero con el elemento del vector
		**/
		int& operator [] (int indice){
			return info[indice];
		}
		/**
		*@brief sobrecarga del operador de asiganación
		*@param Persona con la que se compara 
		*@return Devuelve true si son iguales y false en caso contrario
		**/
		bool operator == (Persona p){
			bool iguales = false;
			if(info == p.info){
				if(name == p.name){
					if(path_imagen == p.path_imagen){
						iguales = true;
					}
				}
			}
			return iguales;
		}
		/**
		*@brief Sobrecarga del operador >> de entrada
		*@param &flujo: flujo de enttrada
		*@param &p: Persona a escribir
		*@return Devuelve una referencia añ flijo de entrada
		**/
		friend istream& operator >> (istream &flujo, Persona &p);
		/**
		*@brief Sobrecarga del operador de salida
		*@param &flujo: flujo de salida
		*@param &p: persona a escribir
		*@return devuelve una referencia al flujo de salida
		**/
		friend ostream& operator << (ostream &flujo, Persona &p);

};

#endif
