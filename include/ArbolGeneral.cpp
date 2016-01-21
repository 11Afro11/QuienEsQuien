    ////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////
    ///////////////Clae arbol general/////////////////////////////
    /////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////
/**
      * @brief Destruye el subárbol
      * @param n Nodo a destruir, junto con sus descendientes
      *
      * Libera los recursos que ocupan \e n y sus descendientes.
      */
    template<class T>
    void ArbolGeneral<T> :: destruir(nodo * n){
      if(n != 0){
        destruir(n->izqda);
        destruir(n->drcha);
      }
    }
    
    /**
      * @brief Copia un subárbol
      * @param dest Referencia al puntero del que cuelga la copia
      * @param orig Puntero a la raíz del subárbol a copiar
      *
      * Hace una copia de todo el subárbol que cuelga de \e orig en el puntero
      * \e dest. Es importante ver que en \e dest->padre (si existe) no se 
      * asigna ningún valor, pues no se conoce.
      */
    template<class T>
    void ArbolGeneral<T> :: copiar(nodo *& dest, nodo * orig){
      if(orig == 0){
        dest = 0;
      }
      else{
        dest = new nodo;
        dest->etiqueta = orig->etiqueta;
        dest->padre = orig->padre;
        dest->izqda = orig->izqda;
        dest->drcha = orig->drcha;
        copiar(dest->izqda, orig->izqda);
        copiar(dest->drcha, orig->drcha);
      }
    }
      
    /**
      * @brief Cuenta el número de nodos
      * @param n Nodo del que cuelga el subárbol de nodos a contabilizar.
      *
      * Cuenta cuántos nodos cuelgan de \e n, incluido éste.
      */
    template<class T>
    int ArbolGeneral<T> :: contar(const nodo * n) const{
      if(n == 0){
        return 0;
      }
      else{
        return 1 + +contar(n->izqda)+contar(n->drcha);
      }
    }
    
    /**
      * @brief Comprueba igualdad de dos subárboles
      * @param n1 Primer subárbol a comparar
      * @param n2 Segundo subárbol a comparar
      *
      * Comprueba si son iguales los subárboles que cuelgan de \e n1 y \e n2. 
      * Para ello deberán tener los mismos nodos en las mismas posiciones y 
      * con las mismas etiquetas.
      */
    template<class T>
    bool ArbolGeneral<T> :: soniguales(const nodo * n1, const nodo * n2) const{
      if(n1 == 0 && n2 == 0){
        return true;
      }
      else if(n1 == 0 || n2 == 0){
        return false;
      }
      else if(n1->etiqueta != n2->etiqueta){
        return false;
      }
      else if(!soniguales(n1->izqda, n2->izqda)){
        return false;
      }
      else if(!soniguales(n1->drcha, n2->drcha)){
        return false;
      }
      else
        return true;
    }
    
    /**
      * @brief Escribe un subárbol
      * @param out Stream de salida donde escribir
      * @param nod Nodo del que cuelga el subárbol a escribir
      *
      * Escribe en el flujo de salida todos los nodos del subárbol que cuelga 
      * del nodo \e nod siguiendo un recorrido en preorden. La forma de 
      * impresión de cada nodo es:
      *
      * - Si el nodo es nulo, imprime el carácter 'x'.
      * - Si el nodo no es nulo, imprime el carácter 'n' seguido de un 
      * espacio, al que sigue la impresión de la etiqueta
      */
    template<class T>
    void ArbolGeneral<T> :: escribe_arbol(std::ostream& out, nodo * nod) const{
      if(nod == 0){
        out << "x";
      }
      else{
        out<<"n "<<nod->etiqueta<<" ";
        escribe_arbol(out, nod->izqda);
        escribe_arbol(out, nod->drcha);
      }
    }
    
    /**
      * @brief Lee un subárbol
      * @param in Stream de entrada desde el que leer
      * @param nod Referencia al nodo que contendrá el subárbol leído
      *
      * Lee del flujo de entrada \e in los elementos de un árbol según el 
      * formato que se presenta en la función de escritura.
      *
      * @see escribe_arbol
      */
    template<class T>
    void ArbolGeneral<T> :: lee_arbol(std::istream& in, nodo *& nod){
      char letra;
      letra=in.get();
      //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
      //He sustituido c por letra
      //if(c == 'n')
      if(letra == 'n'){
        nod = new nodo;
	nod->padre=0;
	nod->drcha=0; 
	nod->izqda=0;
        in >> nod->etiqueta;
        lee_arbol(in, nod->izqda);
        lee_arbol(in, nod->drcha);
        if(nod->izqda != 0){
          nod->izqda->padre = nod;
           nodo * aux = nod->izqda;
           while (aux->drcha!=0){
        
              aux ->drcha->padre = nod;
              aux =aux->drcha;
           }
        }
           
      }
      else if (letra=='x')
        nod = 0;
      else in.get();
    }

    /**
      * @brief Constructor por defecto
      *
      * Reserva los recursos e inicializa el árbol a vacío {}. La operación se
      * realiza en tiempo O(1).
      */
    template<class T>
    ArbolGeneral<T> :: ArbolGeneral(){
      laraiz = 0;
    }
    
    /**
      * @brief Constructor de raíz
      * @param e Etiqueta de la raíz
      *
      * Reserva los recursos e inicializa el árbol con un único nodo raíz que 
      * tiene la etiqueta \e e, es decir, el árbol {e, {}, {}}. La operación 
      * se realiza en tiempo O(1).
      */
    template<class T>
    ArbolGeneral<T> :: ArbolGeneral(const T& e){
      laraiz = new nodo;
      laraiz->padre = laraiz->izqda = laraiz->drcha = 0;
      laraiz->etiqueta = e;
    }
    
    /**
      * @brief Constructor de copias
      * @param v ArbolGeneral a copiar
      *
      * Construye el árbol duplicando el contenido de \e v en el árbol 
      * receptor.
      * La operación se realiza en tiempo O(n), donde \e n es el número
      * de elementos de \e v.
      */
    template<class T>
    ArbolGeneral<T> :: ArbolGeneral (const ArbolGeneral<T>& v){
      copiar(laraiz, v.laraiz);
      if(laraiz!=0){
        laraiz->padre = 0;
      }
    }

    /**
      * @brief Destructor
      *
      * Libera los recursos ocupados por el árbol receptor. La operación se 
      * realiza en tiempo O(n), donde n es el número de elementos del árbol 
      * receptor.
      */
    template<class T>
    ArbolGeneral<T> :: ~ArbolGeneral(){
      destruir(laraiz);
    }
    
    /**
      * @brief Operador de asignación
      * @param v ArbolGeneral a copiar
      * @return Referencia al árbol receptor.
      *
      * Asigna el valor del árbol duplicando el contenido de \e v en el árbol 
      * receptor.
      * La operación se realiza en tiempo O(n), donde \e n es el número de 
      * elementos de \e v.
      */
    template<class T>
    ArbolGeneral<T>& ArbolGeneral<T> :: operator = (const ArbolGeneral<T> &v){
      if(this != &v){
        destruir(laraiz);
        copiar(laraiz, v.laraiz);
        if(laraiz!=0)
          laraiz->padre = 0;
      }
      return *this;
    }
    
    /**
      * @brief Asignar nodo raíz
      * @param e Etiqueta a asignar al nodo raíz
      *
      * Vacía el árbol receptor y le asigna como valor el árbol de un único 
      * nodo cuya etiqueta es \e e.
      */
    template<class T>
    void ArbolGeneral<T> :: AsignaRaiz(const T& e){
      destruir(laraiz);
      laraiz = new nodo;
      laraiz->padre = laraiz->izqda = laraiz->drcha = 0;
      laraiz->etiqueta = e;
    }
    
    /**
      * @brief Raíz del árbol
      * @return Nodo raíz del árbol receptor
      *
      * Devuelve el nodo raíz, que es 0 (nulo) si el árbol está vacío.
      * La operación se realiza en tiempo O(1).
      */

      //!!!!!!!!!!!!!!!!!!!!!!!!!1
      //Faltaba poner ArbolGeneral<T>:: antes de Nodo
    template<class T>
    typename ArbolGeneral<T>::Nodo ArbolGeneral<T> :: raiz() const{
      return laraiz;
    }
    
    /**
      * @brief Hijo más a la izquierda
      * @param n Nodo del que se quiere obtener el hijo más a la izquierda.
      * @pre \e n no es nulo
      * @return Nodo hijo más a la izquierda
      *
      * Devuelve el nodo hijo más a la izquierda de \e n, que valdrá 0 (nulo) 
      * si no tiene hijo más a la izquierda.
      * La operación se realiza en tiempo O(1).
      */
    template<class T>
     typename ArbolGeneral<T>::Nodo ArbolGeneral<T>:: hijomasizquierda(const typename ArbolGeneral<T>::Nodo n) const{
      assert(n != 0);
      return n->izqda;
    }
    
    /**
      * @brief Hermano derecha
      * @param n Nodo del que se quiere obtener el hermano a la derecha.
      * @pre \e n no es nulo
      * @return Nodo hermano a la derecha
      *
      * Devuelve el nodo hermano a la derecha de \e n, que valdrá 0 (nulo) 
      * si no tiene hermano a la derecha.
      * La operación se realiza en tiempo O(1).
      */
    template<class T>

    typename ArbolGeneral<T>::Nodo ArbolGeneral<T>:: hermanoderecha(const Nodo n) const{
      assert(n != 0);
      return n->drcha;
    }
    
    /**
      * @brief Nodo padre
      * @param n Nodo del que se quiere obtener el padre.
      * @pre \e n no es nulo
      * @return Nodo padre
      *
      * Devuelve el nodo padre de \e n, que valdrá 0 (nulo) si es la raíz.
      * La operación se realiza en tiempo O(1).
      */
    template<class T>
    typename ArbolGeneral<T>::Nodo ArbolGeneral<T>:: padre(const Nodo n) const{
      assert(n != 0);
      return n->padre;
    }
    
    /**
      * @brief Etiqueta de un nodo
      * @param n Nodo en el que se encuentra el elemento.
      * @pre \e n no es nulo
      * @return Referencia al elemento del nodo \e n
      *
      * Devuelve una referencia al elemento del nodo \e n y por tanto se puede 
      * modificiar o usar el valor.
      * La operación se realiza en tiempo O(1).
      */
    template<class T>
    T& ArbolGeneral<T> :: etiqueta(const Nodo n){
      assert(n != 0);
      return n->etiqueta;
    }
    
    /**
      * @brief Etiqueta de un nodo
      * @param n Nodo en el que se encuentra el elemento.
      * @pre \e n no es nulo
      * @return Referencia constante al elemento del nodo \e n.
      *
      * Devuelve una referencia al elemento del nodo \e n. Es constante y por 
      * tanto no se puede modificiar el valor.
      * La operación se realiza en tiempo O(1).
      */
    template<class T>
    const T& ArbolGeneral<T> :: etiqueta(const Nodo n) const{
      assert(n != 0);
      return n->etiqueta;
    }
    
    /**
      * @brief Copia subárbol
      * @param orig Árbol desde el que se va a copiar una rama
      * @param nod Nodo raíz del subárbol que se copia. 
      * @pre \e nod es un nodo del árbol \e orig y no es nulo
      *
      * El árbol receptor acaba con un valor copia del subárbol que cuelga del 
      * nodo \e nod en el árbol \e orig. La operación se realiza en tiempo
      * O(n), donde \e n es el número de nodos del subárbol copiado.
      */
    template<class T>
    void ArbolGeneral<T> :: asignar_subarbol(const ArbolGeneral<T>& orig, const Nodo nod){
      destruir(laraiz);
      copiar(laraiz, nod);
      if(laraiz != 0)
        laraiz->padre = 0;
    }
    
    /**O
      * @brief Podar subárbol hijo más a la izquierda
      * @param n Nodo al que se le podará la rama hijo más a la izquierda. 
      * @param dest Árbol que recibe la rama cortada
      * @pre \e n no es nulo y es un nodo válido del árbol receptor.
      *
      * Asigna un nuevo valor al árbol \e dest, con todos los elementos del 
      * subárbol izquierdo del nodo \e n en el árbol receptor. Éste se queda 
      * sin dichos nodos.
      *  La operación se realiza en tiempo O(1).
      */
    template<class T>
    void ArbolGeneral<T> :: podar_hijomasizquierda(Nodo n, ArbolGeneral<T>& dest){
      assert(n != 0);
      Nodo res = 0;
      if(n->izqda != 0){
        res = n->izqda;
        n->izqda = res->drcha;
        res->padre = res->drcha = 0;
      }
    }
    
    /**
      * @brief Podar subárbol hermano derecha
      * @param n Nodo al que se le podará la rama hermano derecha. 
      * @param dest Árbol que recibe la rama cortada
      * @pre \e n no es nulo y es un nodo válido del árbol receptor.
      *
      * Asigna un nuevo valor al árbol \e dest, con todos los elementos del 
      * subárbol hermano derecho del nodo \e n en el árbol receptor. Éste se 
      * queda sin dichos nodos.
      * La operación se realiza en tiempo O(1).
      */
    template<class T>
    void ArbolGeneral<T>:: podar_hermanoderecha(Nodo n, ArbolGeneral<T>& dest){
      assert(n != 0);
      destruir(dest.laraiz);
      dest.laraiz = n->drcha;
      if(dest.laraiz != 0){
        dest.laraiz->padre = 0;
        n->drcha = 0;
      }
    }
    
    /**
      * @brief Insertar subárbol hijo más a la izquierda
      * @param n: Nodo al que se insertará el árbol \e rama como hijo más a la 
      * izquierda.
      * @param rama Árbol que se insertará como hijo más a la izquierda.
      * @pre \e n no es nulo y es un nodo válido del árbol receptor
      *
      * El árbol \e rama se inserta como hijo más a la izquierda del nodo \e n
      * del árbol receptor. El árbol \e rama queda vacío y los nodos que 
      * estaban en el subárbol hijo más a la izquierda de \e n se desplazan a 
      * la derecha, de forma que el anterior hijo más a la izquierda pasa a ser
      * el hermano a la derecha del nuevo hijo más a la izquierda.
      */
    template<class T>
    void ArbolGeneral<T> :: insertar_hijomasizquierda(Nodo n, ArbolGeneral<T>& rama){
      assert(n!=0);

      if(!rama.empty()){
        rama.laraiz->drcha = n->izqda;
        rama.laraiz->padre = n;
        n->izqda = rama.laraiz;
        rama.laraiz = 0;
      }
    }

    /**
      * @brief Insertar subárbol hermano derecha
      * @param n Nodo al que se insertará el árbol \e rama como hermano a la 
      * derecha. 
      * @param rama Árbol que se insertará como hermano derecho.
      * @pre \e n no es nulo y es un nodo válido del árbol receptor
      *
      * El árbol \e rama se inserta como hermano derecho del nodo \e n del 
      * árbol receptor. El árbol \e rama queda vacío y los nodos que estaban a 
      * la derecha del nodo \e n pasan a la derecha del nuevo nodo.
      */
    template<class T>
    void ArbolGeneral<T> :: insertar_hermanoderecha(Nodo n, ArbolGeneral<T>& rama){
      assert(n != 0);
      if(!rama.empty()){
        rama.laraiz->drcha = n->drcha;
        rama.laraiz->padre = n->padre;
        n->drcha = rama.laraiz;
        rama.laraiz = 0;
      }
    }
    
    /**
      * @brief Borra todos los elementos
      *
      * Borra todos los elementos del árbol receptor. Cuando termina, el árbol
      * está vacía. La operación se realiza en tiempo O(n), donde \e n es el 
      * número de elementos del árbol receptor.
      */
    template<class T>
    void ArbolGeneral<T> :: clear(){
      destruir(laraiz);
      laraiz = 0;
    }
    
    /**
      * @brief Número de elementos
      * @return El número de elementos del árbol receptor.
      *
      * La operación se realiza en tiempo O(n).
      * @see contar
      */
    template<class T>
    int ArbolGeneral<T> :: size() const{
      return contar(laraiz);
    }
    
    /**
      * @brief Vacío
      * @return Devuelve \e true si el número de elementos del árbol receptor 
      * es cero, \e false en caso contrario.
      *
      * La operación se realiza en tiempo O(1).
      */
    template<class T>
    bool ArbolGeneral<T> :: empty() const{
      return laraiz == 0;
    }
    
    /**
      * @brief Operador de comparación (igualdad)
      * @param v ArbolGeneral con el que se desea comparar.
      * @return Devuelve \e true si el árbol receptor tiene los mismos
      * elementos y en el mismo orden, \e false en caso contrario.
      *
      * La operación se realiza en tiempo O(n).
      * @see soniguales
      */
    template<class T>
    bool ArbolGeneral<T> :: operator == (const ArbolGeneral<T>& v) const{
      return soniguales(laraiz, v.laraiz);
    }
    
    /**
      * @brief Operador de comparación (diferencia)
      * @param v ArbolGeneral con el que se desea comparar.
      * @return Devuelve \e true si el árbol receptor no tiene los mismos 
      * elementos y en el mismo orden, \e false en caso contrario.
      *
      * La operación se realiza en tiempo O(n).
      */
    template<class T>
    bool ArbolGeneral<T> :: operator != (const ArbolGeneral<T>& v) const{
      return !(*this==v);
    }
      
    /**
      * @brief Operador de extracción de flujo
      * @param in Stream de entrada
      * @param v Árbol que leer
      * @return Referencia al stream de entrada
      *
      * Lee de \e in un árbol y lo almacena en \e v. El formato aceptado para
      * la lectura se puede consultar en la función de salida.
      * @see lee_arbol
      */
    template<class T>
    std::istream& operator>>(std::istream& in, ArbolGeneral<T>& v){
      v.lee_arbol(in, v.laraiz);
      return in;
    }
    /**
      * @brief Operador de inserción en flujo
      * @param out Stream de salida
      * @param v Árbol que escribir
      * @return Referencia al stream de salida
      *
      * Escribe en la salida todos los nodos del árbol \e v siguiendo un 
      * recorrido en preorden. La forma de impresión de cada nodo es:
      *
      * - Si el nodo es nulo, imprime el carácter 'x'.
      * - Si el nodo no es nulo, imprime el carácter 'n' seguido de un 
      * espacio, al que sigue la impresión de la etiqueta.
      *
      * @see escribe_arbol
      */
    template<class T>
    std::ostream& operator<< (std::ostream& out, const ArbolGeneral<T>& v){
      v.escribe_arbol(out, v.laraiz);
      return out;
    }
    
    ////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////
    ///////////////Iterador no constante//////////////////////////
    /////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////
    
    /** 
     * @brief TDA. Iterador del ArbolGeneral  en preorden
     * */
   /**
    * @brief Constructor por defecto
    * 
    * */
   template<class T>
   ArbolGeneral<T>::iter_preorden::iter_preorden(){
      it = typename ArbolGeneral<T>::Nodo();
      raiz = it;
      level = 0;
   }
   
   /**
    * @brief Obtiene la etiqueta del nodo
    * 
    * */
     template<class T>
   T& ArbolGeneral<T>::iter_preorden:: operator*(){
    return it->etiqueta;
   }
   
   
   /**
    * @brief Obtiene el nivel del nodo
    * 
    * */
  template<class T>
   
   int ArbolGeneral<T>::iter_preorden :: getlevel()const{
    return level;
   }
     
   /**
    * @brief Compara dos iteradores
    * @param i: iterador con el  que se compara
    * @return true si los dos iteradores son iguales (la raiz y el nodo son iguales). False en caso contrario
    * */
  template<class T>

   bool ArbolGeneral<T>::iter_preorden :: operator == (const iter_preorden &i){
    return it == i.it;
   }
        
   /**
    * @brief Compara dos iteradores
    * @param i: iterador con el  que se compara
    * @return true si los dos iteradores son diferentes (la raiz o  el nodo son diferentes). False en caso contrario
    * */
  template<class T>
   bool ArbolGeneral<T>::iter_preorden::operator != (const iter_preorden &i){
    return !(it == i.it);
   }
   ///////////////////////////////////////////////////////////////////////////////////
   //////////////////////////////////////////////////////////////////////////////////
   /////////////////////////////////////////////////////////////////////////////////
   ////////////////////////////////////////////////////////////////////////////////
   ///////////////////////////////////////////////////////////////////////////////
   ///////////////////////Iterador constante/////////////////////////////////////
   /////////////////////////////////////////////////////////////////////////////
   ////////////////////////////////////////////////////////////////////////////
  template<class T>
   //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
   //Faltaba poner <T> al lado de ArbolGeneral
   //ArbolGeneral::const_iter_preorden :: const_iter_preorden()
   ArbolGeneral<T>::const_iter_preorden :: const_iter_preorden(){
    it = 0;
    raiz = 0;
    level = -1;
   }
   /**
    * @brief Obtiene la etiqueta del nodo
    * 
    * */
  template<class T>
   //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //Faltaba el <T> al lado de ArbolGeneral
   const T& ArbolGeneral<T>::const_iter_preorden::operator*() {
    return it->elemento;
   }
     
   
   /**
    * @brief Obtiene el nivel del nodo
    * 
    * */
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
   //}
  template<class T>
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //Faltaba el <T>
   int ArbolGeneral<T>::const_iter_preorden :: getlevel()const{
    return level;
   }
     
   /**
    * @brief Obtiene un iterador al siguiente nodo segun el recorrido en preorden
    * 
    * */
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
   //}
  //template<class T>
   /**
    * @brief Compara dos iteradores
    * @param i: iterador con el con que se comparación
    * @return true si los dos iteradores son iguales (la raiz y el nodo son iguales). False en caso contrario
    * */
  template<class T>
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //Faltaba el <T>
   bool ArbolGeneral<T>::const_iter_preorden:: operator == (const const_iter_preorden &i){
    return it == i.it;
   }
        
   /**
    * @brief Compara dos iteradores
    * @param i: iterador con el con que se comparación
    * @return true si los dos iteradores son diferentes (la raiz o  el nodo son diferentes). False en caso contrario
    * */
  template<class T>
   
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!1
    //Falta el <T>
   bool ArbolGeneral<T>::const_iter_preorden:: operator != (const const_iter_preorden &i){
    return!(it == i.it);
   }
   template<class T>
   typename ArbolGeneral<T>::const_iter_preorden & ArbolGeneral<T>::const_iter_preorden :: operator ++(){
         if (it->izqda!=0){
        it= it->izqda;
        level = level+1; 
      } 
      else{
    if (it->drcha!=0)
      it=it->drcha;
    else{
     if (it->padre!=0){
       while  (it->padre!=0 && it->drcha==0){
        it=it->padre;
        level = level-1;
       }
       it=it->drcha;
        
     }
     else{
       it=0;
       level = -1;
     }
    }  
      }
      return *this;
   }  
   //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
   //Las 2 lineas de abajo sobraban
   //friend class ArbolGeneral;
    //};
    

    /**
     * @brief Inicializa un iterador a la raiz del arbol. Nivel -1
     */
    template<class T>
     typename ArbolGeneral<T>::iter_preorden ArbolGeneral<T> :: begin(){
      typename ArbolGeneral<T>::iter_preorden iter;
      iter.it = laraiz;
      iter.raiz = laraiz;
      iter.level = 0;
      return iter;

     }
     template <class T>
     typename ArbolGeneral<T>::const_iter_preorden ArbolGeneral<T> :: begin()const  {
      typename ArbolGeneral<T>::const_iter_preorden iter;
      iter.it = laraiz;
      iter.raiz = laraiz;
      iter.level = 0;
      return iter;
     } 
     
     
    /**
     * @brief Inicializa un iterador al nodo nulo con la raiz del arbol. Nivel -1
     */
    template<class T>
     typename ArbolGeneral<T>::iter_preorden ArbolGeneral<T>::end(){
      typename ArbolGeneral<T>::iter_preorden iter;
      iter.it = 0;
      iter.raiz = laraiz;
      iter.level = 0;
      return iter;
     }
     template <class T>
     typename ArbolGeneral<T>::const_iter_preorden ArbolGeneral<T>::end()const{
      typename ArbolGeneral<T>::const_iter_preorden iter;      
      iter.it = 0;
      iter.raiz = laraiz;
      iter.level = 0;
      return iter;
     }

    
//};
