#include <stdio.h>
#include <stdlib.h>
#include "structures.h"
#include "oper.h"

//arquivo f deve estar aberto já
boolean configRead(FILE *fp, char *grau, char *pos, char *txt1, char *txt2){
	int i = 0;
	if (fp != NULL){
		fscanf(fp, "%c", grau);
		fseek(fp, 1, SEEK_CUR);
		fscanf(fp, "%c", pos);
		fscanf(fp, "%s", txt1);
		fscanf(fp, "%s", txt2);
		return TRUE;
	} else return FALSE;
	
}

int text1Read(FILE *fp, arvoreB arv[]){ // coloca o arquivo de texto1 na struct
	int aux, i = 0, j = 0;
	if (fp == NULL) printf("ERRO AO LER ARQUIVO!!\n");
	else{
		do{
			arvoreB novoNo;
			//lendo primeiro a estrutura da arvore B+
			fscanf(fp, "%d %d", novoNo.numChaves, aux);
			if (aux == 1) novoNo.isFolha = TRUE;
			else novoNo.isFolha = FALSE;
			//lendo as chaves
			for(; i < MAX_CHAVES; i++)
				fscanf(fp, "%d", novoNo.chaves[i]);
			//lendo os filhos / indices
			for(i = 0; i < MAX_FILHOS; i++)
				fscanf(fp, "%d", novoNo.filhos[i]);

			// fseek(fp, 1, SEEK_CUR);
			// fscanf(fp, "%d", aux);
			// if (aux == 0) arv->isFolha = FALSE;
			// else arv->isFolha = TRUE;
			// for (int i = 0; i < ; ++i){
			// 	/* code */
			// }
			arv[j] = novoNo;
			j++;
		}while(!feof(fp));
		return 1;
	}
	return 0;
}