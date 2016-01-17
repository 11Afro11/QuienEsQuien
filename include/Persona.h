//Definición de la clase Persona
//Personas.h
#ifndef PERSONAS_H
#define PERSONAS_H
#include <string>
#include <vector>
#include <iostream>
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
		string get_name(){
			return name;
		}
		string get_path(){
			return path_imagen;
		}
		void set_name(string n){
			name = n;
		}
		void set_path(string p){
			path_imagen = p;
		}
		void set_info(vector<int> v){
			info = v;
		}
		int& operator [] (int indice){
			return info[indice];
		}
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

};
istream& operator >> (istream &flujo, Persona &p);
ostream& operator << (ostream &flujo, Persona &p);
#endif
