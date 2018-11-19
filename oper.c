#include <stdio.h>
#include <stdlib.h>
#include "structures.h"

//arquivo f deve estar aberto já
int configRead(FILE *fp, char grau, char pos, char *txt1, char *txt2){
	int i = 0;
	grau = fgetc(fp);
	fseek(fp, 1, SEEK_CUR);
	pos = fgetc(fp);
	fscanf(fp, "%s", txt1);
	fscanf(fp, "%s", txt2);
}