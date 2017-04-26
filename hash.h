#ifndef HASH_H_INCLUDED
#define HASH_H_INCLUDED
#include "listaEncadeada.h"
#include <stdio.h>
#include <stdlib.h>
//Estrutura da tabela Hash, sem encadeamento
typedef struct{
	int sz;
	ListaEncadeada *itens;
} HashTable;
// Funcao inicializadora da estrutura
void initHash(HashTable** t,int M);
// Funcao que imprime os nomes dos itens inseridos na tabela
void print(HashTable* t);
// Funcao que imprime a tabela exatamente como ela é, ou seja, mantendo campos que estão vazios
void printTabela(HashTable* t);
// Funcao de busca por Item pela Matricula
int searchMatricula(HashTable* t, unsigned int matricula);
// Funcao de busca por Item pelo Nome
int searchNome(HashTable* t, Chave nome);
#endif
