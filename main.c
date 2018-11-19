#include <stdio.h>
#include <stdlib.h>
#include "oper.c"

int main(){
	
	FILE *fp, *fp2;

	fp = fopen("arq/config.txt", "r");
	fp2 = fopen("arq/texto1.txt", "r");
	int i = 0, j = 0;
	char grau;
	char pos;
	char txt1[10], txt2[10];
	arvoreB arv[8];
	configRead(fp, &grau, &pos, txt1, txt2);

	//iniciando arvore;
	for (; i < 8; ++i){
		arv[i].isFolha = FALSE;
		arv[i].numChaves = 0;
		for(; j < MAX_CHAVES; j++)
			arv[i].chaves[j] = 0;
		for(j = 0; j < MAX_FILHOS; j++)
			arv[i].filhos[j] = 0;
	}

	text1Read(fp2, arv);
	printf("%d %d %d\n", arv[0].numChaves, arv[0].chaves[0], arv[0].filhos[0]);
	printf("Grau = %c\nPos = %c\nArq1 = %s\nArq2 = %s", grau, pos, txt1, txt2);


	return 0;
}