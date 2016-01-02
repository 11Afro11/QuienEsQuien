#ifndef CONJUNTOPREGUNTAS
#define CONJUNTOPREGUNTAS

#include <vector>
#include <cassert>
/**
* @file ConjuntoPreguntas.h
* @brief Clase ConjuntoPregunta, en ella abstraemos el TDA Conjuntostringcon los siguientes atributos:
*Segun mi definicion del TDA Conjuntostringse compone de un map de int Pregunta
**/
class ConjuntoPreguntas{
private:
	vector<string> preguntas;

/**
* @brief Reserva
* @se encarga de reservar memoria para el vector dinamico de preguntas
* @param tam: tamaño de memoria a reservar
**/
	// void Reserva(int tam);
/**
* @brief Copia
*copia los datos de un conjunto a otro
* @param otro: stringa copiar
**/
	void Copia(const ConjuntoPreguntas & otro);
/**
* @brief Borra
*Borra la memoria reservada
**/
	// void Borra();
public:

/**
* @brief ConjuntoPreguntas
*Constructor por defecto
**/
	ConjuntoPreguntas(){}
/**
* @brief ConjuntoPreguntas
*Constructor de copia
* @param otro: conjunto a copiar
**/
	ConjuntoPreguntas(const ConjuntoPreguntas & otro);
/**
* @brief ~ConjuntoPreguntas Destructor
**/
	// ~ConjuntoPreguntas();
/**
* @brief Operador de acceso, Devuelve el valor del vector en la posicion deseada, este operador permite modificacion
* @param num: posicion del vector que queremos consultar
* @return string&
**/
	string& operator [] (const int num);
/**
* @brief Operador de acceso. Devuelve el valor del vector en la posicion deseada, este operador NO permite modificacion
* @param num: posicion del vector que queremos consultar
* @return string&
**/
	const string& operator [] (const int num)const;

/**
* @brief Esta
* Metodo que comprueba si una stringse encuentra en el conjunto
* @param nueva: stringque comprobamos
* @return true | false
**/
	bool Esta(const string& nueva);
/**
* @brief Size
*Devuelve el tamaño utilizado del conjunto
* @returnt tamaño del conjunto(int)
**/
	int Size()const;

/**
* @brief Sobrecarga del operador de entrada
*lee un conjunto de un flujo de entrada
* @param is: flujo de entrada
* @param conj: conjunto a leer
* @return devuelve una referencia al flujo de entrada
**/
	friend istream & operator >> (istream & is, ConjuntoPreguntas & conj);
/**
* @brief Sobrecarga del operador de salida
*lee una stringde un flujo de salida
* @param os: flujo de salida
* @param conj: conjunto a escribir
* @return devuelve una referencia al flujo de salida
**/
	friend ostream & operator << (ostream & os, ConjuntoPreguntas & conj);

};
/**
* @brief Sobrecarga del operador de entrada
*lee un conjunto de un flujo de entrada
* @param is: flujo de entrada
* @param conj: conjunto a leer
* @return devuelve una referencia al flujo de entrada
**/
istream & operator >> (istream & is, ConjuntoPreguntas & conj);
/**
* @brief Sobrecarga del operador de salida
*lee una stringde un flujo de salida
* @param os: flujo de salida
* @param conj: conjunto a escribir
* @return devuelve una referencia al flujo de salida
**/
ostream & operator << (ostream & os, ConjuntoPreguntas & conj);
#endif