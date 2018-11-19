#ifndef _OPER_H_
#define _OPER_H_

void printStruct(arvoreB *arv[]);
boolean configRead(FILE *fp, char *grau, char *pos, char *txt1, char *txt2);
int text1Read(FILE *fp, arvoreB *arv[]);
int binary1Create(arvoreB **arv, FILE *fb);
int binaryRead(FILE *fb, arvoreB **arv);

#endif