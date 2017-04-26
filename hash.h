#ifndef HASH_H_INCLUDED
#define HASH_H_INCLUDED
#include "listaEncadeada.h"
#include <stdio.h>
#include <stdlib.h>
typedef struct{
	int sz;
	ListaEncadeada *itens;
} HashTable;
void initHash(HashTable** t,int M);
void print(HashTable* t);
void printTabela(HashTable* t);
int searchMatricula(HashTable* t, unsigned int matricula);
int searchNome(HashTable* t, Chave nome);
#endif
