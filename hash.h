#ifndef HASH_H_INCLUDED
#define HASH_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
typedef struct{
	unsigned int matricula;
} Info;
typedef char * Chave;
typedef struct _Item{
	struct _Item *prox;
	Chave val;
	Info dados;
} Item;
typedef struct{
	int sz;
	Item *itens;
	unsigned int *pesos;
} Table;
void addi(Table *t, Item i);
void add(Table *t, Chave *c, int tam);
void transf(Table *t, Chave c);
void antiColisoes(Item *i,Chave c);
void antiColisoesi(Item *i,Item item);
unsigned int peso(unsigned int i, Table *t);
int calcM(int n);
void initHash(Table **t,int M);
void print(Table *t);
#endif
