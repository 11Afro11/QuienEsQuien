//Prueba de arboles binarios

#include <iostream>
#include <cstdlib>
#include <ArbolGeneral.h>

using namespace std;

int main(){
	nodo <int> n;
	n.etiqueta = 5;
	n.izqda = 0;
	n.drcha = 0;
	n.padre = 0;
	
	ArbolGeneral AG;
	ArbolGeneral AG2;

	AG.AsignaRaiz(n);
	cout << AG.padre();
	AG2 = AG;
	AG.insertar_hijosmasizquierda(n,AG2);
	AG.insertar_hermanoderecha(n,AG2);

	cout << AG;

	iter_preorden it;
	it = AG.begin();
}