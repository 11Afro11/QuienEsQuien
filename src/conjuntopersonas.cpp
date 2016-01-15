//conjuntopersonas.cpp
  ///////////////////////////////////////
 ////////REVISAR LOS INCLUDES///////////
///////////////////////////////////////

#include "conjuntopersonas.h"
#include <iostream>

conjuntopersonas::conjuntopersonas(vector<persona> v){
	per = v;
}
void conjuntopersonas::aniade_persona(persona p){
	per.push_back(p);
}
string conjuntopersonas :: get_name(int indice){
	if(indice >= 0 && indice < per.size()){
		return per[indice].get_name();
	}
}
string conjuntopersonas :: get_path(int indice){
	if(indice >= 0 && indice < per.size()){
		return per[indice].get_path();
	}
}
void conjuntopersonas :: borra_persona(int indice){
	if(indice >= 0 && indice < per.size()){
		per.erase(per.begin() + indice);
	}
}
void conjuntopersonas :: del(persona p){
	//Busca persona
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

ostream& operator << (ostream &flujo, conjuntopersonas &conj){
	
	for(int i = 0; i < conj.get_size(); i++){
		persona p;
		p = conj.get_persona(i);
		flujo << p;
	}
}
istream& operator >> (istream &flujo, conjuntopersonas &conj){
	
	string aux; //Guarda el contenido de una linea del flujo de entrada
	persona p;
	int n_per = 0;
	//Hay que situar el flujo en el primer nombre

	while(aux != "#PERSONAJES"){
		getline(flujo,aux);
	}
	
	char n[1];
	getline(flujo, aux);
	int i = 0;
	//Obtener el numero de personajes
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

		conj.aniade_persona(p);
	}	
	
}
