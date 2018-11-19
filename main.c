#include <stdio.h>
#include <stdlib.h>
#include "oper.c"

int main(){
	
	FILE *fp, *fp2, *fp3; //texto 
	FILE *fb1, *fb2, *fb3; //binario
	int i = 0, j = 0;
	char grau;
	char pos;
	char txt1[10], txt2[10];
	DADOS *cidades[24];
	DADOS *cidades2[24];
	arvoreB *arv[8]; // 8 = grau máximo da árvore
	arvoreB *arv2[8]; // 8 = grau máximo da árvore; auxiliar
	//==========================================================||==========================================================\\

	fp = fopen("arq/config.txt", "r");
	configRead(fp, &grau, &pos, txt1, txt2);
	fp2 = fopen("arq/texto1.txt", "r");
	fp3 = fopen("arq/texto2.txt", "r");
	//iniciando arvore;
	/*for (; i < 8; ++i){
		arv[i]->isFolha = FALSE;
		arv[i]->numChaves = 0;
		for(; j < MAX_CHAVES; j++)
			arv[i]->chaves[j] = 0;
		for(j = 0; j < MAX_FILHOS; j++)
			arv[i]->filhos[j] = 0;
	}*/

	
	printf("Grau = %c\nPos = %c\nArq1 = %s\nArq2 = %s\n", grau, pos, txt1, txt2);


	// text1Read(fp2, arv);
	text2Read(fp3, cidades);
	// printStruct2(cidades);
	fb2 = fopen("arq/binary2.txt", "wb+");
	boolean test = binary2Create(cidades, fb2);
	fflush(fb2);
	fb2 = fopen("arq/binary2.txt","rb");
	binaryRead2(fb2, cidades2);


	// printStruct(arv);
	// printf("IMPRIMINDO ARQUIVO BINARIO\n=================\n\n");
	// fb1 = fopen("arq/binary1.txt", "wb+");
	// binary1Create(arv, fb1);
	/*//
	// printf("%d\n", test);
	*/
	// fflush(fb1);
	// fb1 = fopen("arq/binary1.txt", "rb");
	// int test = binaryRead(fb1, arv2);	
	// printf("%d\n", test);
	return 0;
}