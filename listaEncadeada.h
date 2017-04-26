#ifndef LISTAENCADEADA_H_INCLUDED
#define LISTAENCADEADA_H_INCLUDED
#include <stdlib.h>
// Renomeamos o tipo vetor de chars para tornar mais intuitivo o uso deste
typedef char * Chave;
//Estrutura responsável por armazenar informações usadas em nossa implementação
typedef struct{
	unsigned int matricula;
	Chave nome;
} Item;
//Estrutura da Lista encadeada
typedef struct _ListaEncadeada{
	struct _ListaEncadeada *prox;
	Item dados;
} ListaEncadeada;
// Funcao inicializadora da estrutura
void initListaEncadeada(ListaEncadeada **lista, int M);
// Funcao de adicao de itens na lista
void ListaEncadeada_Insere(ListaEncadeada **lista, Item item);
#endif
