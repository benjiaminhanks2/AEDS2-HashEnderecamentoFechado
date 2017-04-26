#ifndef CLOSEDADRESSINGHASH_H_INCLUDED
#define CLOSEDADRESSINGHASH_H_INCLUDED
#include "hash.h"
#include <string.h>
typedef struct{ 
	HashTable *table;
	unsigned int *pesos;
} ClosedAdressingHashTable;
void initClosedAdressingHash(ClosedAdressingHashTable** t,int M);
void addItem(ClosedAdressingHashTable *t, Item i);
void antiColisoes(ListaEncadeada *i,Item item);
unsigned int peso(unsigned int i, ClosedAdressingHashTable *t);
#endif
