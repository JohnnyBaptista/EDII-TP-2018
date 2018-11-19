#include <stdio.h>
#include <stdlib.h>
#include "oper.c"

int main(){
	
	FILE *fp, *fp2, *fb1;
	int i = 0, j = 0;
	char grau;
	char pos;
	char txt1[10], txt2[10];
	arvoreB *arv[8]; // 8 = grau máximo da árvore
	arvoreB *arv2[8]; // 8 = grau máximo da árvore; auxiliar
	//==========================================================||==========================================================\\

	fp = fopen("arq/config.txt", "r");
	configRead(fp, &grau, &pos, txt1, txt2);
	printf("%d\n", pos);
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

	fp2 = fopen(txt1, "r");
	fb1 = fopen("arq/binary1.txt", "wb+");
	text1Read(fp2, arv);
	/*//printStruct(arv);
	binary1Create(arv, fb1);
	// printf("%d\n", test);
	fb1 = fopen("arq/binary1.txt", "rb");
	int test = binaryRead(fb1, arv2);	*/
	// printf("%d\n", test);
	return 0;
}