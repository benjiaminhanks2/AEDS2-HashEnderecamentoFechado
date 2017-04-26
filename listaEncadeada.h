#ifndef LISTAENCADEADA_H_INCLUDED
#define LISTAENCADEADA_H_INCLUDED
#include <stdlib.h>
typedef char * Chave;
typedef struct{
	unsigned int matricula;
	Chave nome;
} Item;
typedef struct _ListaEncadeada{
	struct _ListaEncadeada *prox;
	Item dados;
} ListaEncadeada;
void initListaEncadeada(ListaEncadeada **lista, int M);
#endif
