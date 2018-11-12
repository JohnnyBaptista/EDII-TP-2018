
#ifndef _STRUCTURES_H
#define _STRUCTURES_H

#define T          2
#define MAX_CHAVES 3 
#define MAX_FILHOS 4
#define MIN_OCUP   1

typedef no_arvoreB arvoreB;
	
struct no_arvoreB {
   int num_chaves, folha; //Quantidades de chaves contida no nó, folha = 1, não folha = 0
   int chaves[MAX_CHAVES]; //Chaves armazenadas no nó
   arvoreB *filhos[MAX_FILHOS]; //Ponteiro para os filhos
   arvoreB *pai
   arvoreB *prox;
   arvoreB *ult;
};

#endif