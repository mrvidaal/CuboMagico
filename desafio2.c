#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cubo.h"
//Mauricio Roque Vidal - 2014.1.08.020
void procuraFace(FILE *out, bloco ***cubo){
	register int i;
	for(i=0; i<7; i++){
		if(!strcmp(cubo[0][1][1].frente, "am")){
			break;
		}else{
			if(i<4){
				fprintf(out, "CbDi\n");
				giraCubo(cubo, "Di");
			}else{
				fprintf(out, "CbCi\n");
				giraCubo(cubo, "Ci");
			}
		}
	}
}

void fazerCruz(FILE *out, bloco ***cubo){
	procuraFace(out, cubo);
	fprintf(out, "CbCi\n");
	giraCubo(cubo, "Ci");
	// Constroi a cruz em volta da cor amarela
	while(strcmp(cubo[0][0][1].base, "br") != 0 || strcmp(cubo[1][0][0].base, "br") != 0 
	   || strcmp(cubo[1][0][2].base, "br") != 0 || strcmp(cubo[2][0][1].base, "br") != 0){
		if(strcmp(cubo[0][0][1].frente, "br") == 0){
			fprintf(out, "FaEs\n");
			giraFace(cubo, "Es");
		}

		if(strcmp(cubo[0][2][1].frente, "br") == 0){
			if(strcmp(cubo[0][0][1].base, "br") != 0){
				fprintf(out, "FaEs\n");
				giraFace(cubo, "Es");
			}else{
				fprintf(out, "Li2Di\n");
				giraLinha(cubo, 2, "Di");
			}
		}

		if(strcmp(cubo[0][2][1].base, "br") == 0){
			if(strcmp(cubo[0][0][1].base, "br") != 0){
				fprintf(out, "FaDi\n");
				giraFace(cubo, "Di");
			}else{
				fprintf(out, "Li2Di\n");
				giraLinha(cubo, 2, "Di");
			}
		}

		if(strcmp(cubo[0][1][0].frente, "br") == 0){
			while(strcmp(cubo[1][0][0].base, "br") == 0){
				fprintf(out, "CbBa\n");
				giraCubo(cubo, "Ba");
				fprintf(out, "FaDi\n");
				giraFace(cubo, "Di");
				fprintf(out, "CbCi\n");
				giraCubo(cubo, "Ci");
			}
			fprintf(out, "Cl0Ci\n");
			giraColuna(cubo, 0, "Ci");
		}

		if(strcmp(cubo[0][1][2].frente, "br") == 0){
			while(strcmp(cubo[1][0][2].base, "br") == 0){
				fprintf(out, "CbBa\n");
				giraCubo(cubo, "Ba");
				fprintf(out, "FaDi\n");
				giraFace(cubo, "Di");
				fprintf(out, "CbCi\n");
				giraCubo(cubo, "Ci");
			}
			fprintf(out, "Cl2Ci\n");
			giraColuna(cubo, 2, "Ci");
		}
		fprintf(out, "CbDi\n");
		giraCubo(cubo, "Di");
	}

	//montar a cruz completa na cor branca
	while (strcmp(cubo[0][2][1].base, "br") != 0 || strcmp(cubo[1][2][0].base, "br") != 0 
	   || strcmp(cubo[1][2][2].base, "br") != 0 || strcmp(cubo[2][2][1].base, "br") != 0){
			
			if(strcmp(cubo[0][0][1].base, "br") == 0 ){
				while(strcmp(cubo[0][0][1].frente, cubo[0][1][1].frente) != 0){
					fprintf(out, "Li1Di\n");
					giraLinha(cubo, 1, "Di");
					fprintf(out, "Li0Di\n");
					giraLinha(cubo, 0, "Di");
				}
				fprintf(out, "FaDi\n");
				giraFace(cubo, "Di");
				fprintf(out, "FaDi\n");
				giraFace(cubo, "Di");
			}
			fprintf(out, "CbDi\n");
			giraCubo(cubo, "Di");
	}
}
 
 int linhaCompleta(bloco ***cubo, int linha){
	register int i;
	int result = 1;
	for(i=0; i<4; i++){
		if(strcmp(cubo[0][linha][1].frente, cubo[0][linha][0].frente) != 0 ||
			strcmp(cubo[0][linha][1].frente, cubo[0][linha][2].frente)){
			result = 0;
		}
		giraCubo(cubo, "Di");
	}
	return result;
}

int baseBrancaCompleta(bloco ***cubo){
	if(strcmp(cubo[0][2][0].base, "br") == 0 && strcmp(cubo[0][2][2].base, "br") == 0
	 &&strcmp(cubo[2][2][0].base, "br") == 0 && strcmp(cubo[2][2][2].base, "br") == 0
	 &&strcmp(cubo[0][2][1].base, "br") == 0 && strcmp(cubo[1][2][0].base, "br") == 0 
	 &&strcmp(cubo[1][2][2].base, "br") == 0 && strcmp(cubo[2][2][1].base, "br") == 0
	 &&linhaCompleta(cubo, 2)){
		return 1;
	}
	return 0;
}

void primeiraCamada(FILE *out, bloco ***cubo){
	while(!baseBrancaCompleta(cubo)){
		if(strcmp(cubo[0][0][2].base, "br") == 0){
			while(strcmp(cubo[0][0][2].frente, cubo[1][1][2].lateral) != 0){
				fprintf(out, "Li1Di\n");
				giraLinha(cubo, 1, "Di");
				fprintf(out, "Li0Di\n");
				giraLinha(cubo, 0, "Di");
			}
			fprintf(out, "FaEs\n");
			giraFace(cubo, "Es");
			fprintf(out, "Li2Di\n");
			giraLinha(cubo, 2, "Di");
			fprintf(out, "FaDi\n");
			giraFace(cubo, "Di");
		}
		
		if(strcmp(cubo[0][0][0].base, "br") == 0){
			while(strcmp(cubo[0][0][0].frente, cubo[1][1][0].lateral) != 0){
				fprintf(out, "Li1Di\n");
				giraLinha(cubo, 1, "Di");
				fprintf(out, "Li0Di\n");
				giraLinha(cubo, 0, "Di");
			}
			fprintf(out, "FaDi\n");
			giraFace(cubo, "Di");
			fprintf(out, "Li2Es\n");
			giraLinha(cubo, 2, "Es");
			fprintf(out, "FaEs\n");
			giraFace(cubo, "Es");
		}

		if(strcmp(cubo[0][2][0].frente, "br") == 0){
			fprintf(out, "FaDi\n");
			giraFace(cubo, "Di");
			fprintf(out, "Li2Es\n");
			giraLinha(cubo, 2, "Es");
			fprintf(out, "FaEs\n");
			giraFace(cubo, "Es");
		}

		if(strcmp(cubo[0][2][2].frente, "br") == 0){
			fprintf(out, "FaEs\n");
			giraFace(cubo, "Es");
			fprintf(out, "Li2Di\n");
			giraLinha(cubo, 2, "Di");
			fprintf(out, "FaDi\n");
			giraFace(cubo, "Di");
		}

		if(strcmp(cubo[0][0][2].frente, "br") == 0){
			while(strcmp(cubo[0][0][2].base, cubo[0][1][1].frente) != 0){
				fprintf(out, "Li1Di\n");
				giraLinha(cubo, 1, "Di");
				fprintf(out, "Li0Di\n");
				giraLinha(cubo, 0, "Di");
			}
			fprintf(out, "FaEs\n");
			giraFace(cubo, "Es");
			fprintf(out, "Li2Di\n");
			giraLinha(cubo, 2, "Di");
			fprintf(out, "FaDi\n");
			giraFace(cubo, "Di");
		}

		if(strcmp(cubo[0][0][0].frente, "br") == 0){
			while(strcmp(cubo[0][0][0].base, cubo[0][1][1].frente) != 0){
				fprintf(out, "Li1Di\n");
				giraLinha(cubo, 1, "Di");
				fprintf(out, "Li0Di\n");
				giraLinha(cubo, 0, "Di");
			}
			fprintf(out, "FaDi\n");
			giraFace(cubo, "Di");
			fprintf(out, "Li2Es\n");
			giraLinha(cubo, 2, "Es");
			fprintf(out, "FaEs\n");
			giraFace(cubo, "Es");
		}

		if(strcmp(cubo[0][2][0].base, "br") == 0){
			if(strcmp(cubo[0][2][0].frente, cubo[0][1][1].frente) != 0 
			|| strcmp(cubo[0][2][0].lateral, cubo[1][1][0].lateral) != 0 ){
				fprintf(out, "FaDi\n");
				giraFace(cubo, "Di");
				fprintf(out, "Li2Es\n");
				giraLinha(cubo, 2, "Es");
				fprintf(out, "FaEs\n");
				giraFace(cubo, "Es");
			}
		}

		if(strcmp(cubo[0][2][2].base, "br") == 0){
			if(strcmp(cubo[0][2][2].frente, cubo[0][1][1].frente) != 0 
			|| strcmp(cubo[0][2][2].lateral, cubo[1][1][2].lateral) != 0 ){
				fprintf(out, "FaEs\n");
				giraFace(cubo, "Es");
				fprintf(out, "Li2Di\n");
				giraLinha(cubo, 2, "Di");
				fprintf(out, "FaDi\n");
				giraFace(cubo, "Di");
			}
		}
		fprintf(out, "CbDi\n");
		giraCubo(cubo, "Di");
	}
}

void segundaCamada(FILE *out, bloco ***cubo){
	while(!linhaCompleta(cubo, 1)){
		if(strcmp(cubo[0][0][1].frente, "am") != 0 && strcmp(cubo[0][0][1].base, "am") != 0){
			while(strcmp(cubo[0][0][1].frente, cubo[0][1][1].frente) != 0){
				fprintf(out, "Li1Di\n");
				giraLinha(cubo, 1, "Di");
				fprintf(out, "Li0Di\n");
				giraLinha(cubo, 0, "Di");
			}
			if(strcmp(cubo[0][0][1].base, cubo[1][1][2].lateral) == 0){
				fprintf(out, "Li2Es\n");
				giraLinha(cubo, 2, "Es");
				fprintf(out, "Cl2Ci\n");
				giraColuna(cubo, 2, "Ci");
				fprintf(out, "Li2Es\n");
				giraLinha(cubo, 2, "Es");
				fprintf(out, "Cl2Ba\n");
				giraColuna(cubo, 2, "Ba");
				fprintf(out, "Li2Di\n");
				giraLinha(cubo, 2, "Di");
				primeiraCamada(out, cubo);
			}else{
				fprintf(out, "Li2Di\n");
				giraLinha(cubo, 2, "Di");
				fprintf(out, "Cl0Ci\n");
				giraColuna(cubo, 0, "Ci");
				fprintf(out, "Li2Di\n");
				giraLinha(cubo, 2, "Di");
				fprintf(out, "Cl0Ba\n");
				giraColuna(cubo, 0, "Ba");
				fprintf(out, "Li2Es\n");
				giraLinha(cubo, 2, "Es");
				primeiraCamada(out, cubo);
			}
		}else{
			if(strcmp(cubo[0][1][2].frente, cubo[0][1][1].frente) != 0  ||
			   strcmp(cubo[0][1][2].lateral, cubo[1][1][2].lateral) != 0){
				if(strcmp(cubo[0][1][2].frente, "am") != 0
				&& strcmp(cubo[0][1][2].lateral, "am") != 0){
					fprintf(out, "Li2Es\n");
					giraLinha(cubo, 2, "Es");
					fprintf(out, "Cl2Ci\n");
					giraColuna(cubo, 2, "Ci");
					fprintf(out, "Li2Es\n");
					giraLinha(cubo, 2, "Es");
					fprintf(out, "Cl2Ba\n");
					giraColuna(cubo, 2, "Ba");
					fprintf(out, "Li2Di\n");
					giraLinha(cubo, 2, "Di");
					primeiraCamada(out, cubo);
				}
				
			}else if (strcmp(cubo[0][1][0].frente, cubo[0][1][1].frente) != 0  ||
			          strcmp(cubo[0][1][0].lateral, cubo[1][1][0].lateral) != 0){
				if(strcmp(cubo[0][1][0].frente, "am") != 0
				&& strcmp(cubo[0][1][0].lateral, "am") != 0){
					fprintf(out, "Li2Di\n");
					giraLinha(cubo, 2, "Di");
					fprintf(out, "Cl0Ci\n");
					giraColuna(cubo, 0, "Ci");
					fprintf(out, "Li2Di\n");
					giraLinha(cubo, 2, "Di");
					fprintf(out, "Cl0Ba\n");
					giraColuna(cubo, 0, "Ba");
					fprintf(out, "Li2Es\n");
					giraLinha(cubo, 2, "Es");
					primeiraCamada(out, cubo);
	
				}
			}
		}
		fprintf(out, "CbDi\n");
		giraCubo(cubo, "Di");
	}
}

void fazerCruzAmarela(FILE *out, bloco ***cubo){
	while(strcmp(cubo[0][0][1].base, "am") != 0 || strcmp(cubo[1][0][2].base, "am") != 0
		||strcmp(cubo[2][0][1].base, "am") != 0 || strcmp(cubo[1][0][0].base, "am") != 0){
	
		if((strcmp(cubo[1][0][0].base, "am") == 0 || strcmp(cubo[1][0][0].base, "am") != 0) 
		 && strcmp(cubo[0][0][1].base, "am") != 0){

			fprintf(out, "FaDi\n");
			giraFace(cubo, "Di");
			fprintf(out, "Li2Es\n");
			giraLinha(cubo, 2, "Es");
			fprintf(out, "Cl2Ci\n");
			giraColuna(cubo, 2, "Ci");
			fprintf(out, "Li2Di\n");
			giraLinha(cubo, 2, "Di");
			fprintf(out, "Cl2Ba\n");
			giraColuna(cubo, 2, "Ba");
			fprintf(out, "FaEs\n");
			giraFace(cubo, "Es");
		}
		fprintf(out, "Li2Di\n");
		giraLinha(cubo, 2, "Di");
	}
}
int quantosCantos(bloco ***cubo){
	register int i;
	int result =0;
	for(i=0; i<4; i++){
		if(strcmp(cubo[0][0][0].base, "am") == 0){
			result++;
		}
		giraLinha(cubo, 2, "Di");
	}
	return result;
}
void algoritmo2Cubo(FILE *out, bloco ***cubo){
	fprintf(out, "Cl2Ci\n");
	giraColuna(cubo, 2, "Ci");
	fprintf(out, "Li2Es\n");
	giraLinha(cubo, 2, "Es");
	fprintf(out, "Cl2Ba\n");
	giraColuna(cubo, 2, "Ba");
	fprintf(out, "Li2Es\n");
	giraLinha(cubo, 2, "Es");
	fprintf(out, "Cl2Ci\n");
	giraColuna(cubo, 2, "Ci");
	fprintf(out, "Li2Es\n");
	giraLinha(cubo, 2, "Es");
	fprintf(out, "Li2Es\n");
	giraLinha(cubo, 2, "Es");
	fprintf(out, "Cl2Ba\n");
	giraColuna(cubo, 2, "Ba");
}

void completarCorAmarela(FILE *out, bloco ***cubo){
	while(strcmp(cubo[0][0][0].base, "am") != 0 || strcmp(cubo[0][0][2].base, "am") != 0
		||strcmp(cubo[2][0][0].base, "am") != 0 || strcmp(cubo[2][0][2].base, "am") != 0){
		int cantos = quantosCantos(cubo);
		if(cantos == 0){
			while(strcmp(cubo[0][0][2].frente, "am") != 0){
				fprintf(out, "Li2Es\n");
				giraLinha(cubo, 2, "Es");
			}
			fprintf(out, "Li2Es\n");
			giraLinha(cubo, 2, "Es");
			algoritmo2Cubo(out, cubo);
		}else if(cantos == 1){
			while(strcmp(cubo[0][0][0].base, "am") != 0){
				fprintf(out, "Li2Es\n");
				giraLinha(cubo, 2, "Es");
			}
			algoritmo2Cubo(out, cubo);
		}else if(cantos == 2){
			while(strcmp(cubo[0][0][0].frente, "am") != 0 ){
				fprintf(out, "Li2Es\n");
				giraLinha(cubo, 2, "Es");
			}
			algoritmo2Cubo(out, cubo);
		}

	}
}
int cantosCorretos(bloco ***cubo){
	register int i;
	int result = 1;
	for(i=0; i<4; i++){
		if(strcmp(cubo[0][1][1].frente, cubo[0][0][0].frente) != 0 || strcmp(cubo[0][1][1].frente, cubo[0][0][2].frente) != 0){
			result = 0;
		}
		giraCubo(cubo, "Di");
	}
	return result;
}

int cantosTodosDiferente(bloco ***cubo){
	register int i;
	int result = 1;
	for(i=0; i<4; i++){
		if(strcmp(cubo[0][0][0].frente, cubo[0][0][2].frente) == 0){
			result = 0;
		}
		giraCubo(cubo, "Di");
	}
	return result;
}

void algoritmoL(FILE *out, bloco ***cubo){
	fprintf(out, "Cl2Ba\n");
	giraColuna(cubo, 2, "Ba");
	fprintf(out, "FaDi\n");
	giraFace(cubo, "Di");
	fprintf(out, "Cl2Ba\n");
	giraColuna(cubo, 2, "Ba");
	fprintf(out, "CbDi\n");
	giraCubo(cubo, "Di");
	fprintf(out, "CbDi\n");
	giraCubo(cubo, "Di");
	fprintf(out, "FaDi\n");
	giraFace(cubo, "Di");
	fprintf(out, "FaDi\n");
	giraFace(cubo, "Di");
	fprintf(out, "CbDi\n");
	giraCubo(cubo, "Di");
	fprintf(out, "CbDi\n");
	giraCubo(cubo, "Di");
	fprintf(out, "Cl2Ci\n");
	giraColuna(cubo, 2, "Ci");
	fprintf(out, "FaEs\n");
	giraFace(cubo, "Es");
	fprintf(out, "Cl2Ba\n");
	giraColuna(cubo, 2, "Ba");
	fprintf(out, "CbDi\n");
	giraCubo(cubo, "Di");
	fprintf(out, "CbDi\n");
	giraCubo(cubo, "Di");
	fprintf(out, "FaDi\n");
	giraFace(cubo, "Di");
	fprintf(out, "FaDi\n");
	giraFace(cubo, "Di");
	fprintf(out, "CbDi\n");
	giraCubo(cubo, "Di");
	fprintf(out, "CbDi\n");
	giraCubo(cubo, "Di");
	fprintf(out, "Cl2Ba\n");
	giraColuna(cubo, 2, "Ba");
	fprintf(out, "Cl2Ba\n");
	giraColuna(cubo, 2, "Ba");
}

void arrumarCantos(FILE *out, bloco ***cubo){
	while(!cantosCorretos(cubo)){
		if(!cantosTodosDiferente(cubo)){
			while(strcmp(cubo[2][0][0].frente, cubo[2][0][2].frente) != 0){
				fprintf(out, "Li2Di\n");
				giraLinha(cubo, 2, "Di");
			}
			algoritmoL(out, cubo);
		}else{
			algoritmoL(out, cubo);
		}
	}
	while(strcmp(cubo[0][0][0].frente, cubo[0][1][1].frente) != 0){
		giraLinha(cubo, 2, "Di");
	}
}


int faceCompleta(bloco ***cubo){
	register int i;
	int result = 0;
	for(i=0; i<4; i++){
		if(strcmp(cubo[0][0][1].frente, cubo[0][1][1].frente) == 0 
		&& strcmp(cubo[0][0][1].frente, cubo[0][0][0].frente) == 0
		&& strcmp(cubo[0][0][1].frente, cubo[0][0][2].frente) == 0){
			result = 1;
		}
		giraCubo(cubo, "Di");
	}

	

	return result;
}

void algoritmoMinerva(FILE *out, bloco ***cubo){
	fprintf(out, "FaDi\n");
	giraFace(cubo, "Di");
	fprintf(out, "FaDi\n");
	giraFace(cubo, "Di");
	if(strcmp(cubo[0][1][1].frente, cubo[1][0][0].lateral) == 0){
		fprintf(out, "Li2Di\n");
		giraLinha(cubo, 2, "Di");
	}else{
		fprintf(out, "Li2Es\n");
		giraLinha(cubo, 2, "Es");
	}
	fprintf(out, "Cl1Ci\n");
	giraColuna(cubo, 1, "Ci");
	fprintf(out, "CbBa\n");
	giraCubo(cubo, "Ba");
	fprintf(out, "FaDi\n");
	giraFace(cubo, "Di");
	fprintf(out, "FaDi\n");
	giraFace(cubo, "Di");
	fprintf(out, "CbCi\n");
	giraCubo(cubo, "Ci");
	fprintf(out, "Cl1Ba\n");
	giraColuna(cubo, 1, "Ba");
	if(strcmp(cubo[1][0][0].base, "br") == 0){
		fprintf(out, "Li2Di\n");
		giraLinha(cubo, 2, "Di");
	}else{
		fprintf(out, "Li2Es\n");
		giraLinha(cubo, 2, "Es");
	}
	fprintf(out, "FaDi\n");
	giraFace(cubo, "Di");
	fprintf(out, "FaDi\n");
	giraFace(cubo, "Di");
}

void ultimoPasso(FILE *out, bloco ***cubo){
	while(strcmp(cubo[0][0][1].frente, cubo[0][1][1].frente) != 0 || strcmp(cubo[1][0][2].lateral, cubo[1][1][2].lateral) != 0
		||strcmp(cubo[1][0][0].lateral, cubo[1][1][0].lateral) != 0 || strcmp(cubo[2][0][1].frente, cubo[2][1][1].frente) != 0){

		if(faceCompleta(cubo)){
			while(strcmp(cubo[2][0][1].frente, cubo[2][1][1].frente) != 0){
				fprintf(out, "CbDi\n");
				giraCubo(cubo,"Di");
			}
			algoritmoMinerva(out, cubo);
		}else{
			algoritmoMinerva(out, cubo);
		}
	}

}

void resolverCubo(bloco ***cubo, FILE *in, FILE *out){
	int id;
	while(fscanf(in, "%d", &id) != EOF){
			printf("%d\n", id);
			fprintf(out, "%d\n", id);
			lerCubo(in, cubo);
			fazerCruz(out, cubo);
			primeiraCamada(out, cubo);
			segundaCamada(out, cubo);
			fazerCruzAmarela(out, cubo);
			completarCorAmarela(out, cubo);
			arrumarCantos(out, cubo);
			ultimoPasso(out, cubo);
			fprintf(out,"\n");
			mostrarCubo1(cubo);
	}
}

void main(){
	bloco *** cubo;
	FILE *in = fopen("cubo.txt", "r");
	FILE *out = fopen("operacoes.txt", "w");
	cubo =  alocaCubo();
	resolverCubo(cubo, in, out);
	fclose(in);
	fclose(out);
	liberaCubo(cubo);
}