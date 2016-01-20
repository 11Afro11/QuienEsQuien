#include <iostream>
#include <fstream>
#include "Pregunta.h"
#include "ConjuntoPreguntas.h"

using namespace std;

int main(int argc, char const *argv[])
{
	ConjuntoPreguntas conj;
	ifstream fin ("caras1.txt");
//	creacion de una pregunta

	fin >> conj;



	cout << "Hace la entrada\n";
	cout << conj.Size();
	/*
	for(int i = 0; i < conj.Size();i++){
		cout << conj[i];
	}*/
	
	Pregunta p;
	p.setPregunta("Pregunta uno");
	conj.Add(p);
	p.setPregunta("Pregunta dos");
	//conj.Add(p);
	cout << conj;
	//cout << conj;



	return 0;
}

