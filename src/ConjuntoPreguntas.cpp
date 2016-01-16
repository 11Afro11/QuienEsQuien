#include "ConjuntoPreguntas.h"
#include <iostream>
#include <Pregunta>
using namespace std;

/*
class ConjuntoPreguntas{
private:

	Pregunta * preguntas
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

	const Pregunta & ConjuntoPreguntas::operator [](const int num)const{
  		return preguntas[num];
	}
/*
	void ConjuntoPreguntas::Add(const Pregunta & nueva){

		preguntas. = nueva;
		num_preguntas++;
	}*/

/*	bool ConjuntoPreguntas::Esta(const Pregunta & nueva){
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
		preguntas.erase(indice);
	}
	void del(Pregunta p){
		//COmpribar el indice de la pregunta
		bool notfound = true;
		int i;
		for(i = 0; i < preguntas.size() && notfound; i++){
			if(preguntas[i] == p){
				notfound = false;
			}
		}
		if(!notfound){
			preguntas.erase(i);
		}
	}

//};

istream & operator >> (istream & is, ConjuntoPreguntas & conj){
	Pregunta preg;
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

