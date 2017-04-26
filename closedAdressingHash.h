#ifndef CLOSEDADRESSINGHASH_H_INCLUDED
#define CLOSEDADRESSINGHASH_H_INCLUDED
#include "hash.h"
#include <string.h>
/*Estrutura Tabela hash de endereçamento fechado
 *Armazena uma tabela hash e um vetor de pesos(no qual o primeiro indice possui como valor o numero de pesos armazenados no vetor)
 * */
typedef struct{ 
	HashTable *table;
	unsigned int *pesos;
} ClosedAdressingHashTable;
// Funcao inicializadora da estrutura
void initClosedAdressingHash(ClosedAdressingHashTable** t,int M);
// Funcao de adicao de itens
void addItem(ClosedAdressingHashTable *t, Item i);
// Funcao responsavel por gerar peso aleatoriamente e armazenar no vetor de pesos
unsigned int peso(unsigned int i, ClosedAdressingHashTable *t);
#endif
