//Definición de la clase persona
//Personas.h
#ifndef PERSONAS_H
#define PERSONAS_H
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class persona{
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
		persona(vector<int> v, string n, string path){
			if(v.size() == 17){
				info = v;
				name = n;
				path_imagen = path;
			}
		}
		persona(){
		}
		/*
		/@brief A continuación se define un método que responde a las reguntas
		*que se hacen acerca de la persona.
		*@param Se le pasa como parámetro la pregunta, codificada con un número.
		*@return Devuelve verdadero o falso según si encaja el personaje con la 
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
		

};
istream& operator >> (istream &flujo, persona &p);
ostream& operator << (ostream &flujo, persona &p);
#endif
