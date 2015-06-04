#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cubo.h"
//##########################CUBO MAGICO############################
bloco ***alocaCubo(){
	bloco ***cubo;
	int i, j, k, dim = 3;
	cubo = malloc(dim * sizeof(bloco **));
	for(i = 0; i < dim; i++){
		cubo[i] = malloc(dim * sizeof(bloco *));
		for(j = 0; j < dim; j++){
			cubo[i][j] = malloc(dim * sizeof(bloco));
			for(k=0; k < dim; k++){
				strcpy(cubo[i][j][k].frente, "");
				strcpy(cubo[i][j][k].lateral, "");
				strcpy(cubo[i][j][k].base, "");
			}
		}
	}

	return cubo;
	
}

void liberaCubo(bloco ***cubo){
	int i, j, dim = 3;	

	for(i=0; i < dim; i++){
		for(j=0; j < dim; j++){
			free(cubo[i][j]);
		}
		free(cubo[i]);
	}
	free(cubo);
}

void giraLinha(bloco ***cubo, int i, char sentido[3]){
	bloco auxiliar[3];
	int j;	
	if(i == 0){
		i = 2;
	}else if(i == 2){
		i = 0;
	}
	for(j=0; j<3; j++){
		strcpy(auxiliar[j].frente,  cubo[0][i][j].frente);
		strcpy(auxiliar[j].lateral, cubo[0][i][j].lateral);
		strcpy(auxiliar[j].base,    cubo[0][i][j].base);
	}
	if(strcmp(sentido, "Di")==0){
		strcpy(cubo[0][i][2].frente,  cubo[0][i][0].lateral);
		strcpy(cubo[0][i][2].lateral, cubo[0][i][0].frente);
		strcpy(cubo[0][i][2].base,    cubo[0][i][0].base);
		
		strcpy(cubo[0][i][1].frente,  cubo[1][i][0].lateral);
		strcpy(cubo[0][i][1].lateral, cubo[1][i][0].frente);
		strcpy(cubo[0][i][1].base,    cubo[1][i][0].base);

		strcpy(cubo[0][i][0].frente,  cubo[2][i][0].lateral);
		strcpy(cubo[0][i][0].lateral, cubo[2][i][0].frente);
		strcpy(cubo[0][i][0].base,    cubo[2][i][0].base);

		strcpy(cubo[1][i][0].frente,  cubo[2][i][1].lateral);
		strcpy(cubo[1][i][0].lateral, cubo[2][i][1].frente);
		strcpy(cubo[1][i][0].base,    cubo[2][i][1].base);

		strcpy(cubo[2][i][0].frente,  cubo[2][i][2].lateral);
		strcpy(cubo[2][i][0].lateral, cubo[2][i][2].frente);
		strcpy(cubo[2][i][0].base,    cubo[2][i][2].base);

		strcpy(cubo[2][i][1].frente,  cubo[1][i][2].lateral);
		strcpy(cubo[2][i][1].lateral, cubo[1][i][2].frente);
		strcpy(cubo[2][i][1].base,    cubo[1][i][2].base);
			
		strcpy(cubo[2][i][2].frente,  auxiliar[2].lateral);
		strcpy(cubo[2][i][2].lateral, auxiliar[2].frente);
		strcpy(cubo[2][i][2].base,    auxiliar[2].base);

		strcpy(cubo[1][i][2].lateral, auxiliar[1].frente);
		strcpy(cubo[1][i][2].frente,  auxiliar[1].lateral);
		strcpy(cubo[1][i][2].base,    auxiliar[1].base);
	}else{
		strcpy(cubo[0][i][0].lateral, cubo[0][i][2].frente);
		strcpy(cubo[0][i][0].frente,  cubo[0][i][2].lateral);
		strcpy(cubo[0][i][0].base,    cubo[0][i][2].base);

		strcpy(cubo[0][i][1].lateral, cubo[1][i][2].frente);
		strcpy(cubo[0][i][1].frente,  cubo[1][i][2].lateral);
		strcpy(cubo[0][i][1].base,    cubo[1][i][2].base);

		strcpy(cubo[0][i][2].lateral, cubo[2][i][2].frente);
		strcpy(cubo[0][i][2].frente,  cubo[2][i][2].lateral);
		strcpy(cubo[0][i][2].base,    cubo[2][i][2].base);

		strcpy(cubo[1][i][2].lateral, cubo[2][i][1].frente);
		strcpy(cubo[1][i][2].frente,  cubo[2][i][1].lateral);
		strcpy(cubo[1][i][2].base,    cubo[2][i][1].base);

		strcpy(cubo[2][i][2].lateral, cubo[2][i][0].frente);
		strcpy(cubo[2][i][2].frente,  cubo[2][i][0].lateral);
		strcpy(cubo[2][i][2].base,    cubo[2][i][0].base);

		strcpy(cubo[2][i][1].lateral, cubo[1][i][0].frente);
		strcpy(cubo[2][i][1].frente,  cubo[1][i][0].lateral);
		strcpy(cubo[2][i][1].base,    cubo[1][i][0].base);
			
		strcpy(cubo[2][i][0].frente,  auxiliar[0].lateral);
		strcpy(cubo[2][i][0].lateral, auxiliar[0].frente);
		strcpy(cubo[2][i][0].base,    auxiliar[0].base);

		strcpy(cubo[1][i][0].lateral, auxiliar[1].frente);
		strcpy(cubo[1][i][0].frente,  auxiliar[1].lateral);
		strcpy(cubo[1][i][0].base,    auxiliar[1].base);

	}
}

void giraColuna(bloco ***cubo, int i, char sentido[3]){
	bloco auxiliar[3];
	int j;
	for(j=0; j<3; j++){
		strcpy(auxiliar[j].frente,  cubo[0][j][i].frente);
		strcpy(auxiliar[j].lateral, cubo[0][j][i].lateral);
		strcpy(auxiliar[j].base,    cubo[0][j][i].base);
	}
	if(strcmp(sentido, "Ci")==0){
		strcpy(cubo[0][0][i].frente,   cubo[0][2][i].base);
		strcpy(cubo[0][0][i].base,     cubo[0][2][i].frente);
		strcpy(cubo[0][0][i].lateral,  cubo[0][2][i].lateral);

		strcpy(cubo[0][1][i].frente,   cubo[1][2][i].base);
		strcpy(cubo[0][1][i].base,     cubo[1][2][i].frente);
		strcpy(cubo[0][1][i].lateral,  cubo[1][2][i].lateral);
			
		strcpy(cubo[0][2][i].frente,   cubo[2][2][i].base);
		strcpy(cubo[0][2][i].base,     cubo[2][2][i].frente);
		strcpy(cubo[0][2][i].lateral,  cubo[2][2][i].lateral);

		strcpy(cubo[1][2][i].frente,   cubo[2][1][i].base);
		strcpy(cubo[1][2][i].base,     cubo[2][1][i].frente);
		strcpy(cubo[1][2][i].lateral,  cubo[2][1][i].lateral);

		strcpy(cubo[2][2][i].frente,   cubo[2][0][i].base);
		strcpy(cubo[2][2][i].base,     cubo[2][0][i].frente);
		strcpy(cubo[2][2][i].lateral,  cubo[2][0][i].lateral);

		strcpy(cubo[2][1][i].frente,   cubo[1][0][i].base);
		strcpy(cubo[2][1][i].base,     cubo[1][0][i].frente);
		strcpy(cubo[2][1][i].lateral,  cubo[1][0][i].lateral);

		strcpy(cubo[2][0][i].base,     auxiliar[0].frente);
		strcpy(cubo[2][0][i].frente,   auxiliar[0].base);
		strcpy(cubo[2][0][i].lateral,  auxiliar[0].lateral);

		strcpy(cubo[1][0][i].base,     auxiliar[1].frente);
		strcpy(cubo[1][0][i].frente,   auxiliar[1].base);
		strcpy(cubo[1][0][i].lateral,  auxiliar[1].lateral);
	}else{
		strcpy(cubo[0][2][i].base,     cubo[0][0][i].frente);
		strcpy(cubo[0][2][i].frente,   cubo[0][0][i].base);
		strcpy(cubo[0][2][i].lateral,  cubo[0][0][i].lateral);

		strcpy(cubo[0][1][i].base,     cubo[1][0][i].frente);
		strcpy(cubo[0][1][i].frente,   cubo[1][0][i].base);
		strcpy(cubo[0][1][i].lateral,  cubo[1][0][i].lateral);
			
		strcpy(cubo[0][0][i].base,     cubo[2][0][i].frente);
		strcpy(cubo[0][0][i].frente,   cubo[2][0][i].base);
		strcpy(cubo[0][0][i].lateral,  cubo[2][0][i].lateral);

		strcpy(cubo[1][0][i].base,     cubo[2][1][i].frente);
		strcpy(cubo[1][0][i].frente,   cubo[2][1][i].base);
		strcpy(cubo[1][0][i].lateral,  cubo[2][1][i].lateral);

		strcpy(cubo[2][0][i].base,     cubo[2][2][i].frente);
		strcpy(cubo[2][0][i].frente,   cubo[2][2][i].base);
		strcpy(cubo[2][0][i].lateral,  cubo[2][2][i].lateral);

		strcpy(cubo[2][1][i].base,     cubo[1][2][i].frente);
		strcpy(cubo[2][1][i].frente,   cubo[1][2][i].base);
		strcpy(cubo[2][1][i].lateral,  cubo[1][2][i].lateral);

		strcpy(cubo[2][2][i].base,     auxiliar[2].frente);
		strcpy(cubo[2][2][i].frente,   auxiliar[2].base);
		strcpy(cubo[2][2][i].lateral,  auxiliar[2].lateral);

		strcpy(cubo[1][2][i].base,     auxiliar[1].frente);
		strcpy(cubo[1][2][i].frente,   auxiliar[1].base);
		strcpy(cubo[1][2][i].lateral,  auxiliar[1].lateral);
	}
}

void giraCubo(bloco ***cubo, char sentido[3]){
	int i;
	if(strcmp(sentido, "Es")==0 || strcmp(sentido, "Di")==0){
		for(i=0; i<3; i++){
			giraLinha(cubo, i, sentido);
		}
	}else{
		for(i=0; i<3; i++){
			giraColuna(cubo, i, sentido);
		}
	}	
	
}

void lerFace(FILE *arq, bloco ***cubo){
	int j, k;
	for(j=0; j<3; j++){
		for(k=0; k<3; k++){
			fscanf(arq," %s", &cubo[0][j][k].frente[0]);
		}
	}
}

void lerCubo(FILE *arq, bloco ***cubo){	
	lerFace(arq, cubo);
	giraCubo(cubo, "Di");
	lerFace(arq, cubo);
	giraCubo(cubo, "Di");
	lerFace(arq, cubo);
	giraCubo(cubo, "Di");
	lerFace(arq, cubo);
	giraCubo(cubo, "Di");
	giraCubo(cubo, "Ba");
	lerFace(arq, cubo);
	giraCubo(cubo, "Ci");
	giraCubo(cubo, "Ci");
	lerFace(arq, cubo);
	giraCubo(cubo, "Ba");
}

void mostraFace(bloco ***cubo){
	int j, k;
	for(j=0; j<3; j++){
		for(k=0; k<3; k++){
			printf("%s ", cubo[0][j][k].frente);
		}
		printf("\n");
	}
	printf("\n");
}

void escreveFace(FILE *arq, bloco ***cubo){
	int j, k;
	for(j=0; j<3; j++){
		for(k=0; k<3; k++){
			fprintf(arq,"%s\n", cubo[0][j][k].frente);
		}
	}
	//fprintf(arq, "\n");
}
void mostrarCubo1( bloco ***cubo){	
	mostraFace(cubo);
	printf("\n");
	giraCubo(cubo, "Di");
	mostraFace(cubo);
	printf("\n");
	giraCubo(cubo, "Di");
	mostraFace(cubo);
	printf("\n");
	giraCubo(cubo, "Di");
	mostraFace(cubo);
	printf("\n");
	giraCubo(cubo, "Di");
	giraCubo(cubo, "Ba");
	mostraFace(cubo);
	printf("\n");
	giraCubo(cubo, "Ci");
	giraCubo(cubo, "Ci");
	mostraFace(cubo);
	printf("\n");
	giraCubo(cubo, "Ba");
}

void mostrarCubo(FILE *arq, bloco ***cubo){
	mostraFace(cubo);
	escreveFace(arq, cubo);
	fprintf(arq, "\n");
	printf("\n");
	giraCubo(cubo, "Di");
	mostraFace(cubo);
	escreveFace(arq, cubo);
	fprintf(arq, "\n");
	printf("\n");
	giraCubo(cubo, "Di");
	mostraFace(cubo);
	escreveFace(arq, cubo);
	fprintf(arq, "\n");
	printf("\n");
	giraCubo(cubo, "Di");
	mostraFace(cubo);
	escreveFace(arq, cubo);
	fprintf(arq, "\n");
	printf("\n");
	giraCubo(cubo, "Di");
	giraCubo(cubo, "Ba");
	mostraFace(cubo);
	escreveFace(arq, cubo);
	fprintf(arq, "\n");
	printf("\n");
	giraCubo(cubo, "Ci");
	giraCubo(cubo, "Ci");
	mostraFace(cubo);
	escreveFace(arq, cubo);
	printf("\n");
	giraCubo(cubo, "Ba");
}

void giraFace(bloco ***cubo, char sentido[3]){

	giraCubo(cubo, "Es");
	if(strcmp(sentido, "Di") == 0){
		giraColuna(cubo, 0, "Ba");
	}else{
		giraColuna(cubo, 0, "Ci");
	}
	giraCubo(cubo, "Di");
}

/*int isDigit(char text[10]){
	int i=0, result = 1;
	while(text[i] != '\0'){
		if(!(text[i] > '0' && text[i] < '9')){
			return 0;
		}
		i++;
	}
	return result;
}*/

/*void operacao( bloco ***cubo){
	FILE *arq = fopen("cubo.txt", "r");
	FILE *arq2 = fopen("operacoes.txt", "r");
	FILE *saida = fopen("saida.txt", "w");
	char operacao[10];
	int idCubo=0;
	char sentido[3], val[1], opr[3];
	while(fscanf(arq2, " %s", operacao) != EOF){
		if(isDigit(operacao)){
			if(idCubo > 0){
				printf("%d\n", idCubo);
				fprintf(saida,"%d\n", idCubo);
				mostrarCubo(saida, cubo);
				fprintf(saida,"\n");
			}
			lerCubo(arq, cubo, &idCubo);
		}else{
			opr[0] = operacao[0];
			opr[1] = operacao[1];
			opr[2] = '\0';
			if(strcmp(opr, "Cl")==0){ // Função rotaciona coluna
				val[0] = operacao[2];
				int coluna = atoi(val);
				sentido[0] = operacao[3];
				sentido[1] = operacao[4];
				sentido[2] = '\0';
				giraColuna(cubo, coluna, sentido);
			}else if(strcmp(opr, "Fa")==0){//Função rotaciona face
				sentido[0] = operacao[2];
				sentido[1] = operacao[3];
				sentido[2] = '\0';
				giraFace(cubo, sentido);
			}else if(strcmp(opr, "Cb")==0){//Fução rotaciona cubo
				sentido[0] = operacao[2];
				sentido[1] = operacao[3];
				sentido[2] = '\0';
				giraCubo(cubo, sentido);
			}else if(strcmp(opr, "Li")==0){//Função rotaciona linha
				val[0] = operacao[2];
				int linha = atoi(val);
				sentido[0] = operacao[3];
				sentido[1] = operacao[4];
				sentido[2] = '\0';
				giraLinha(cubo, linha, sentido);
			}
		}
	}
	printf("%d\n", idCubo);
	fprintf(saida, "%d\n", idCubo);
	mostrarCubo(saida, cubo);
	fclose(arq);
	fclose(arq2);
	fclose(saida);

}*/

/*void main(){
	bloco ***cubo;
	cubo = alocaCubo();
	operacao(cubo);
	liberaCubo(cubo);
}*/

