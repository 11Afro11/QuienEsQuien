#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <unistd.h>
#include "ArbolGeneral.h"
#include "ConjuntoPersonas.h"
#include "Pregunta.h"
// #include "QuitaComentarios.h"
#include "ConjuntoPreguntas.h"
#include "Persona.h"

using namespace std;
  
  
int main(int argc,char *argv[]){
    
  if ((argc!=3)){
      cout<<"Dime el nombre del fichero de configuracion"<<endl;
  
      return 0;
  }
  ifstream f(argv[1],ios::in);
  // QuitaComentarios(f);
  // ifstream f2(argv[1],ios::in);
  
  ConjuntoPreguntas ask;
  f>>ask;
  cout << ask;
  
  ConjuntoPersonas People;
  f>>People;
  cout << People;
  
  
  // QuitaComentarios(f);
  // string str;
  //Leemos el fichero con el arbol
  
  // cin>>str;
  //Abrimos el fichero con el arbol
  ifstream farbol(argv[2]);
  if (!farbol){
      cout<<"No puedo abrir el fichero "<<endl;
  }
  ArbolGeneral<int> ab;
  cout << "\nhe llegado\n";
  farbol>>ab;
  cout<<"Leido el arbol con las descripciones de los personajes"<<endl;
  
  
  //recorremos en postorden el arbol
  ArbolGeneral<int>::iter_preorden it_tree=ab.begin();
  
  while (it_tree!=ab.end()){
  	// cout << ab;
  	/*cout << it_tree.Hoja()<<" ";
  	cout <<(*it_tree)<<endl;*/
    if (it_tree.Hoja() /*&& (*it_tree)!=-1*/){
    	cout << "despues de if\n";
      ArbolGeneral<int>::Nodo nod = it_tree.GetNodo();
      cout<<"***************\nPersonaje: "<<People[*it_tree].get_name()<<endl;
      cout<<"Preguntas y contestaciones son:"<<endl;
 /*     ConjuntoPreguntas::iterator itask=ask.end(); --itask;
      
      ConjuntoPreguntas::iterator itask_prev=ask.end();*/
      vector<int> codigo;
      int pos = ask.Size()-1;
      do{
	cout<<ask[pos];
	if (nod==ab.hijomasizquierda(ab.padre(nod))){
	  cout<<"Si"<<endl;
	  codigo.push_back(1);
	}  
	else{ 
	  cout<<"No"<<endl;
	  codigo.push_back(0);
	  
	} 
/*	itask_prev=itask;
       --itask;*/	
        pos--;
	nod=ab.padre(nod);
      }while (pos!=0);
      // cout<<"Codigo asociado "<<codigo<<endl;
      //Le ponemos al personaje el codigo
      People[*it_tree].set_info(codigo);
      
      
    }
    
    ++it_tree;
    /*cout << "me cagoentoooooooooo"<<endl;
    cout << (*it_tree);*/
    // sleep(1);
  }
  
  
	
}
    
    
