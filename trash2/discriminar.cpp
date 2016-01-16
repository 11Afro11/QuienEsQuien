//Prueba de la funcion de discriminar
#include "personas.h"
#include "ConjuntoPreguntas.h"
#include "conjuntopersonas.h"
#include "Pregunta.h"
#include <string>
#include <cmath>
#include <iostream>
Pregunta Discriminar(ConjuntoPreguntas preguntas, conjuntopersonas personas){
	int si = 0;
	int no = 0;

	int maximo = 0;
	Pregunta max;
	int discriminator;

	for(int i = 0; i < 3; i++){
		for(int j = 0; j < personas.get_size(); i++){
			if(personas[j][i] == 1){
				si++;
			}
			else{
				no++;
			}
		}
		si = si/3;
		no = no/3;
		discriminator = si*(log(si)/log(2)) - no * (log(no)/log(2));

		if(discriminator > maximo){
			maximo = discriminator;
			max = preguntas[i];
		}
	}
	return max;
}

int main(){
	ConjuntoPreguntas preguntas;
	conjuntopersonas personajes;

	//Creacion de 3 presonas
	std::vector<int> v;
	for(int i = 0; i < 3; i++){
		v.push_back(0);
	}
	persona p(v,"pepe","/unadireccion");
	personajes.aniade_persona(p);

	for(int i = 0;i < 3; i++){
		v[i] = 1;
	}
	persona p2(v,"juan","otradireccion");
	personajes.aniade_persona(p2);

	for(int i = 0; i < 3; i++){
		v[i] = i%2;
	}
	persona p3(v,"un tio","una dereccion");
	personajes.aniade_persona(p3);

	//Creacion de 3 preguntas

	Pregunta preg;
	preg.setPregunta("pre1");
	preg.setNum(0);
	Pregunta preg2;
	preg2.setPregunta("pre2");
	preg2.setNum(1);
	Pregunta preg3;
	preg3.setPregunta("pregunta 3");
	preg3.setNum(2);
	ConjuntoPreguntas cp;
	cp.insert(preg);
	cp.insert(preg2);
	cp.insert(preg3);

	//cout << Discriminar(cp,personajes);



}