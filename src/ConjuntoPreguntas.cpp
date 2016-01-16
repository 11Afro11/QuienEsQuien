#include "ConjuntoPreguntas.h"
#include <iostream>
#include <cstring>
using namespace std;

/*
class ConjuntoPreguntas{
private:

	string * preguntas
		int num_preguntas;
	int tam;
*/

	void ConjuntoPreguntas::Copia(const ConjuntoPreguntas & otro){
		preguntas = otro.preguntas;

	}

//public:

	ConjuntoPreguntas::ConjuntoPreguntas(const ConjuntoPreguntas & otro){
		Copia(otro);
	}



	Pregunta & ConjuntoPreguntas::operator [](const int num){
		return preguntas[num];
	}
	/*
	const Pregunta & ConjuntoPreguntas::operator [](const int num)const{
  		return preguntas[num];
	}
	*/
/*
	void ConjuntoPreguntas::Add(const string & nueva){

		preguntas. = nueva;
		num_preguntas++;
	}*/

/*	bool ConjuntoPreguntas::Esta(const string & nueva){
		for(int i = 0; i < Size(); i++){
			if(preguntas[i] == nueva){
				return true;
			}
		}
		return false;
	}*/

	int ConjuntoPreguntas::Size()const{
		return preguntas.size();
	}

	void ConjuntoPreguntas::Borra_preg(int indice){
		vector<Pregunta>:: iterator it = preguntas.begin();
		preguntas.erase(it + indice);
	}
	void ConjuntoPreguntas::del(Pregunta p){
		//Comprobar el indice de la pregunta
		bool notfound = true;
		int i;
		for(i = 0; i < preguntas.size() && notfound; i++){
			if(preguntas[i] == p){
				notfound = false;
			}
		}
		vector<Pregunta>::iterator it = preguntas.begin();
		if(!notfound){
			preguntas.erase(it + i);
		}
	}

//};
/*
istream & operator >> (istream & is, ConjuntoPreguntas & conj){
	string preg;
	getline(is, preg)
	int num;
	cin >> num;
	getline(is,preg);
	for(int i = 0; i < num; i++){
		getline(is, preg);
		preguntas.push_back();
	}
	return is;
}


ostream & operator << (ostream & os, ConjuntoPreguntas & conj){
	for(int i = 0; i < conj.Size(); i++){
		os << conj[i]<<endl;
	}
	return os;
}

*/