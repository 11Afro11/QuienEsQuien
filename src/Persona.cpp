//personas.cpp
#include "Persona.h"

istream& operator >> (istream &flujo, Persona &p){
	//Como antes de cada nombre hay una linea con '#'
	string aux;
	//getline(flujo,aux);
	/*while(aux[0] != '#' && aux[0] != '\n'){
		getline(flujo,aux);
	}*/
	QuitaComment(flujo);
	//Asi se situa el flujo en la linea donde aparece el nombre
	string name;
	string path_imagen;

	getline(flujo, name, '\n');
	getline(flujo, path_imagen,'\n');
	p.set_name(name);
	p.set_path(path_imagen);
	QuitaComment(flujo);
	return flujo;

}
ostream& operator << (ostream &flujo, Persona &p){
	flujo << p.get_name();
	return flujo;
}