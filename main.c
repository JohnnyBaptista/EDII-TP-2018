#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "oper.c"

int main(){
	
	setlocale(LC_ALL, "Portuguese");
	FILE *fp, *fp1, *fp2;
	FILE *fb1, *fb2, *fb3; //binario
	int i = 0, j = 0, res;
	char grau;
	char pos;
	char txt1[14], txt2[14];
	boolean test = FALSE;
	DADOS *cidades[24];
	DADOS *cidades2[24];
	arvoreB *arv[8]; // 8 = grau máximo da árvore
	arvoreB *arv2[8]; // 8 = grau máximo da árvore; auxiliar
	//==========================================================||==========================================================\\
	
	fp = fopen("arq/config.txt", "r");
	configRead(fp, &grau, &pos, txt1, txt2);
	printf("SELECIONE UMA DAS OPÇÕES:\n1-Criar arquivo Binário 1\n2-Criar Arquivo Binário 2\n");
	scanf("%d", &res);
	printf("Leitura do arquivo de configuração:\nGrau = %c\nPos = %c\nArq1 = %s\nArq2 = %s\n", grau, pos, txt1, txt2);
	system("pause");
	switch(res){
		case 1:
			system("cls"); 
			fp1 = fopen("arq/texto1.txt", "r");
			text1Read(fp1, arv);
			fp1 = fopen("arq/binary1.txt", "wb+");
			test = binary1Create(arv, fp1);
			if (test == TRUE)
				printf("Criação do arquivo feito com sucesso!\n");
			system("pause");
			system("cls");
			printf("Deseja imprimir o arquivo binário? Sim = 1, Não = 0\n");
			scanf("%d", &res);
			if (res == 1){
				fp1 = fopen("arq/binary1.txt", "rb");
				binaryRead(fp1, arv2);
			}
			break;
		case 2:
			system("cls"); 
			fb1 = fopen("arq/texto1.txt", "r");
			text2Read(fb1, cidades);
			fb1 = fopen("arq/binary2.txt", "wb+");
			test = binary2Create(cidades, fb1);
			if (test == TRUE)
				printf("Criação do arquivo feito com sucesso!\n");
			system("pause");
			system("cls");
			printf("Deseja imprimir o arquivo binário? Sim = 1, Não = 0\n");
			scanf("%d", &res);
			if (res == 1){
				fp1 = fopen("arq/binary2.txt", "rb");
				binaryRead2(fp1, cidades2);
			}
		default:
			system("cls"); 
			main();
			break;
	}
	system("cls");
	
	if (res == 1)
	{
		printf("Qual deseja imprimir:\n1 - Arquivo binário 1\n2 - Arquivo binário 2\n");
		scanf("%d", &res);
		switch(res){
			case 1:
				
				break;
			case 2:
				fp1 = fopen("arq/binary2.txt", "rb");
				binaryRead2(fp1, cidades2);
				break;
			default: break;
		}
	}

	return 0;
}