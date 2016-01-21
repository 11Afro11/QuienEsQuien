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
	int i = 0;
	vector<Persona>::iterator it;

	for(it = per.begin(); it!=per.end() && notfound; ++it,i++){
		if(p == per[i]){
			notfound = false;
		}
	}
	if(!notfound){
		per.erase(it);
	}
}

ostream& operator << (ostream &flujo, ConjuntoPersonas &conj){
	
	for(int i = 0; i < conj.get_size(); i++){
		Persona p;
		p = conj.get_Persona(i);
		flujo << p;
		flujo <<endl;
	}
	return flujo;
}
	
istream& operator >> (istream &flujo, ConjuntoPersonas &conj){
	
	string aux; //Guarda el contenido de una linea del flujo de entrada
	Persona p;
	int n_per = 0;
	
	flujo>>n_per;
	cout<<"Numero de personas "<<n_per<<endl;
	QuitaComment(flujo);
	for(int i = 0; i < n_per;i++){
		flujo >> p;

		conj.aniade_Persona(p);
	}		
	  
	 cout<<"Numero de personas "<<conj.get_size()<<endl;
	/*
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
	}*/
	return flujo;
	
}
