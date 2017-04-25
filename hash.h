#ifndef HASH_H_INCLUDED
#define HASH_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
typedef char * Chave;
typedef struct _Item{
	struct _Item *prox;
	Chave val;
} Item;
typedef struct{
	int sz;
	Item *itens;
} Table;
void add(Table *t, Chave *c, int tam);
void transf(Table *t, Chave c);
void antiColisoes(Item *i,Chave c);
int peso(int i);
int calcM(int n);
void initHash(Table *t,int M);
void print(Table *t);
#endif
