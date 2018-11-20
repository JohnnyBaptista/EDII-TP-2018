#ifndef _OPER_H_
#define _OPER_H_

void printStruct(arvoreB *arv[]);
boolean configRead(FILE *fp, char *grau, char *pos, char *txt1, char *txt2);
boolean text1Read(FILE *fp, arvoreB *arv[]);
boolean binary1Create(arvoreB **arv, FILE *fb);
boolean binaryRead(FILE *fb, arvoreB **arv);
boolean text2Read(FILE *fp, DADOS *cidades[]);
boolean binary2Create(DADOS *cidades[], FILE *fp);
boolean binaryRead2(FILE *fb, DADOS **cidades);

#endif