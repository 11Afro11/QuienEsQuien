


//Esbozo algoritmo discriminante


#include "ConjuntoPreguntas.h"
#include "ConjuntoPersonajes.h"

string Discriminar(ConjuntoPreguntas preguntas, ConjuntoPersonajes personas){
	int si = 0;
	int no = 0;

	int maximo = 0;
	string max;
	int discriminator;

	for(int i = 0; i < 17; i++){
		for(int j = 0; j < preguntas.Size(); i++){
			if(personas[j][i] == 1){
				si++;
			}
			else{
				no++;
			}
		}
		si = si/17;
		no = no/17;
		discriminator = si*log2(si) - no * log2(no);

		if(discriminator > maximo){
			maximo = discriminator;
			max = preguntas[i];
		}
	}
	return max;
}