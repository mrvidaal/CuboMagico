#include <stdio.h>
#include <stdlib.h>
#ifndef CUBO_H

	#define CUBO_H

	typedef struct {
		char frente[3];
		char lateral[3];
		char base[3];
	}bloco;


	bloco ***alocaCubo();

	void liberaCubo(bloco ***cubo);

	void giraLinha(bloco ***cubo, int i, char sentido[3]);

	void giraColuna(bloco ***cubo, int i, char sentido[3]);

	void giraCubo(bloco ***cubo, char sentido[3]);

	void lerFace(FILE *arq, bloco ***cubo);

	void lerCubo(FILE *arq, bloco ***cubo);

	void mostraFace(bloco ***cubo);

	void escreveFace(FILE *arq, bloco ***cubo);

	void mostrarCubo(FILE *arq, bloco ***cubo);
	
	void mostrarCubo1(bloco ***cubo);

	void giraFace(bloco ***cubo, char sentido[3]);

#endif