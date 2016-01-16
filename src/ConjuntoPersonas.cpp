//ConjuntoPersonas.cpp
  ///////////////////////////////////////
 ////////REVISAR LOS INCLUDES///////////
///////////////////////////////////////

#include "ConjuntoPersonas.h"
#include <iostream>

ConjuntoPersonas::ConjuntoPersonas(vector<Persona> v){
	per = v;
}
void ConjuntoPersonas::aniade_Persona(Persona p){
	per.push_back(p);
}
string ConjuntoPersonas :: get_name(int indice){
	if(indice >= 0 && indice < per.size()){
		return per[indice].get_name();
	}
}
string ConjuntoPersonas :: get_path(int indice){
	if(indice >= 0 && indice < per.size()){
		return per[indice].get_path();
	}
}
void ConjuntoPersonas :: borra_Persona(int indice){
	if(indice >= 0 && indice < per.size()){
		per.erase(per.begin() + indice);
	}
}
void ConjuntoPersonas :: del(Persona p){
	//Busca Persona
	bool notfound = true;
	int i;
	for(i = 0; i < per.size() && notfound; i++){
		if(p == per[i]){
			notfound = false;
		}
	}
	if(!notfound){
		per.erase(i);
	}
}

ostream& operator << (ostream &flujo, ConjuntoPersonas &conj){
	
	for(int i = 0; i < conj.get_size(); i++){
		Persona p;
		p = conj.get_Persona(i);
		flujo << p;
	}
}
istream& operator >> (istream &flujo, ConjuntoPersonas &conj){
	
	string aux; //Guarda el contenido de una linea del flujo de entrada
	Persona p;
	int n_per = 0;
	//Hay que situar el flujo en el primer nombre

	while(aux != "#PERSONAJES"){
		getline(flujo,aux);
	}
	
	char n[1];
	getline(flujo, aux);
	int i = 0;
	//Obtener el numero de Personajes
	cout << aux;
	while(aux[i] != ' '){
		
		
		int digit;
		n[0] = aux[i];
		digit = atoi(n);
		n_per = n_per * 10 + digit;
		i++;
		
		
	}
	
	getline(flujo,aux);
	
	for(i = 0; i < n_per;i++){

		flujo >> p;

		conj.aniade_Persona(p);
	}	
	
}
