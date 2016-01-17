#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include "ArbolGeneral.h"
#include "ConjuntoPersonas.h"
#include "Pregunta.h"
// #include "QuitaComentarios.h"
#include "ConjuntoPreguntas.h"
#include "Persona.h"

using namespace std;
  
  
int main(int argc,char *argv[]){
    
  if ((argc!=2)){
      cout<<"Dime el nombre del fichero de configuracion"<<endl;
  
      return 0;
  }
  ifstream f(argv[1],ios::in);
  // QuitaComentarios(f);
  
  Pregunta ask;
  f>>ask;
  
  
  Persona People;
  f>>People;
  
  
  // QuitaComentarios(f);
  string str;
  //Leemos el fichero con el arbol
  
  f>>str;
  //Abrimos el fichero con el arbol
  ifstream farbol(str.c_str());
  if (!farbol){
      cout<<"No puedo abrir el fichero "<<str<<endl;
  }
  ArbolGeneral<int> ab;
  farbol>>ab;
  cout<<"Leido el arbol con las descripciones de los personajes"<<endl;
  
  
  //recorremos en postorden el arbol
  ArbolGeneral<int>::iter_preorden it_tree=ab.begin();
  
  while (it_tree!=ab.end()){
  
    if (it_tree.Hoja() && (*it_tree)!=-1){
      ArbolGeneral<int>::Nodo nod = it_tree.GetNodo();
      cout<<"***************\nPersonaje: "<<People.GetPersona(*it_tree).GetNombre()<<endl;
      cout<<"Preguntas y contestaciones son:"<<endl;
      Pregunta::iterator itask=ask.end(); --itask;
      
      Pregunta::iterator itask_prev=ask.end();
      string codigo(ask.NumPreguntas(),'0');
      int pos = ask.NumPreguntas()-1;
      do{
	cout<<(*itask);
	if (nod==ab.hijomasizquierda(ab.padre(nod))){
	  cout<<"Si"<<endl;
	  codigo[pos]='1';
	}  
	else{ 
	  cout<<"No"<<endl;
	  codigo[pos]='0';
	  
	} 
	itask_prev=itask;
       --itask;	
        pos--;
	nod=ab.padre(nod);
      }while (itask_prev!=ask.begin());
      cout<<"Codigo asociado "<<codigo<<endl;
      //Le ponemos al personaje el codigo
      People.GetPersona(*it_tree).SetCodigoRespuestas(codigo);
      
      
    }
    
    ++it_tree;
  }
  
  
	
}
    
    
