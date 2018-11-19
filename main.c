#include <stdio.h>
#include <stdlib.h>
#include "oper.c"

int main(){
	
	FILE *fp;

	fp = fopen("arq/config.txt", "r");
	char grau;
	char pos;
	char txt1[10], txt2[10];
	
	configRead(fp, &grau, &pos, txt1, txt2);

	printf("Grau = %c\nPos = %c\nArq1 = %s\nArq2 = %s", grau, pos, txt1, txt2);


	return 0;
}