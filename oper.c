#include <stdio.h>
#include <stdlib.h>
#include "structures.h"
#include "oper.h"


void  printStruct(arvoreB *arv[]){
	int i = 0, j = 0;
	for (i = 0; i < 8; ++i){
		printf("%d ", arv[i]->numChaves);
		for (j = 0; j < 7; ++j){
			printf("%d ", arv[i]->chaves[j]);
		}
		for (j = 0; j < 8; j++){
			printf("%d ", arv[i]->filhos[j]);
		}
		printf("\n");
	}
}


//arquivo fp deve estar aberto já
boolean configRead(FILE *fp, char *grau, char *pos, char *txt1, char *txt2){
	int i = 0;
	if (fp != NULL){
		fseek(fp, 0, SEEK_SET);
		fscanf(fp, "%c", grau);
		fseek(fp, 1, SEEK_CUR);
		fscanf(fp, "%c", pos);
		fscanf(fp, "%s", txt1);
		fscanf(fp, "%s", txt2);
		return TRUE;
	} else return FALSE;
	
}

int text1Read(FILE *fp, arvoreB *arv[]){ // coloca o arquivo de texto1 na struct
	int aux, i = 0, j = 0;
	if (fp == NULL) printf("ERRO AO LER ARQUIVO!!\n");
	else{
		do{
			arvoreB *novoNo = (arvoreB *) malloc(sizeof(arvoreB));
			//lendo primeiro a estrutura da arvore B+
			fscanf(fp, "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n", 
												&novoNo->numChaves, 
												&aux, 
												&novoNo->chaves[0],
												&novoNo->chaves[1],
												&novoNo->chaves[2],
												&novoNo->chaves[3],
												&novoNo->chaves[4],
												&novoNo->chaves[5],
												&novoNo->chaves[6],
												&novoNo->filhos[0],
												&novoNo->filhos[1],
												&novoNo->filhos[2],
												&novoNo->filhos[3],
												&novoNo->filhos[4],
												&novoNo->filhos[5],
												&novoNo->filhos[6],
												&novoNo->filhos[7]);
			if (aux == 1) novoNo->isFolha = TRUE;
			else novoNo->isFolha = FALSE;
			//lendo as chaves

		
			arv[j] = novoNo;
			j++;
		}while(!feof(fp));
		fclose(fp);
		return 1;
	}
	return 0;
}

//arquivo binário deve estar aberto
int binary1Create(arvoreB **arv, FILE *fb){
	int i;
	if (fb != NULL){
		fwrite(arv, sizeof(arv), sizeof(arv), fb);
		fclose(fb);
		return 1;
	}
	return 0;
}

int binaryRead(FILE *fb, arvoreB **arv){
    if (fb != NULL) {
    	fseek(fb, 0, SEEK_SET);
        fread(arv, sizeof(int), sizeof(arv), fb);
        fclose(fb);
        printStruct(arv);
        return 1;
    }
    return 0;
}


