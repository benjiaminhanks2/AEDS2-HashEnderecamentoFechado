#include "listaEncadeada.h"
void initListaEncadeada(ListaEncadeada **lista, int M){
	*lista = (ListaEncadeada*) malloc(sizeof(ListaEncadeada) * M);
}

void ListaEncadeada_Insere(ListaEncadeada **lista, Item item){
	*lista = (ListaEncadeada *)malloc(sizeof(ListaEncadeada));
	(*lista)->prox = NULL;
	(*lista)->dados = item;
}
