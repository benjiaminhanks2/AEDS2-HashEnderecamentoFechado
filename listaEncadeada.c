#include "listaEncadeada.h"
void initListaEncadeada(ListaEncadeada **lista, int M){
	*lista = (ListaEncadeada*) malloc(sizeof(ListaEncadeada) * M);
}

void ListaEncadeada_Insere(ListaEncadeada **lista, Item item){
	if((*lista) == NULL){
		*lista = (ListaEncadeada *)malloc(sizeof(ListaEncadeada));
		(*lista)->prox = NULL;
		(*lista)->dados = item;
	}
	else ListaEncadeada_Insere(&(*lista)->prox,item);
}
