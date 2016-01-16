//Prueba de arboles binarios

#include <iostream>
#include <cstdlib>
#include <fstream>
#include "ArbolGeneral.h"

using namespace std;

int main(int arcg, char *argv[]){
	
	ifstream fin ("conjunto_no_minimal.tree");
	
	ArbolGeneral<int> AG;
	ArbolGeneral<int> AG2;

	fin >> AG;
	//AG.AsignaRaiz(n);
	//cout << AG.padre();
	AG2 = AG;
	if(AG == AG2){
		cout << "El operador de asignacion es correcto\n";
	}
	ArbolGeneral<int>::iter_preorden it;
	//AG.insertar_hijosmasizquierda(n,AG2);
	//AG.insertar_hermanoderecha(n,AG2);
	typename ArbolGeneral<int>::Nodo n;
	//ArbolGeneral<int>::nodo n1;
	n = AG.raiz();
	//n->etiqueta = 5;
	
	AG2.asignar_subarbol(AG,n);
	//ArbolGeneral<int>::iter_preorden it;
	//it = AG.begin();
	n = AG2.raiz();
	//Podar no funciona
	AG2.podar_hijomasizquierda(n,AG2);
	//AG2.podar_hermanoderecha(n,AG2);
	//AG2.clear();
	if(AG2.empty()== true){
		cout << AG2.size();
	}
	cout << "\n"<<AG2.size();
	cout << AG2;
}