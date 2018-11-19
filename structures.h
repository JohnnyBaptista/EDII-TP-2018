

// #define true 	   1
// #define false 	   0

#define MAX_CHAVES 7 
#define MAX_FILHOS 8
#define MIN_OCUP   3


//===================================== STRUCTURES =======
#ifndef _STRUCTURES_H
#define _STRUCTURES_H
typedef enum boolean{TRUE, FALSE}boolean;

typedef struct no_arvoreB {
   boolean isFolha; //folha = TRUE, não folha = FALSE
   int numChaves; // Quantidades de chaves contida no nó
   int chaves[MAX_CHAVES]; //Chaves armazenadas no nó, id dos munícipios
   int filhos[MAX_FILHOS]; //Ponteiro para os filhos
}arvoreB; // no folha

typedef struct dados{
  	int id;
  	int cod;
  	float area;
  	char UF[2];
  	char nome[120];
}DADOS;

#endif