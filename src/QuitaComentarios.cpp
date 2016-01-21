#include "QuitaComentarios.h"
void QuitaComment(istream &is){
  cout<<is.peek()<<endl;
 while (is.peek()=='#' || is.peek()==' ' || is.peek()=='\n' ){
      if (is.peek()==' ') is.get();
      else{
	string a;
        getline(is,a);
      }
    }
}