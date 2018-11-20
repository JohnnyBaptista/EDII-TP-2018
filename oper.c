#include <stdio.h>
#include <stdlib.h>
#include "structures.h"
#include "oper.h"


void  printStruct(arvoreB *arv[]){
	int i = 0, j = 0;
	for (i = 0; i < 8; ++i){
		printf("%d ", arv[i]->numChaves);
		printf("%d ", arv[i]->isFolha);
		for (j = 0; j < 7; ++j){
			printf("%d ", arv[i]->chaves[j]);
		}
		for (j = 0; j < 8; j++){
			printf("%d ", arv[i]->filhos[j]);
		}
		printf("\n");
	}
}

void  printStruct2(DADOS *cidades[]){
	int i = 0, j = 0;
	for (i = 0; i < 24; ++i){
		printf("%d  %s  %d  %s  %f\n\n", cidades[i]->id, cidades[i]->UF, cidades[i]->cod, cidades[i]->nome, cidades[i]->area);
	}
}


//arquivo fp deve estar aberto já
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

boolean text1Read(FILE *fp, arvoreB *arv[]){ // coloca o arquivo de texto1 na struct
	int j = 0;
	if (fp == NULL) printf("ERRO AO LER ARQUIVO!!\n");
	else{
		do{
			arvoreB *novoNo = (arvoreB *) malloc(sizeof(arvoreB));
			fscanf(fp, "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n", 
												&novoNo->numChaves, 
												&novoNo->isFolha, 
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
		
			arv[j] = novoNo;
			j++;
		}while(!feof(fp));
		fclose(fp);
		return TRUE;
	}
	return FALSE;
}

boolean text2Read(FILE *fp, DADOS *cidades[]){
	int j = 0, i = 0;
	char c;
	if (fp == NULL) printf("ERRO AO LER ARQUIVO!!\n");
	else{
		do{
			DADOS *novoNo = (DADOS *) malloc(sizeof(DADOS));
			fscanf(fp, "%d %s %d %s %f\n", 
							&novoNo->id,
							&novoNo->UF,
							&novoNo->cod,
							&novoNo->nome,
							&novoNo->area);
			cidades[j] = novoNo;
			j++;
		} while (!feof(fp));
		fclose(fp);
		return TRUE;
	}
	return FALSE;
}

//arquivo binário deve estar aberto
boolean binary1Create(arvoreB **arv, FILE *fb){
	int i;
	if (fb != NULL){
		fwrite(arv, sizeof(arvoreB), 1, fb);
		fclose(fb);
		return TRUE;
	}
	return FALSE;
}

boolean binary2Create(DADOS *cidades[], FILE *fb){
	if (fb != NULL){
		fwrite(cidades, sizeof(DADOS), 1, fb);
		fclose(fb);
		return TRUE;
	}
	return FALSE;
}

boolean binaryRead(FILE *fb, arvoreB **arv){
    if (fb != NULL) {
        fread(arv, sizeof(arvoreB), 1, fb);
        fclose(fb);
        printStruct(arv);
        return TRUE;
    }
    return FALSE;
}

boolean binaryRead2(FILE *fb, DADOS **cidades){
    if (fb != NULL) {
        fread(cidades, sizeof(DADOS), 1, fb);
        fclose(fb);
        printStruct2(cidades);
        return TRUE;
    }
    return FALSE;
}


